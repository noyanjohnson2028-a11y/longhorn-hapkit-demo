# Development and support

Keep changes focused and explain which effect or hardware configuration they affect. Include board and dependency versions, a compile result, and any physical checks performed. Never describe a compile-only check as hardware validation.

## Compile locally with Arduino CLI

From the repository root, with [Arduino CLI](https://docs.arduino.cc/arduino-cli/getting-started/) installed:

```sh
arduino-cli core update-index
arduino-cli core install arduino:avr
arduino-cli lib install Encoder
arduino-cli compile --fqbn arduino:avr:uno firmware/HapkitDemo
```

Arduino IDE users can instead select Arduino Uno and click Verify. Mac and Windows use the same FQBN and sketch path. The GitHub workflow performs the CLI compile on Linux.

## Before submitting a change

- Compile for Uno R3 and retain the upstream MIT notice.
- Document any changed mode behavior, pins, dimensions, or dependencies.
- Check zeroing and restoring-force direction on hardware when available.
- Keep heavy work and blocking delays outside the control path.
- Include relevant Serial Monitor output when reporting an issue.

Use [GitHub issues](https://github.com/noyanjohnson2028-a11y/longhorn-hapkit-demo/issues) for reproducible problems or questions. See [troubleshooting](docs/TROUBLESHOOTING.md) for the information needed.
