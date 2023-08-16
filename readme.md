# [T4CORUN ZMK Config](https://github.com/T4CORUN/zmk-config)

[zmk-config/config/cradio.keymap at main · filterpaper/zmk-config · GitHub](https://github.com/filterpaper/zmk-config/blob/main/config/cradio.keymap)

## [Rollow](https://www.barbellboards.com/product/rollow)

Quote by Barry

```text
Rollow is one of the first split keyboards with dedicated thumb encoders... It's inspired by the ergonomics of a Ferris and the elegance of a Corne. While also influenced by my passion for the automotive customization scene.

This passion is represented in the small details like…

- A base plate designed with hot-swap socket cutouts, allowing sockets to fit within the plate making Rollow one of the lowest sitting hot-swappable split keyboards (Excluding Mini Version).
- Custom Inset OLED covers add additional protection to your OLEDs, while maintaining a balanced, sleek, and flush appearance to your board.
- Gasket-like sound dampening layer to minimize unwanted rattles and noise.
```

## Setup

- This is my first time using ZMK and Github Actions. My aim is to port my QMK layout to ZMK. Please bear with me
- My keymap is heavily inspired by Manna Harbor Miryoku. I flipped some things around and made some operations doable with the left side so I can keep using the mouse
- ZMK Official does not define the Rollow Shield or support Peripheral Side Encoder as of 2023-01-18
  - Uses [GitHub - nickconway/zmk: ZMK Firmware Repository](https://github.com/nickconway/zmk) dev branch for peripheral side encoder and mouse support
  - Leveraged [tutuuXY](https://github.com/TutuuXY/zmk-config)'s repo to get shield definition

## Personal Additions

- Created ability for user to choose 5 column or 6 column layout. This way you do not have to put `&none` on the outer columns on a 3x5 layout
- Created encoder support for mouse movement/scrolling emulation. Out of the box ZMK only supports `&kp` for encoders
- Allows switching between QWERTY and COLEMAKDH for base layer

## Todo

[Issue Tracker](https://github.com/T4CORUN/zmk-config/issues)