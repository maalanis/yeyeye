#import "mine.h" 

void buzzer_set_period(short cycles){
    CCR0 = cycles;
    CCR1 = cycles >>1;
}
int main(void){
    //timer methods
    configureClocks();
    enableWDTInterrupts();
    timerAUpmode();
    P2SEL2 &= ~(BIT6 | BIT7);
    P2SEL &= ~BIT7;
    P2SEL |= BIT6;
    P2DIR = BIT6;
       
    P1DIR &= ~SW1;
    P1REN |= SW1;
    P1OUT |= SW1;
    P1DIR |= LED_GREEN + LED_RED;
    P1OUT |= LED_GREEN;
    P1OUT &= ~RED;
    P2DIR &= ~BUTTON1;
    P2REN |= BUTTON1;
    P2OUT |= BUTTON1;

    while(1){
        if((P1IN & SW1) == SWITCH_DOWN){
            while((P1IN & SW1) == SWITCH_DOWN);
            P1OUT ^= LED_GREEN | LED_RED;
        }

        if((P2IN & BUTTON1) == SWITCH_DOWN){
            while((P2IN & BUTTON1) == SWITCH_DOWN);
            P1OUT |= LED_GREEN;
            P1OUT &= ~LED_RED;
            buzzer_set_period(1000);
        }
        if((P2IN & BUTTON2) == SWITCH_DOWN){
            while((P2IN & BUTTON2) == SWITCH_DOWN);
            P1OUT |= LED_RED;
            P1OUT &= ~LED_GREEN;
            buzzer_set_period(0);
        }
        if((P2IN & BUTTON3) == SWITCH_DOWN){
            while((P2IN & BUTTON3) == SWITCH_DOWN);
            P1OUT |= LED_RED;
            P1OUT |= LED_GREEN;
            buzzer_set_period(1000);
            buzzer_set_period(NOTE1);
            buzzer_set_period(NOTE1);
            buzzer_set_period(NOTE1);
            buzzer_set_period(1000);
            buzzer_set_period(NOTE1);
            buzzer_set_period(NOTE2);
            buzzer_set_period(NOTE3);
            buzzer_set_period(NOTE1);
        }
        if((P2IN & BUTTON4) == SWITCH_DOWN){
            while((P2IN & BUTTON4) == SWITCH_DOWN);
            P1OUT &= ~LED_GREEN & ~LED_RED;
        }
    }
    return 0;
}