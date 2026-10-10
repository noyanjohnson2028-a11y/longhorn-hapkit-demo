# Longhorn Hapkit

**Build a handle that lets you feel springs, walls, friction, bumps, and valleys created in code.**

This repository contains Arduino Uno R3 firmware and build resources for a Longhorn Hapkit assembled at a UT Austin robotics camp. The original design and examples are by [Ross Neuman / RobotCamp2026](https://github.com/rneum/RobotCamp2026); this version adds custom effects and clearer setup guidance.

## Choose your starting point

| What you need | Guide |
|---|---|
| Buy the components | [Parts, quantities, and purchase links](PARTS.md) |
| Assemble and connect the device | [Assembly references and wiring](docs/WIRING.md) |
| Install on Mac or Windows | [Software setup and upload](docs/SETUP.md) |
| Check your first working build | [Zeroing, direction, and calibration](docs/CALIBRATION.md) |
| Explore every effect | [Commands and expected behavior](docs/MODES.md) |
| Adjust the feel | [Tuning guide](docs/TUNING.md) |
| Resolve a problem | [Troubleshooting](docs/TROUBLESHOOTING.md) |

## Already assembled? Start here

1. [Download the repository ZIP](https://github.com/noyanjohnson2028-a11y/longhorn-hapkit-demo/archive/refs/heads/main.zip) and extract it.
2. Install Arduino IDE, **Arduino AVR Boards**, and **Encoder by Paul Stoffregen**.
3. Open [`firmware/HapkitDemo/HapkitDemo.ino`](firmware/HapkitDemo/HapkitDemo.ino), select **Arduino Uno** and its port, then verify and upload.
4. Open Serial Monitor at **115200 baud**. Center the handle and send `0`.
5. Send `1` and confirm it pulls toward zero from both sides. Continue with the [first-run guide](docs/CALIBRATION.md).

## Hardware compatibility

| Component | Required configuration |
|---|---|
| Controller | Uno R3, ATmega328P, 16 MHz |
| Motor/encoder | Camp motor: Pololu 4860, no gearbox, 48 CPR |
| Driver | Camp L298N module, correctly powered and configured |
| PWM | Uno D9, Timer1 at 20 kHz |
| Motor supply | Camp BOM specifies 12V, 2A |
| Software | Arduino IDE on Mac or Windows; Encoder library |

**Uno R4 is not compatible with this sketch.** Other boards, motors, geometry, or driver modules need their own checks. The code has been compiled for Uno; the effects were reported working on the creator's assembled R3 build. Mac and Windows instructions describe the same firmware workflow, not separate operating-system-dependent firmware.

## Effects at a glance

| Command | Effect |
|---|---|
| `0` | Stop output and zero current position |
| `1` | Centering spring |
| `2` | One wall |
| `3` | Damped wall |
| `4` | Damper |
| `5` | Friction |
| `6` | Smooth bump |
| `7` | Stronger bump |
| `8` | Bump and valley |
| `9` | Two walls with impact |
| `A` | Damped centering spring |

See [mode locations and behavior](docs/MODES.md). Mode A intentionally replaces the original camp mass-spring-damper simulation. Send one command at a time; line endings are ignored and lowercase `a` works too.

## How it works

An encoder measures motion. The Arduino computes a signed motor command from position and filtered velocity. The driver powers the motor, which transmits force through the mechanism to the handle. Commands are limited to +/-400 PWM; they are not measured forces in newtons.

## Original design resources

- [Camp repository and lab guides](https://github.com/rneum/RobotCamp2026)
- [Original bill of materials](https://github.com/rneum/RobotCamp2026/blob/main/Hapkit%20Parts/Hapkit%201DOF%20BOM.xlsx)
- [STL files and assembly STEP model](https://github.com/rneum/RobotCamp2026/tree/main/Hapkit%20Parts/1DOF%20STL)
- [Original fast-PWM firmware](https://github.com/rneum/RobotCamp2026/blob/main/all_environments_fast_PWM/all_environments_fast_PWM.ino)

The unchanged source spreadsheet is included as [camp-parts-list.xlsx](camp-parts-list.xlsx). Mechanical assembly details remain in the upstream guides; this repository does not replace them with guessed instructions.

## Build verification

The GitHub Actions workflow compiles the sketch for `arduino:avr:uno`. Compilation checks board compatibility and syntax; it cannot verify mechanical assembly, force direction, or physical performance. See [development notes](CONTRIBUTING.md) for local compilation and issue reporting.

## Credit and license

Original camp code and documentation: Ross Neuman, 2026. MIT notice retained in [LICENSE](LICENSE) and the sketch. Local adaptations include serial parsing, timed foreground updates, stronger bumps, two walls, and a damped centering spring. CAD/STL files remain linked to their original source. This personal project does not claim UT endorsement.
