// butled2.c - press button to light LEDs
// Two loops, one for each state of the button
// launchpad with msp430g2553, red led on P1.0, green led on P1.6
// button on P1.3

#include  <msp430g2553.h>

// Pins for LEDS and button on port 1
#define LEDS    (BIT0|BIT6)
#define BTN     (BIT3)

void main (void)
{
    WDTCTL = WDTPW | WDTHOLD;   // disable wdt+
    P1DIR |= LEDS;          // set red and green led out
    P1REN |= BTN;          // pull enabled
    P1OUT |= BTN;          // pull up 

    for (;;)
    {
        while(P1IN & BTN);   // button up, loop
        P1OUT = LEDS;           // turn on leds
        while(!(P1IN & BTN));      // button down, loop
        P1OUT = ~LEDS;          // turn off leds
    }
}