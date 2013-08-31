#include  <msp430g2553.h>

#define RED_LED     BIT0
#define GREEN_LED   BIT6

void main (void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop the watchdog timer
    P1DIR |= RED_LED | GREEN_LED;    //set output for leds
    P1OUT = RED_LED;            // turn the red led on
    for(;;){
        // loop forever
    }
}