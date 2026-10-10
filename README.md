# Longhorn Hapkit demo

Build resources and Arduino firmware for my YouTube series about a Longhorn Hapkit I assembled at a robotics camp at The University of Texas at Austin. The first video is an overview and demonstration; follow-up videos will cover the parts, assembly, wiring, and programming.

## Start here

- **[Parts list and purchase links](PARTS.md)**
- **[Demo Arduino sketch](firmware/HapkitDemo/HapkitDemo.ino)**
- [Original camp project, lab guides, and design files](https://github.com/rneum/RobotCamp2026)
- [3D-print files](https://github.com/rneum/RobotCamp2026/tree/main/Hapkit%20Parts/1DOF%20STL)

## What it does

An encoder measures movement, an Arduino calculates a response, and a motor applies force to the handle. The same mechanism can simulate springs, walls, damping, friction, bumps, and a valley.

## Upload and run

1. Use an **Arduino Uno R3 / ATmega328P, 16 MHz**. The firmware directly configures Timer1 and requires motor PWM on pin 9.
2. Install **Encoder by Paul Stoffregen** in Arduino IDE Library Manager.
3. Download this repository, then open `firmware/HapkitDemo/HapkitDemo.ino`.
4. Select Arduino Uno and the correct port, verify, and upload.
5. Connect the motor supply using the camp's power-wiring instructions. The motor connects through the driver, not directly to Arduino pins.
6. Open Serial Monitor at **115200 baud**. Center the handle and send `0` to establish zero.
7. Send a mode from the table below. Send `0` to stop and reset between demos.

The parser ignores line endings and accepts either `A` or `a`.

## Signal pins

| Signal | Uno R3 pin |
|---|---|
| Motor driver IN1 | 5 |
| Motor driver IN2 | 4 |
| Motor driver PWM | 9 |
| Encoder channel passed first to Encoder | 3 |
| Encoder channel passed second to Encoder | 2 |

This table covers control signals. Follow the original guides for encoder power, common ground, motor supply, driver jumpers, and mechanical assembly.

## Demo modes

| Command | Effect |
|---|---|
| `0` | Stop motor output and zero current position |
| `1` | Spring toward the zero position |
| `2` | One wall at +2 cm |
| `3` | Wall at +2 cm with damping |
| `4` | Damper: resistance increases with movement speed |
| `5` | Friction: resistance opposes movement |
| `6` | Smooth bump centered at +1.5 cm |
| `7` | Stronger bump centered at +1.5 cm |
| `8` | Bump at +1.5 cm and valley at -1.5 cm |
| `9` | Walls at +/-2 cm with a brief impact effect |
| `A` | Damped spring toward the zero position |

On my demonstrated build, positive position is physically left. A bump repels from its peak; a valley attracts toward its bottom. Modes 4 and 5 do not return to center. The printed position uses the camp geometry and encoder resolution; it is a calculated displacement, not an independently calibrated measurement.

## Changes from the camp examples

This demo uses 20 kHz PWM, a timed foreground control loop, one-time zeroing, serial diagnostics, stronger/wider bumps, and two walls. **Mode A is a custom damped centering spring, replacing the camp's separate mass-spring-damper simulation.** This preserves the behavior used in my demo rather than claiming to be an unchanged camp sketch.

The effects were reported working on my assembled Uno R3 build. They have not been verified on every hardware variant. If the centering spring pushes away from zero, stop and check motor/encoder direction before tuning force. Disconnect motor power if motion is unexpected, and avoid holding the motor stalled against a wall.

## Credit and license

Original Longhorn Hapkit camp materials and example firmware: [Ross Neuman / RobotCamp2026](https://github.com/rneum/RobotCamp2026). Demo adaptations were made for this video series. This is a personal project, with no claim of UT endorsement.

The upstream MIT copyright and permission notice is retained in [LICENSE](LICENSE) and the sketch. The camp's original parts spreadsheet is included unchanged as `camp-parts-list.xlsx`. CAD/STL files and lab guides are linked to their original repository.
