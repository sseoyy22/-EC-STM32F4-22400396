/*----------------------------------------------------------------\
@ Embedded Controller by Young-Keun Kim - Handong Global University
Author           : [Seoyoon Shin - 22400396]
Created          : 05-03-2021
Modified         : 09-20-2026
Language/ver     : C++ in VS Code

Description      : Toggle multiple LEDs with a button
/----------------------------------------------------------------*/

#include "ecRCC2.h"
#include "ecGPIO2.h"

#define BUTTON_PIN  PA_4

#define LED0_PIN    PB_12
#define LED1_PIN    PB_13
#define LED2_PIN    PB_14
#define LED3_PIN    PB_15


void setup(void) {
    RCC_HSI_init();

    // Button SW2
    GPIO_init(BUTTON_PIN, INPUT);
    GPIO_pupd(BUTTON_PIN, PU);

    // LED0
    GPIO_init(LED0_PIN, OUTPUT);
    GPIO_pupd(LED0_PIN, PU);
    GPIO_otype(LED0_PIN, OPEN_DRAIN);
    GPIO_ospeed(LED0_PIN, MEDIUM_SPEED);

    // LED1
    GPIO_init(LED1_PIN, OUTPUT);
    GPIO_pupd(LED1_PIN, PU);
    GPIO_otype(LED1_PIN, OPEN_DRAIN);
    GPIO_ospeed(LED1_PIN, MEDIUM_SPEED);

    // LED2
    GPIO_init(LED2_PIN, OUTPUT);
    GPIO_pupd(LED2_PIN, PU);
    GPIO_otype(LED2_PIN, OPEN_DRAIN);
    GPIO_ospeed(LED2_PIN, MEDIUM_SPEED);

    // LED3
    GPIO_init(LED3_PIN, OUTPUT);
    GPIO_pupd(LED3_PIN, PU);
    GPIO_otype(LED3_PIN, OPEN_DRAIN);
    GPIO_ospeed(LED3_PIN, MEDIUM_SPEED);

    // Initially LED0 ON
    GPIO_write(LED0_PIN, HIGH);
    GPIO_write(LED1_PIN, LOW);
    GPIO_write(LED2_PIN, LOW);
    GPIO_write(LED3_PIN, LOW);
}


int main(void) {

    setup();

    int buttonState = HIGH;
    int prevButtonState = HIGH;
    int ledIndex = 0;

    while(1) {

        buttonState = GPIO_read(BUTTON_PIN);

        // Detect button press
        if (prevButtonState == HIGH && buttonState == LOW) {

            ledIndex++;

            if (ledIndex > 3)
                ledIndex = 0;

            // Turn all LEDs OFF
            GPIO_write(LED0_PIN, LOW);
            GPIO_write(LED1_PIN, LOW);
            GPIO_write(LED2_PIN, LOW);
            GPIO_write(LED3_PIN, LOW);

            // Turn selected LED ON
            if (ledIndex == 0)
                GPIO_write(LED0_PIN, HIGH);

            else if (ledIndex == 1)
                GPIO_write(LED1_PIN, HIGH);

            else if (ledIndex == 2)
                GPIO_write(LED2_PIN, HIGH);

            else if (ledIndex == 3)
                GPIO_write(LED3_PIN, HIGH);
        }

        prevButtonState = buttonState;

        delay_ms_HSI(20);
    }
}