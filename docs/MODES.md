# Effects and commands

[Home](../README.md) · [First run](CALIBRATION.md) · [Tuning](TUNING.md)

Send one command at a time in Serial Monitor, at 115200 baud. Commands select an effect; they do not cause a scripted movement. Move the handle yourself to explore the effect. `0` turns off output and defines the current position as zero. Switching to another mode preserves that zero.

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


## Where to feel each effect

- **Spring (1):** displace either side of zero; release gently to feel return toward center.
- **Wall (2):** move above +2 cm. Nothing happens before reaching the wall.
- **Damped wall (3):** same boundary, with extra resistance to movement while in contact.
- **Damper (4):** compare slow and fast sweeps. It is intended to oppose speed, not position.
- **Friction (5):** move both ways. Resistance levels off outside a small velocity transition around zero.
- **Smooth bump (6):** active from +0.5 to +2.5 cm. Force reverses at the +1.5 cm peak.
- **Stronger bump (7):** same location, with a sharper force transition and stronger plateau.
- **Bump and valley (8):** bump from +0.5 to +2.5 cm; valley from -2.5 to -0.5 cm. The valley attracts toward -1.5 cm. Outside these regions, output is zero.
- **Two walls (9):** free region between -2 and +2 cm; spring-like resistance outside it, damping, and a short speed-dependent vibration on entry. Slow entry may make the impact subtle.
- **Damped spring (A):** spring toward zero plus motion damping. It replaces the original camp mass simulation.

## Reading the output

```text
mode=1 x_cm=2.745 PWM=-219
```

`mode` is the selected effect. `x_cm` is the handle displacement calculated from encoder counts and mechanism dimensions. `PWM` is the signed, limited motor command: sign selects direction; magnitude sets duty cycle on a 0–400 scale. It is not a measured force in newtons. At magnitude 400, the command is saturated and additional calculated force cannot increase motor output.
