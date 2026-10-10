# First run and calibration

[Home](../README.md) · [Setup](SETUP.md) · [Troubleshooting](TROUBLESHOOTING.md)

## 1. Check movement with output off

Open Serial Monitor at 115200 baud. Center the handle and send `0`. Move gently in both directions: `x_cm` should change and `PWM` should remain zero. Returning to the starting point should bring the position close to zero.

Sending `0` resets once; the position can still change afterward. Send it again only when you want a new reference. This is manual zeroing, not automatic homing.

## 2. Establish the middle

Place the handle at the physical middle of its usable travel, then send `0`. Spring modes return toward this chosen point; they cannot identify the mechanical middle automatically. Re-zero after resetting the board or moving the reference.

## 3. Check force direction

Send `1`, gently move a small distance to one side, and feel the response. It should pull toward zero. Repeat on the other side. If it pushes farther away, stop with `0` and disconnect motor power before changing wiring. Reverse one directional relationship (motor leads or encoder channels), then repeat; reversing both preserves their relative sign.

On the original working build, physical left measured positive and right negative. A different viewing angle or assembly can change that convention. Use the printed position to locate effects.

## 4. Check effects in order

Try `1`, then `A`, then the motion-only modes `4` and `5`. Explore `2` and `3` beyond +2 cm. Try `6` and `7` around +1.5 cm, `8` on both sides, and finally `9` at both boundaries. Send `0` at center between checks.

## 5. Check scale if your geometry differs

The firmware assumes 48 encoder counts per motor revolution, an 8.5 cm handle radius, 0.5 cm motor pulley radius, and 7.5 cm sector radius. Counts are converted to pulley angle, then scaled by the mechanism geometry. The reported displacement is an arc-length-style estimate based on those dimensions, not an independently measured Cartesian displacement.

If the encoder or pulley dimensions differ, update those constants before adjusting wall positions. Gearboxes change the relationship between encoder rotation and output rotation; do not substitute a geared motor without revisiting the calculation.

## Completion checklist

- [ ] Output stays at zero in mode 0.
- [ ] Position changes smoothly in both directions.
- [ ] Centered zero is repeatable.
- [ ] Spring pulls toward zero on both sides.
- [ ] Walls and bumps occur at their documented printed positions.
- [ ] The mechanism does not bind or slip.

The motor can become hot when held against resistance. Keep checks brief, keep fingers out of the cable/pulley mechanism, and disconnect motor power for unexpected motion. Command 0 is a software stop, not a hardware emergency disconnect.
