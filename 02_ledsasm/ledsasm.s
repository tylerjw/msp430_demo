; ledsasm.s43 - simple program to light LEDs, absolute assembly
; Lights pattern of LEDs, sets pins to output, then loops forever
; launchpad with msp430g2553, red led on P1.0, green led on P1.6

;---------------------------------------------------------------
#include <msp430g2553.h>

    ORG     0x0C00                  ; start of 16kb flash memory for code
Main:                               ; execution starts here
    mov.w   #WDTPW|WDTHOLD,&WDTCTL  ; stop watchdog
    mov.b   #01000001b,&P1OUT       ; set P1.0 and P1.6 high
    mov.b   #01000001b,&P1DIR       ; configure P1.0 and P1.6 output
InfLoop:                            ; infinate loop
    jmp     InfLoop
;---------------------------------------------------------------
    ORG     0xFFFE                  ; address of reset vector
    DW      Main                    ; Address to start execution
    END