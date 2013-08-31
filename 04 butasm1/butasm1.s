; butasm1.s - press button to light LEDs
; relocatable assembly
; Single loop with decision
; launchpad with msp430g2553, red led on P1.0, green led on P1.6
; button on P1.3
#include <msp430g2553.h>

; Pins for LED and button on port 1
LEDS    EQU     BIT0|BIT6
B1      EQU     BIT3

    RSEG    CODE
Main:
    mov.w   #WDTPW|WDTHOLD,&WDTCTL  ; stop watchdog
    bis.b   #LEDS,&P1OUT            ; set output
    bis.b   #LEDS,&P1DIR            ; set direction
InfLoop:
    bit.b   #B1,&P1IN               ; test bit B1 of P2IN
    jnz     ButtonUp                ; Jump if not zero, button ButtonUp
ButtonDown:
    bis.b   #LEDS,&P1OUT            ; turn leds on, bit set
    jmp InfLoop                     ; jump to top of infinate loop
ButtonUp:
    bic.b   #LEDS,&P1OUT            ; turn leds off, bit clear
    jmp InfLoop                     ; jump to top
;-------------------------------------------------------------------------
    RSEG    RESET
    DW      Main
    END