#include  <msp430g2553.h>

#define RED_LED BIT0

void main (void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop the watchdog timer
    P1DIR |= RED_LED            // set output for red led
    P1OUT |= RED_LED            // turn the led on
    for(;;){
        // loop forever
    }
}