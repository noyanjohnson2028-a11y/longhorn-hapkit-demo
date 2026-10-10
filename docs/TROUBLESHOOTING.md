# Troubleshooting

[Home](../README.md) · [Setup](SETUP.md) · [Calibration](CALIBRATION.md)

### Troubleshooting

- **`Encoder.h: No such file or directory`:** install Encoder by Paul Stoffregen in Library Manager.
- **No board port:** try another data cable or USB port. Disconnect and reconnect the board to identify the correct port. See [Arduino's board-detection guide](https://support.arduino.cc/hc/en-us/articles/4412955149586-If-your-board-is-not-detected-by-Arduino-IDE). Some compatible boards need a driver for their specific USB-serial chip; use the board manufacturer's instructions.
- **Upload fails:** confirm Arduino Uno and the correct port are selected, and close other programs using that port.
- **Unreadable output:** set Serial Monitor to 115200 baud.
- **Wall does nothing:** check the printed position. Modes 2 and 3 activate only above +2 cm; on the demonstrated build that is left of zero.
- **Position never changes:** check encoder connections and power using the camp guide.
- **PWM changes but no force:** check the separate motor supply, motor driver connections, PWM pin 9, and mechanical transmission.
- **Spring pushes away from center:** stop motor output and check motor/encoder direction before increasing strength.

Reference instructions: [install Arduino IDE](https://support.arduino.cc/hc/en-us/articles/360019833020-Download-and-install-Arduino-IDE), [select board and port](https://support.arduino.cc/hc/en-us/articles/4406856349970-Select-board-and-port-in-Arduino-IDE), and [upload a sketch](https://support.arduino.cc/hc/en-us/articles/4733418441116-Upload-a-sketch-in-Arduino-IDE).


## What to include when asking for help

Provide board model, operating system, selected board/port, motor supply rating, wiring changes, mode used, and Serial Monitor lines from both sides of zero. For compilation/upload errors, include the full error text. A wiring photo helps distinguish direction, power, and encoder problems.

A useful report looks like:

```text
Board: Uno R3
OS: macOS / Windows
Mode: 1
Left: mode=1 x_cm=2.745 PWM=-219
Right: mode=1 x_cm=-3.709 PWM=296
Observed: pulls toward center / pushes away / no force
Motor supply: voltage and current rating
```

If output unexpectedly returns to mode 0, check USB reconnects, board resets, supply disturbances, or added blocking code triggering the control-gap stop. The current firmware does not print a specific reason for a reset.
