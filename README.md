# SerialPWM #
A Microchip PIC16F used to control 4 indepedent PWM signals using basic GPIO inputs.

## About ##
SerialPWM uses a PIC16 microcontroller to control 4 independent PWM channels. It
offers an easy-to-use digital logic interface as opposed to more complex
communications protocols, making it a low-cost solution for expanding PWM
capability.

The SerialPWM project was developed using Microchip's MPLABX IDE and MCC Plugin,
and the full project folder is supplied so it can be imported and the MCU flashed
in a matter of minutes.

## Signal Definitions ##
For a visual pinout, please refer to the /docs directory.

#### Inputs ####
SerialPWM uses an interrupt-driven, GPIO interface to control the duty cycle
of the PWM channels. It also offers logic to mask input commands, allowing
the end-user to cascade several of these on the same board.

* **PWM_INH (/ Pin 10)** => Chip inhibit, active-low. When high, the device will
ignore all commands on the DUTY and PWMSEL pins. This allows multiple devices
to share the same control lines.

* **DUTY_UP (/ Pin 3)** => Interrupt-On-Change (rising edge) pin that increases the
current duty cycle by +5%.

* **DUTY_DN (/ Pin 2)** => Interrupt-On-Change (rising edge) pin that decreases the
current duty cycle by -5%.

* **PWMSEL0 (/ Pin 6)** => PWM channel select input. The combination of PWMSEL0 and
PWMSEL1 act as multiplexer control inputs which determines which of the four PWM
channels the DUTY command inputs are pertinent to.

* **PWMSEL1 (/ Pin 8)** => See above.

#### Outputs ####
SerialPWM offers four PWM channels with indepedent duty cycles. All channels use
the MCU's Timer2 module for time base reference.

* **PWM0 (/ Pin 5)**
* **PWM1 (/ Pin 7)**
* **PWM2 (/ Pin 11)**
* **PWM3 (/ Pin 9)**

## Tuning Parameters ##
SerialPWM may have to be adjusted per application. The following defaults
are used in the master branch release:

* Target MCU Pinout: PIC16LF1503
* MCU System Clock: Internal FRC, 500kHz
* PWM Frequency: 25kHz (Target frequency for ATX PC Fans)

## Programming ##
#### So you're ready to use SerialPWM? Here's how! ####
The SerialPWM project is geared towards rapid development; users should be
able to clone this repository, import the project, and be able to flash their
MCU with operational code with very little, if any, changes to the original
source.
