# Parts and purchase links

Source: [UT camp bill of materials](https://github.com/rneum/RobotCamp2026/blob/main/Hapkit%20Parts/Hapkit%201DOF%20BOM.xlsx). Quantities below are per build, not the number of items in a seller's pack. Amazon links have been shortened to their product IDs, removing camp bulk-order quantities and tracking parameters.

These are the camp's supplier links. The motor listing was checked on October 10, 2026. Not every seller listing, stock level, or variant has been independently verified. Check dimensions, selected variant, and pack size before buying. The demo firmware requires an Uno R3 / ATmega328P at 16 MHz; an Uno R4 is not a drop-in replacement.

## Before buying

- Match the Uno R3, no-gearbox motor, and physical dimensions used by the camp design.
- Check barrel connector dimensions and polarity against the supply and adaptor listings.
- Pack sizes are seller quantities; the table lists only what one build uses.
- Tools can be reused. The storage bin and spare wire rope are optional.
- Prices are not fixed here: check each seller's current price, availability, shipping, and selected variant.

## Electronics and mechanical components

| Part | Quantity | Purchase link |
|---|---|---|
| Pololu 4860 motor with integrated encoder | 1 | [Supplier](https://www.pololu.com/product/4860) |
| Motor Driver L298N | 1 | [Supplier](https://www.amazon.com/dp/B0C5JCF5RS) |
| 12V 2A Power Supply | 1 | [Supplier](https://www.amazon.com/dp/B0DFPNZ77T) |
| Barrel Jack adaptor | 1 | [Supplier](https://www.amazon.com/dp/B079RCNNCK) |
| Arduino Uno R3-compatible board | 1 | [Supplier](https://www.amazon.com/dp/B0B6VV7MS7) |
| Jumper Wires M-M 10cm | 8 | [Supplier](https://www.amazon.com/dp/B0BRTL3BHR) |
| Jumper Wires M-M 20cm | 1 | [Supplier](https://www.amazon.com/dp/B0BRTJQZRD) |
| Jumper Wires F-M 20cm | 3 | [Supplier](https://www.amazon.com/dp/B0BRTHR2RL) |
| Ball bearing 608 | 2 | [Supplier](https://www.amazon.com/dp/B09PKD8QZZ) |
| M6 shoulder bolts | 1 | [Supplier](https://www.mcmaster.com/92981A202/) |
| M6x1 Nut | 1 | [Supplier](https://www.mcmaster.com/90591A151/) |
| M3x0.5 10mm flat head screw | 9 | [Supplier](https://www.mcmaster.com/92010A120/) |
| M3x0.5 Nut | 9 | [Supplier](https://www.mcmaster.com/91828A211/) |
| M5x0.8 30mm socket screw | 1 | [Supplier](https://www.mcmaster.com/91290A194/) |
| M5x0.8 nut | 1 | [Supplier](https://www.mcmaster.com/90591A260/) |
| 4-40 3/8" pan head screw | 2 | [Supplier](https://www.mcmaster.com/91735A104/) |
| Compression fitting | 2 | [Supplier](https://www.mcmaster.com/3898T29/) |
| Wire rope | 16" | [Supplier](https://www.mcmaster.com/8930T16-8930T543/) |
| Wire rope (extra in case of breaks) | Not specified | [Supplier](https://www.mcmaster.com/8930T16-8930T542/) |

The Pololu 4860 motor has an integrated 48-count-per-revolution encoder and no gearbox. Match the camp design rather than substituting a geared motor. [Manufacturer specifications](https://www.pololu.com/product/4860).

## Tools and optional storage

| Item | Quantity | Purchase link |
|---|---|---|
| Phillips #1 Screwdriver | 1 | [Supplier](https://www.amazon.com/dp/B0006OBFP4) |
| 4mm allen wrench | 1 | [Supplier](https://www.amazon.com/dp/B0D984S6SD) |
| Eyeglass screwdriver Phillips | 1 | [Supplier](https://www.amazon.com/dp/B0CM8SWMXC) |
| Storage bin | 1 | [Supplier](https://www.amazon.com/dp/B01MR7L1VD) |

## Printed parts

Download the [camp STL files and assembly model](https://github.com/rneum/RobotCamp2026/tree/main/Hapkit%20Parts/1DOF%20STL): Base, Bearing Housing, Handle, Motor Shaft, PCB Mount, Sector, and Tensioner. Follow the camp assembly guide for print and assembly requirements.

## Additional setup items

- A computer with Arduino IDE and the Encoder library by Paul Stoffregen.
- A USB data cable matching your Uno R3 and computer; verify whether your board includes one.
- Access to a 3D printer or printing service for the structural parts.

Use the [camp lab guides](https://github.com/rneum/RobotCamp2026) for full assembly and power wiring. The list above transcribes the original BOM; tools and storage are separated for easier shopping.

## Build next

[Wiring and assembly](docs/WIRING.md) · [Mac and Windows software setup](docs/SETUP.md) · [First-run checks](docs/CALIBRATION.md)
