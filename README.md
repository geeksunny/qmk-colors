# qmk-colors

Custom color animations for keyboards running the QMK Firmware.

## Usage

This requires building your own keyboard firmware. You will need to [set up your local build environment](https://docs.qmk.fm/#/getting_started_build_tools) before proceeding.

Set up your keymap. This is covered in the QMK documentation ["Building Your First Firmware."](https://docs.qmk.fm/#/newbs_building_firmware)

Open your keymap's `rules.mk` file, or create it if it does not exist. Add this line:

    RGB_MATRIX_CUSTOM_USER = yes

Copy the `rgb_matrix_user.inc` file into your keymap's directory.

And now... ***Build your firmware!***