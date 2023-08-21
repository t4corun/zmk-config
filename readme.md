# [T4CORUN ZMK Config](https://github.com/T4CORUN/zmk-config)

- My keymap is heavily inspired by Manna Harbor Miryoku. I flipped some things around and made some operations doable with the left side so I can keep using the mouse

## ZMK Notes

- [ZMK Official](https://github.com/zmkfirmware/zmk) does not have Rollow shield definition built in or support Peripheral Side Encoder as of 2023-08-20
- Uses [nickconway/zmk GitHub](https://github.com/nickconway/zmk) dev branch to get
	- peripheral side encoder
	- mouse support
	- 2023-Aug: Leveraging the shield definition he imported into `/app/boards/shields/rollow` versus including my own
- [Previous commit](https://github.com/T4CORUN/zmk-config/commit/34b44a78fa057029da4901533f4dfb751d2bf727) before my 2023-Aug update for breaking changes. This commit includes examples of
	- header files, macros, tap dances
	- "custom" shield definition. Imported rollow definition by [tutuuXY](https://github.com/TutuuXY/zmk-config)

## Barbell Rollow

- [Product Page](https://www.barbellboards.com/product/rollow)
- [barbellboards · GitHub](https://github.com/barbellboards)

Quote by Barry

```text
Rollow is one of the first split keyboards with dedicated thumb encoders... It's inspired by the ergonomics of a Ferris and the elegance of a Corne. While also influenced by my passion for the automotive customization scene.

This passion is represented in the small details like…

- A base plate designed with hot-swap socket cutouts, allowing sockets to fit within the plate making Rollow one of the lowest sitting hot-swappable split keyboards (Excluding Mini Version).
- Custom Inset OLED covers add additional protection to your OLEDs, while maintaining a balanced, sleek, and flush appearance to your board.
- Gasket-like sound dampening layer to minimize unwanted rattles and noise.
```

## Personal Additions

- Created ability for user to choose 5 column or 6 column layout. This way you do not have to put `&none` on the outer columns on a 3x5 layout
- Created encoder support for mouse movement/scrolling emulation. Out of the box ZMK only supports `&kp` for encoders
- Allows switching between QWERTY and COLEMAKDH for base layer
