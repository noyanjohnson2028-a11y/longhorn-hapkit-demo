/*
MIT License

Copyright (c) 2026 Ross Neuman

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

Custom demo adaptation of https://github.com/rneum/RobotCamp2026
*/
#define ENCODER_OPTIMIZE_INTERRUPTS
#include <Encoder.h>

const int MOTOR_IN1 = 5;
const int MOTOR_IN2 = 4;
const int MOTOR_PWM = 9;

Encoder encoder(3, 2);

const float COUNTS_PER_REV = 48.0;
const float HANDLE_RADIUS = 8.5;
const float MOTOR_RADIUS = 0.5;
const float SECTOR_RADIUS = 7.5;

const float FILTER_FREQUENCY = 20.0;
const unsigned long CONTROL_INTERVAL_US = 1000;

char mode = '0';

float position = 0;
float previousPosition = 0;
float velocity = 0;

float massPosition = 0.5;
float massVelocity = 0;
const float MASS_INITIAL_POSITION = 0.5;

int previousWallSide = 0;
float impactTime = 0;
float impactAmplitude = 0;

unsigned long lastControl = 0;
unsigned long lastPrint = 0;
int outputPWM = 0;

void setMotor(int command) {
  command = constrain(command, -400, 400);

  OCR1A = 0;

  if (command >= 0) {
    digitalWrite(MOTOR_IN1, HIGH);
    digitalWrite(MOTOR_IN2, LOW);
  } else {
    digitalWrite(MOTOR_IN1, LOW);
    digitalWrite(MOTOR_IN2, HIGH);
  }

  OCR1A = abs(command);
}

void resetState() {
  setMotor(0);
  outputPWM = 0;
  encoder.write(0);

  position = 0;
  previousPosition = 0;
  velocity = 0;

  massPosition = MASS_INITIAL_POSITION;
  massVelocity = 0;

  previousWallSide = 0;
  impactTime = 0;
  impactAmplitude = 0;

  lastControl = micros();
}

void setup() {
  pinMode(MOTOR_IN1, OUTPUT);
  pinMode(MOTOR_IN2, OUTPUT);
  pinMode(MOTOR_PWM, OUTPUT);

  digitalWrite(MOTOR_IN1, LOW);
  digitalWrite(MOTOR_IN2, LOW);
  digitalWrite(MOTOR_PWM, LOW);

  // Timer1: phase/frequency-correct PWM at 20 kHz.
  // Pin 9 is required.
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1 = 0;
  ICR1 = 400;
  OCR1A = 0;
  TCCR1A = (1 << COM1A1);
  TCCR1B = (1 << WGM13) | (1 << CS10);

  Serial.begin(115200);
  resetState();

  Serial.println("Longhorn Hapkit ready");
  Serial.println("0: Stop/reset");
  Serial.println("1: Spring");
  Serial.println("2: Wall");
  Serial.println("3: Wall with damping");
  Serial.println("4: Damper");
  Serial.println("5: Nonlinear friction");
  Serial.println("6: Bump");
  Serial.println("7: Improved bump");
  Serial.println("8: Bump and valley");
  Serial.println("9: Two walls with impact");
  Serial.println("A: Damped centering spring");
}

void readCommands() {
  while (Serial.available() > 0) {
    char incoming = Serial.read();

    if (incoming == 'a') {
      incoming = 'A';
    }

    if ((incoming >= '0' && incoming <= '9') ||
        incoming == 'A') {
      setMotor(0);
      outputPWM = 0;
      mode = incoming;

      previousWallSide = 0;
      impactTime = 0;
      impactAmplitude = 0;

      if (mode == '0') {
        resetState();
      }
    }
  }
}

// Positive position is physically left on the demonstrated build.
float bumpForce(float x, float center, float halfWidth, float strength) {
  float distance = x - center;
  if (fabs(distance) >= halfWidth) return 0;
  return strength * sin(PI * distance / halfWidth);
}
float valleyForce(float x, float center, float halfWidth, float strength) {
  return -bumpForce(x, center, halfWidth, strength);
}

