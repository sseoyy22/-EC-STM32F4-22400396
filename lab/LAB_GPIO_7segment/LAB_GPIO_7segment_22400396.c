/*----------------------------------------------------------------\
@ Embedded Controller by Young-Keun Kim - Handong Global University
Author           : [Seoyoon Shin - 22400396]
Created          : 05-03-2021
Modified         : 09-22-2026
Language/ver     : C++ in VS Code

Description      : GPIO 7-segment(eval board)
/----------------------------------------------------------------*/

#include "stm32f4xx.h"
#include "ecGPIO2.h"
#include "ecRCC2.h"

PinName_t pinFND[8]    = {PB_0, PB_1, PB_2, PB_3, PB_4, PB_5, PB_6, PB_7};
PinName_t selectFND[4]={PA_10, PA_11, PC_4, PC_3};
PinName_t pinButton = PA_4;  // SW2

void setup(void){
    // Intialize System Clock
    RCC_HSI_init();    
    // Intialize FND pins and Others
    FND_init(pinFND);
    FND_select_init(selectFND);    
    GPIO_init(pinButton, INPUT);
    GPIO_pupd(pinButton, PU); 
};

int main(void) {
    setup();

    uint8_t num = 0; 
    uint8_t buttonState = HIGH; 
    uint8_t prevButtonState = HIGH;


    while (1) {

        buttonState = GPIO_read(pinButton); 

        if (buttonState == LOW && prevButtonState == HIGH) {
            num++; 
            
            if (num > 9) {
                num=0; 
            }
            delay_ms_HSI(1);
        }
        
        prevButtonState = buttonState; 

        FND_select(0);
        FND_display(num);            			
    }
}

