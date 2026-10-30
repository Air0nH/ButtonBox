# ButtonBox

ButtonBox is a handmade, three-button USB keyboard-macro controller I built in late 2021 as a gift. It uses an Arduino board capable of USB HID keyboard emulation. The exact board part number is not firmly established, although the surviving photos and firmware are consistent with a Pro Micro-class board.

## From prototype to finished box

The project began on a breadboard with tactile switches, progressed to an all-printed case, and then to a multi-material enclosure: a 3D-printed body, wooden front face, acrylic rear panel, and large pushbuttons. I later stained the wooden face darker; the surviving wood-front photos show the earlier, unstained finish.

The enclosure and its wiring were physically assembled. This repository is a record of the project, not a recently tested production design.

## Electronics and firmware

The archived [`buttonCode.ino`](buttonCode.ino) uses Arduino's `Keyboard` library to send programmable keystrokes. The source defines these digital inputs:

| Function | Pin |
|---|---:|
| First pushbutton | 9 |
| Second pushbutton | 8 |
| Third pushbutton | 7 |
| Mode switch | 6 |

The mode switch's physical operating position is **not confirmed**. A comment in the archived sketch conflicts with its `HIGH` conditional. The firmware also configures inputs as `INPUT`, so reproducing the wiring requires checking its external bias circuitry. Avoid flashing unreviewed keyboard macros onto a machine where unexpected keystrokes could matter.

## Fabrication assets

Original cut-file sources for the wood and acrylic panels have been recovered, but they have not yet been added here. Their dimensions and material tolerances need verification before they can serve as a fabrication guide. Any future photos or design files should be reviewed for ownership, privacy, and suitability for sharing.

## Project status

**Completed physical gift / historical archive.** The device was built; the preserved firmware has not been recompiled, flashed, or tested in the course of reconstructing this documentation. This page does not guarantee that its pin assignments represent the last flashed revision.

## License

The existing repository [`LICENSE`](LICENSE) contains GNU GPL version 3. Any additional third-party design assets will need separate attribution and license review before being uploaded.
