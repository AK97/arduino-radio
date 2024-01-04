# Arduino Radio
An FM radio built with an Arduino Uno and a TEA5767 FM radio module.

## Parts
- [ ] Arduino Uno (1)
- [ ] TEA 5767 (1)
- [ ] Breadboard (1)
- [ ] 9V Battery (1)
- [ ] Battery Barrel Plug (1)
- [ ] Speakers (2)
- [ ] LCD Module (1)
- [ ] Wires (Many)
- [ ] 12-ohm Resistors (5)
- [ ] Amplifier (1)
- [ ] Switch (1)
- [ ] 10k-ohm Potentiometer (1)
- [ ] 3.5mm audio cable (1)
- [ ] Small philips head screwdriver (1)
- [ ] Shoebox or Container (1) *(optional)*

## Instructions

#### Wire up the Power
* We want our positive (+) buses to be powered by Arduino Uno's 5V output
* We want our negative (-) buses to be attached to ground (GND)
* Connect the following:

| Arduino | Breadboard |
| --- | --- |
| POWER - 5V | Right side, first row, under the plus sign (red column) |
| POWER - GND | Right side, first row, under the minus sign (blue column) |

#### Attach LCD to Arduino
* Place the LCD such that it is on the left of the breadboard. Its pins should be in ```f1``` - ```f16```
* Place the following wires:

| Arduino | Breadboard |
| --- | --- |
| DIGITAL 6 | ```h3``` |
| DIGITAL 12 | ```h4``` |
| DIGITAL 11 | ```h6``` |
| DIGITAL 5 | ```h11``` |
| DIGITAL 4 | ```h12``` |
| DIGITAL 3 | ```h13``` |
| DIGITAL 2 | ```h14``` |

#### Power the LCD
* Place the following wires:

| From | To |
| --- | --- |
| ```h1``` | Last column (negative bus) (blue) |
| ```h2``` | Second-last column (positive bus) (red) |
| ```h5``` | Last column (negative bus) (blue) |
| ```h15``` | Second-last column (positive bus) (red) |
| ```h16``` | Last column (negative bus) (blue) |

*NOTE: If you're having a hard time connecting wires next to each other on the h-column, you can move them along the same row. For example, DIGITAL 6 could connect to ```i3``` or ```j3``` instead of ```h3```, and the positive (red) bus can connect to ```i2``` or ```j2``` instead of ```h2```.*

#### Add another breadboard

* Connect the right-side positive (red) bus of the first breadboard to the left-side positive (red) bus of the second breadboard
* Connect the right-side negative (blue) bus of the first breadboard to the left-side negative (blue) bus of the second breadboard

#### Connect the potentiometer

* Place the potentiometer (knob) on the second breadboard, into pins ```j1``` - ```j5```. The knob should be facing the right. The three pins on the potentiometer will be inserted into ```j1```, ```j3```, and ```j5```.
* Place the following wires:

| From | To |
| --- | --- |
| Left side, second column (negative bus) (blue) | ```f1``` |
| Arduino - ANALOG IN - A0 | ```f3``` |
| Left side, first column (positive bus) (red) | ```f5``` |

#### Connect the TEA5767 Module

* Plug in the antenna to the module. Make sure to put it in the right slot. One slot will have a speaker icon, and the other will have a signal icon. Plug in the antenna to the port with the signal icon.
* Connect the following wires in the **second** breadboard:

| From | To |
| --- | --- |
| Left side, first column (positive bus) (red) | ```f27``` |
| Arduino - ANALOG IN - A4 | ```f28``` |
| Arduino - ANALOG IN - A5 | ```f29``` |
| Left side, second column (negative bus) (blue) | ```f30``` |

* Plug in the TEA5767 Module to the second breadboard. The four pins should connect to ```j27```, ```j28```, ```j29```, and ```j30```. The top of the module (the side with the pins sticking out) should face LEFT (inward on the breadboard).

