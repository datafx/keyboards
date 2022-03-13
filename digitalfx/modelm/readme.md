# modelm terminal

IBM Model M TERMINAL ANSI

This project is based heavily on the work of [Ben Chapman](https://www.crackedthecode.co/how-to-supercharge-your-ibm-model-m-with-qmk/)

This is a configuration for the QMK firmware to convert the Model M to a controller that uses the USB bus and to add extra features that may or may not have been included in the original device.  
This configuration is build for the Atmel AT90USB1286 controller, which you can easily use on the Teensy 2.0++ board (produced by PJRC), and the VIAL version of QMK.

For this conversion you will need:  
1. Teensy 2.0++ dev board you can use a different dev board, but it will require some changes in the configuration)
2. Ribbon connectors to connect the membrane to the dev board. Depending on your Model M variation, you will need 1 Trio-mate 16pin connector (6-520315-6 or 6-520415-6) and 1 Trio-mate 8pin connector (5-120628-8 or 
5-520314-8), or 2 Trio-mate 16pin connectors
3. Full-sized breadboard (half-size should do, but a full-sized one looks more native) or a PCB to wire everything up
4. A bunch of jumper wires and/or ribbon cables
5. Mini-USB male cable with any USB socket you want to use to connect Teensy inside the keyboard to your PC (I used a short mini-USB male to mini-USB female cable)
6. (optional) NeoPixel through hole LEDs and a small protoboard for status LEDs
7. (optional) Double-sided tape or screws to fix USB socket on or inside the keyboard case
8. (optional) 5cm 8ohm 0.5W speaker

Pins of the Teensy board you should use by default:
```  
Columns: 1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16  
Pins:    C7 C6 C5 C4 C3 C2 C1 C0 E1 E0 D7 D6 D5 D4 D3 D2  
--------------------------------------------------------  
Rows: 1  2  3  4  5  6  7  8  
Pins: E7 B0 B1 B2 B3 B4 B5 B6  
--------------------------------------------------------  
Audo: B7
RGB: D0

Note: The LED (D1) or it's resistor (R3) must be removed from the Teensy in order for pin D6 to function properly.
```  

The terminal version of the Model M did not come with status LEDs.  You will need to drill the case and purchase an LED overlay from Unicomp if you wish to add them yourself.  You can try to find an original PCB, or 
like this project, create your own with NeoPixel LEDs.  The adafruit part number I used is 1938.

Keyboard Maintainer: [datafx](https://github.com/datafx)  
Hardware Supported: Teensy 2.0++ board by PJRC  
Hardware Availability: https://www.pjrc.com/store/teensypp.html 

Make example for this keyboard (after setting up your build environment):

    make digitalfx/modelm:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).
