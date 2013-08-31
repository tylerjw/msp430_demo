// butled3.c - program toggles LED once each time the button is pressed
// on first press, off second, on third, etc...
// launchpad with msp430g2553, red led on P1.0, green led on P1.6
// button on P1.3

#include  <msp430g2553.h>

#define LEDS    (BIT0|BIT6)
#define BTN     (BIT3)

void main(void)
{
    WDTCTL = WDTPW | WDTHOLD;       // disable wdt+
    P1OUT = 0;                      // leds off
    P1DIR = LEDS;                   // output enable leds

    for (;;)
    {
        while(!(P1IN & BTN));   // button up, loop
        while(P1IN & BTN);      // button down, loop
        P1OUT = (P1OUT & LEDS)^LEDS; // cycle leds
    }
}