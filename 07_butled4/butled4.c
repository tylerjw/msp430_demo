// // butled4.c - program toggles LED once each time the button is pressed
// couts the number of times a cycles through possible binary values on
// led 1 and 2
// launchpad with msp430g2553, red led on P1.0, green led on P1.6
// button on P1.3

#include  <msp430g2553.h>

#define LED1    (BIT0)
#define LED2    (BIT6)
#define BTN     (BIT3)

void advance_leds();

int led_states[4] = [0,(LED1),(LED2),(LED1|LED2)]

void main(void)
{
    WDTCTL = WDTPW | WDTHOLD;       // disable wdt+
    P1OUT = BTN;                    // pull up
    P1REN = BTN;                    // pull enabled
    P1DIR = LEDS;                   // output enable leds

    for (;;)
    {
        while(P1IN & BTN);   // button up, loop
        while(!(P1IN & BTN));      // button down, loop
        advance_leds();
    }
}

void advance_leds(void)
{
    static state = 0;
    if(state == 4) 
        state = 0;
    else
        state++;
    P1OUT = led_states[state];
}