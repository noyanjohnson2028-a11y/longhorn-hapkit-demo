# Tuning the effects

[Home](../README.md) · [Modes](MODES.md) · [Calibration](CALIBRATION.md)

Start from the working sketch, save a copy, and change one parameter at a time. Verify and upload after edits. Check force direction before increasing output.

## Parameters in the sketch

| Effect | Current settings | Change to adjust |
|---|---|---|
| Spring 1 | stiffness 80 | Pull toward zero |
| Wall 2 | position +2, stiffness 200 | Boundary and penetration resistance |
| Damped wall 3 | position +2, stiffness 200, damping 5 | Boundary resistance and motion damping |
| Damper 4 | damping 8 | Resistance versus speed |
| Friction 5 | strength 140, transition speed 0.5 | Resistance level and behavior near rest |
| Bump 6 | center +1.5, half-width 1, strength 220 | Location, width, and peak output |
| Bump 7 | center +1.5, half-width 1, strength 280 | Stronger peak profile; ramps 0.20 and 0.25 |
| Bump/valley 8 | centers +1.5/-1.5, half-width 1, strength 250 | Locations, widths, and attraction/repulsion |
| Walls 9 | boundaries +/-2, stiffness 250, damping 3 | Boundary resistance and damping |
| Spring A | stiffness 100, damping 2 | Return strength and settling |

Geometry uses cm and velocity uses cm/s. Strength/stiffness settings are gains producing PWM commands; they are not calibrated physical spring constants.

## Making a bump easier to find

For mode 6, `bumpForce(position, 1.5, 1.0, 220.0)` means center, half-width, and strength. Increase width to enlarge the active region, or move its center into comfortable travel. At the exact peak its force is zero and changes direction on either side; that is intentional. For mode 7, change the half-width condition and ramp-out calculation together if changing width.

## Making a valley distinct

Mode 8 attracts toward -1.5 cm only inside its valley region. Sweep both sides of zero. If only the positive region is explored, you only feel the bump. The valley includes damping to reduce oscillation near its bottom.

## Why stronger is not always better

The command saturates at +/-400. Raising gains beyond saturation does not add motor capability. A stiffer wall can also cause chatter. Check power, geometry, cable tension, direction, and damping before increasing gains. Do not add a permanent minimum PWM just to overcome friction: it can create unwanted motion near zero.

## Control timing

The foreground controller targets roughly 1 ms updates and uses the measured elapsed time. This is not a guaranteed hard real-time interrupt loop. A detected control gap over 20 ms stops output and resets state. Serial output is rate-limited to about 10 Hz. Avoid blocking delays or heavy work in the control path. Timer1 is dedicated to 20 kHz PWM, so libraries that also use Timer1 may conflict.