void updateHaptics(float dt) {
  long counts = encoder.read();

  float motorAngle =
      (counts / COUNTS_PER_REV) * 2.0 * PI;

  position =
      HANDLE_RADIUS * MOTOR_RADIUS *
      motorAngle / SECTOR_RADIUS;

  float filter =
      exp(-2.0 * PI * FILTER_FREQUENCY * dt);

  velocity =
      filter * velocity +
      (1.0 - filter) *
      (position - previousPosition) / dt;

  previousPosition = position;

  float command = 0;

  switch (mode) {
    case '0': {
      command = 0;
      break;
    }

    case '1': {
      const float stiffness = 80.0;
      command = -stiffness * position;
      break;
    }

    case '2': {
      const float wallPosition = 2.0;
      const float stiffness = 200.0;

      if (position > wallPosition) {
        command = -stiffness * (position - wallPosition);
      }
      break;
    }

    case '3': {
      const float wallPosition = 2.0;
      const float stiffness = 200.0;
      const float damping = 5.0;

      if (position > wallPosition) {
        command =
            -stiffness * (position - wallPosition)
            - damping * velocity;
      }
      break;
    }

    case '4': {
      const float damping = 8.0;
      command = -damping * velocity;
      break;
    }

    case '5': {
      command = -140.0 * constrain(velocity / 0.5, -1.0, 1.0);
      break;
    }

    case '6': {
      command = bumpForce(position, 1.5, 1.0, 220.0);
      break;
    }

    case '7': {
      float distance = position - 1.5;
      float magnitude = fabs(distance);
      if (magnitude < 1.0) {
        float rampIn = magnitude / 0.20;
        float rampOut = (1.0 - magnitude) / 0.25;
        float envelope = min(1.0f, min(rampIn, rampOut));
        command = (distance >= 0 ? 280.0 : -280.0) * envelope;
      }
      break;
    }

    case '8': {
      command = bumpForce(position, 1.5, 1.0, 250.0)
              + valleyForce(position, -1.5, 1.0, 250.0);
      if (fabs(position + 1.5) < 1.0) command -= 2.0 * velocity;
      break;
    }

    case '9': {
      int wallSide = 0;
      if (position > 2.0) wallSide = 1;
      if (position < -2.0) wallSide = -1;
      if (wallSide != 0) {
        if (wallSide != previousWallSide) {
          impactTime = 0;
          impactAmplitude = constrain(10.0 * fabs(velocity), 0.0, 80.0);
        }
        float penetration = fabs(position) - 2.0;
        float impact = impactAmplitude * exp(-30.0 * impactTime)
                     * sin(2.0 * PI * 60.0 * impactTime);
        command = -wallSide * 250.0 * penetration
                - 3.0 * velocity - wallSide * impact;
        impactTime += dt;
      } else {
        impactTime = 0;
        impactAmplitude = 0;
      }
      previousWallSide = wallSide;
      break;
    }

    case 'A': {
      // Custom damped centering spring, not the camp mass simulation.
      command = -100.0 * position - 2.0 * velocity;
      break;
    }

    default: {
      command = 0;
      break;
    }
  }

  outputPWM = (int)constrain(command, -400.0, 400.0);
  setMotor(outputPWM);
}

void loop() {
  readCommands();

  unsigned long now = micros();
  unsigned long elapsed = now - lastControl;

  if (elapsed >= CONTROL_INTERVAL_US) {
    lastControl = now;

    // Stop if a long pause interrupts control.
    if (elapsed > 20000UL) {
      mode = '0';
      resetState();
    } else {
      float dt = elapsed * 0.000001f;
      updateHaptics(dt);
    }
  }

  // Only print when enough buffer space is available.
  if (millis() - lastPrint >= 100 &&
      Serial.availableForWrite() >= 60) {
    lastPrint = millis();

    Serial.print("mode=");
    Serial.print(mode);
    Serial.print(" x_cm=");
    Serial.print(position, 3);
    Serial.print(" PWM=");
    Serial.println(outputPWM);
  }
}