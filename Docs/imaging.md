## Steps to Image VisionFive2
1. Set bootmode to UART as detailed (here)[https://doc-en.rvspace.org/VisionFive2/Boot_UG/VisionFive2_SDK_QSG/boot_mode_settings.html]
2. Connect UART probe and power the board.
3. Run `vf2 minikernel.img` to load image.
4. After loading image, unplug power from board and change bootmode back to QSPI.
5. Repower board. Board will be running new image.