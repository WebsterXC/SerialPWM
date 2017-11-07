# SerialPWM #
A Microchip PIC16F used to control 4 PWM duty cycles using basic GPIO inputs.

## About ##
SerialPWM uses a PIC16 microcontroller to control 4 PWM channels. It
offers an easy-to-use digital logic interface as opposed to more complex
communications protocols, making it a low-cost solution for expanding PWM
capability. All PWM outputs use the same time base, but maintain individual
duty cycles.

The whole MPLABX project folder is supplied for quick deployment. Simply
clone the repository, import the project, connect your programmer to RA0/RA1 
and program the device.

## Signal Definitions ##
Datasheet-like documentation* and a visual pinout can be found in the /docs directory.

*In-Progress

#### Input / Output ####

| Pin ID | Port ID | Designation | Description |
| ----- | ------- | ----------- | ---------- |
| 1 | VDD | VDD | MCU power. See datasheet for correct supply voltage. |
| 2 | RA5 | DUTYDN# | A falling edge on this signal decrements the selected channel's duty cycle by 5%. |
| 3 | RA4 | DUTYUP# | A falling edge on this signal increments the selected channel's duty cycle by 5%. |
| 4 | MCLR# | Reset | Active-low system reset. |
| 5 | RC5 | PWM1 | PWM output channel 1. |
| 6 | RC4 | PWMSEL0 | PWM channel select line 0. |
| 7 | RC3 | PWM2 | PWM output channel 2. |
| 8 | RC2 | PWMSEL1 | PWM channel select line 1. |
| 9 | RC1 | PWM4 | PWM output channel 4. |
| 10 | RC0 | EN# | Chip enable. When high, all DUTY commands are ignored. This allows multiple SerialPWM chips to be cascaded. |
| 11 | RA2 | PWM3 | PWM output channel 3. |
| 12 | RA1 | ICSPDAT | Dedicated programming line (data). |
| 13 | RA0 | ICSPCLK | Dedicated programming line (clock). |
| 14 | VSS | VSS | MCU ground connection. |

#### PWM Channel Select ####

| PWMSEL0 | PWMSEL1 | PWM Channel Selected |
| 0 | 0 | PWM1 |
| 0 | 1 | PWM2 |
| 1 | 0 | PWM3 |
| 1 | 1 | PWM4 |

## Tuning Parameters ##
SerialPWM may have to be adjusted per application. The following defaults
are used in the master branch release:

* Target MCU Pinout: PIC16F1503
* MCU System Clock: Internal FRC, 500kHz
* PWM Frequency: 25kHz (Target frequency for ATX PC Fans)
* PWM Granularity: +/- 5%

## Programming ##
Small tutorial with screenshots.
