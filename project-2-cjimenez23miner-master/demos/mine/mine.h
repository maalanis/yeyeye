#include <msp430.h>
#include "libTimer.h"

#define led_included
#define switches_included
#define buzzer_included

#define SW1 BIT3		/* switch1 is p1.3 */
#define SWITCHES SW1
#define LED_RED BIT0               // P1.0
#define LED_GREEN BIT6             // P1.6
#define LEDS (BIT0 | BIT6)
#define stateMachine_included

#define SWITCH_DOWN 0x00
#define S1 P2.0
#define BUTTON1 BIT0
#define BUTTON2 BIT1
#define BUTTON3 BIT2
#define BUTTON4 BIT3

#define NOTE1  250
#define NOTE2  300
#define NOTE3  320
#define NOTE4  350

extern unsigned char red_on, green_on;
extern unsigned char led_changed;
extern unsigned char leds_changed, green_led_state, red_led_state;

