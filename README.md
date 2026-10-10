# Longhorn Hapkit demo

Arduino Uno R3 firmware, parts, and setup instructions for a Longhorn Hapkit assembled at a robotics camp at The University of Texas at Austin.

## Start here

- **[Parts list and purchase links](PARTS.md)**
- **[Demo Arduino sketch](firmware/HapkitDemo/HapkitDemo.ino)**
- [Original camp project, lab guides, and design files](https://github.com/rneum/RobotCamp2026)
- [3D-print files](https://github.com/rneum/RobotCamp2026/tree/main/Hapkit%20Parts/1DOF%20STL)

## What it does

An encoder measures movement, an Arduino calculates a response, and a motor applies force to the handle. The same mechanism can simulate springs, walls, damping, friction, bumps, and a valley.

## Setup on Mac and Windows

Use an **Arduino Uno R3 / ATmega328P at 16 MHz**. This firmware directly configures Timer1 and requires motor PWM on pin 9. Uno R4 boards are not compatible with this sketch.

### Mac

1. Download Arduino IDE for macOS from the [official download page](https://www.arduino.cc/en/software). Open the downloaded disk image and drag Arduino IDE into Applications, then launch it.
2. On this repository's main page, choose **Code → Download ZIP**. Double-click the ZIP in Finder to extract it.
3. Connect the Uno R3 using a USB **data** cable. Use a USB adapter if your Mac needs one.
4. In Arduino IDE, choose **File → Open** and open `firmware/HapkitDemo/HapkitDemo.ino` inside the extracted folder.
5. Follow the shared upload steps below. Your port will usually resemble `/dev/cu.usbmodem...` or `/dev/cu.usbserial...`; choose the port that appears when the board is connected.

### Windows

1. Download Arduino IDE for Windows from the [official download page](https://www.arduino.cc/en/software). Run the installer, follow its prompts, and launch Arduino IDE.
2. On this repository's main page, choose **Code → Download ZIP**. In File Explorer, right-click the ZIP and choose **Extract All**. Do not open the sketch from inside the compressed ZIP.
3. Connect the Uno R3 using a USB **data** cable.
4. In Arduino IDE, choose **File → Open** and open `firmware/HapkitDemo/HapkitDemo.ino` inside the extracted folder.
5. Follow the shared upload steps below. Your port will usually be named `COM3`, `COM4`, or another COM number; choose the port that appears when the board is connected.

### Upload — both operating systems

1. Open **Boards Manager**, search for **Arduino AVR Boards**, and install it if needed.
2. Open **Library Manager**, search for **Encoder**, and install **Encoder by Paul Stoffregen**.
3. Select **Tools → Board → Arduino AVR Boards → Arduino Uno**.
4. Select your board's port under **Tools → Port**, or use the board selector at the top of the IDE.
5. Click **Verify** (checkmark), then **Upload** (right arrow). Wait for the upload to finish.
6. Connect the motor supply following the camp's power-wiring instructions. The motor connects through the driver, not directly to Arduino pins.
7. Open **Tools → Serial Monitor** and set the baud rate to **115200**.
8. Hold the handle at the physical middle. Type `0` in the message box and press Enter to stop and establish zero.
9. Type a mode from the table below and press Enter. Send `0` to stop and reset between effects.

The parser ignores line endings and accepts either `A` or `a`. Open the complete saved sketch rather than copying partial code blocks.

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

This demo uses 20 kHz PWM, a timed foreground control loop, one-time zeroing, serial diagnostics, stronger/wider bumps, and two walls. **Mode A is a custom damped centering spring, replacing the camp's separate mass-spring-damper simulation.** These are custom effects based on the camp examples.

The effects were reported working on my assembled Uno R3 build. They have not been verified on every hardware variant. If the centering spring pushes away from zero, stop and check motor/encoder direction before tuning force. Disconnect motor power if motion is unexpected, and avoid holding the motor stalled against a wall.

## Credit and license

Original Longhorn Hapkit camp materials and example firmware: [Ross Neuman / RobotCamp2026](https://github.com/rneum/RobotCamp2026). This repository includes custom firmware adaptations. This is a personal project, with no claim of UT endorsement.

The upstream MIT copyright and permission notice is retained in [LICENSE](LICENSE) and the sketch. The camp's original parts spreadsheet is included unchanged as `camp-parts-list.xlsx`. CAD/STL files and lab guides are linked to their original repository.
