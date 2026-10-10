# Overview and demo script

Read continuously, with a 1–2 second pause between sections. Demo clips appear over the narration. Bracketed notes are editing directions, not spoken lines.

## Introduction — on camera

“This is the first video in a series about the Longhorn Hapkit, a project I built at a robotics camp at UT Austin.

Today is just an overview. I’ll explain what it is, briefly show how it works, and demonstrate the different effects it can create.

In future videos, I’ll cover the parts, assembly, wiring, and programming so you can build one yourself. The parts list, project files, and demo code are linked in the description and pinned comment.”

[Pause]

“The Hapkit is a haptic device, which means it creates feedback you can feel. You might be familiar with vibrations in a game controller. This device uses a motor to apply force to a handle.”

## Mode 0 — IMG_5270.MOV

“An encoder measures movement, the Arduino calculates a response, and a motor driver controls the motor.

Right now, the motor output is turned off, so there’s no programmed resistance. Let’s see what happens when we turn on the different effects.”

## Mode 1 — IMG_5271.MOV

[Pause]

“First is the spring.

I set the middle as the starting position. When I move the handle away from it, the motor pulls back toward that point.

The farther I move, the stronger the pull becomes. When I release it, it returns toward the middle. There isn’t a physical spring doing that—the motor is creating the effect.”

## Mode 2 — IMG_5272.MOV

[Pause]

“Next is a virtual wall.

The handle moves freely until it reaches a position set in the code. Beyond that position, the motor pushes back.

That makes it feel like I’ve reached a boundary, even though nothing is physically blocking the handle there.”

## Mode 3 — IMG_5273.MOV

[Pause]

“This version adds damping to the wall.

While I’m in contact with it, the motor also resists movement. That changes how the wall feels when I push into it.”

## Mode 4 — IMG_5264.MOV

[Pause]

“Here’s damping on its own.

When I move slowly, there’s less resistance. When I move faster, there’s more.

It doesn’t pull toward the middle—it resists how quickly I’m moving.”

## Mode 5 — IMG_5268.MOV

[Pause]

“This mode simulates friction.

I feel resistance as I move in either direction. Unlike the spring, it doesn’t try to return the handle to the middle.”

## Mode 6 — IMG_5269.MOV

[Pause]

“Next is a virtual bump.

As I approach its peak, the motor pushes against me. Once I cross the peak, the force changes direction and pushes me toward the other side.”

## Mode 7 — IMG_5262.MOV

[Pause]

“This is a stronger version of the bump.

It feels more pronounced, with a sharper change in force around the peak.”

## Mode 8 — IMG_5263.mov

[Pause]

“Now we have a bump and a valley.

On the left, the bump pushes me away from its peak. On the right, the valley pulls me toward its bottom, so the handle tends to settle in that spot.

You can’t feel it through the screen, but one feels like moving over a raised area, while the other feels like moving into a dip.”

## Mode 9 — IMG_5261.mov

[Pause]

“This mode puts a wall on each side.

There’s free space in the middle, then resistance at either edge. It also adds a brief impact effect when I enter a wall.”

## Mode A — IMG_5267.MOV

[Pause]

“Finally, this is a spring with damping.

It pulls toward the middle like the first spring, but it also resists motion. That helps the handle settle with less bouncing.”

## Ending — on camera

[Pause]

“All of these effects use the same hardware. Changing how the motor responds to movement changes what you feel through the handle.

The original design and example code came from the camp. I’ve adjusted some of the modes for these demonstrations, and both the original project and my demo version are linked below.

In the next video, I’ll go through the parts and what each one does before we move on to assembly and setup.

I’m also considering putting together kits with the parts in one box, so let me know in the comments if that would interest you.

Thanks for watching, and I’ll see you in the next video.”

[Wait 3 seconds before stopping the recording]
