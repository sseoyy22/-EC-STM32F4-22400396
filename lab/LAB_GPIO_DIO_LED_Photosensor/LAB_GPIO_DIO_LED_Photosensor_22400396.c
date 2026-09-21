/*----------------------------------------------------------------\
@ Embedded Controller by Young-Keun Kim - Handong Global University
Author           : [Seoyoon Shin - 22400396]
Created          : 05-03-2021
Modified         : 09-14-2026
Language/ver     : C++ in VS Code

Description      : Toggle a Single LED with Digital Sensor(Photodetector)
/----------------------------------------------------------------*/

#include "ecRCC2.h"
#include "ecGPIO2.h"

#define LED_PIN PB_12
#define BUTTON_PIN PA_0

// Initialization 
void setup(void) {
    RCC_HSI_init(); 
    
    // Photodetector: PA_0
    GPIO_init(BUTTON_PIN, INPUT);
    GPIO_pupd(BUTTON_PIN, PU);

    // LED0: PB_12
    GPIO_init(LED_PIN, OUTPUT);
    GPIO_pupd(LED_PIN, PU);
    GPIO_otype(LED_PIN, OPEN_DRAIN);
    GPIO_ospeed(LED_PIN, MEDIUM_SPEED);
}

int main (void) {
    setup();
    int buttonState=0;

    while(1) {
        buttonState = GPIO_read(BUTTON_PIN);
        if(buttonState) GPIO_write(LED_PIN, LOW);
        else            GPIO_write(LED_PIN, HIGH);
        delay_ms_HSI(100);                              
    }
}
