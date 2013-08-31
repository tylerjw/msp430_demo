// butledl.c - press button to light LED
// Single loop with "if"
// launchpad with msp430g2553, red led on P1.0, green led on P1.6
// button on P1.3

#include  <msp430g2553.h>

#define LED_ON  BIT0|BIT6  // both red and green leds
#define BTN     BIT3       // button 


void main (void)
{
    WDTCTL = WDTPW | WDTHOLD; // disable wdt+
    P1DIR |= LED_ON;          // set red and green led out
    P1REN |= BTN;          // pull enabled
    P1OUT |= BTN;          // pull up 
    for(;;) 
    {
        if(!(P1IN & BTN))     // button is down
        {
            P2OUT |= 1;       // turn the leds on
        } else {              // button is not pressed
            P2OUT &= 0;       // turn the leds off
        }
    }
}