# Monsieur Toorop's CRKBD layout

## Build

### Firmware

```
qmk compile --keyboard crkbd/rev1 --keymap monsieurtoorop
```

### Flash

:warning: Sometimes the Ubuntu _ModemManager_ service can cause issues. Stop it before flashing the microcontroler.

```
qmk flash --keyboard crkbd/rev1 --keymap monsieurtoorop
```

or

```
sudo avrdude -p atmega32u4 -P /dev/ttyACM0 -c avr109 -U flash:w:crkbd_rev1_monsieurtoorop.hex
```


MCU = atmega32u4
BOOTLOADER = atmel-dfu
