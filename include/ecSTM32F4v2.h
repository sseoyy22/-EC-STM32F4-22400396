/*----------------------------------------------------------------\
@ Embedded Controller by Young-Keun Kim - Handong Global University
Author           : Seoyoon Shin - 22400396
Created          : 05-03-2021
Modified         : 10-01-2026 
Language/ver     : C++ in VS Code

Description      : STM32F411 Library
/----------------------------------------------------------------*/

#ifndef __EC_STM_H
#define __EC_STM_H

// STM built-In Library
#include "stm32f4xx.h"
#include "stm32f411xe.h"
#include "math.h"

// EC course Library
#include "ecPinNames.h"
#include "ecRCC2.h"
#include "ecGPIO2.h"
#include "ecEXTI2.h"
#include "ecSysTick2.h"
//#include "ecTIM2.h"
//#include "ecPWM2.h"
//#include "ecStepper2.h"
//#include "ecADC2.h"
//#include "ecUART2.h"

void MCU_init(void){
    // CLOCK PLL 84MHz
    RCC_PLL_init();
    
    // SysTick 1msec
    SysTick_init();    

    // SW1 : PD_2
    GPIO_init(PD_2, INPUT);
    GPIO_pupd(PD_2, PU);

    // SW2 : PA_4
    GPIO_init(PA_4, INPUT);
    GPIO_pupd(PA_4, PU);

    // 7-Segment
    PinName_t FND_pins[8] = {
        PB_0, PB_1, PB_2, PB_3,
        PB_4, PB_5, PB_6, PB_7
    };

    FND_init(FND_pins);

    // 7-segment GPIO 
    GPIO_init(PB_0, OUTPUT);
    GPIO_init(PB_1, OUTPUT);
    GPIO_init(PB_2, OUTPUT);
    GPIO_init(PB_3, OUTPUT);
    GPIO_init(PB_4, OUTPUT);
    GPIO_init(PB_5, OUTPUT);
    GPIO_init(PB_6, OUTPUT);
    GPIO_init(PB_7, OUTPUT);     

    GPIO_ospeed(PB_0, MEDIUM_SPEED);
    GPIO_ospeed(PB_1, MEDIUM_SPEED);
    GPIO_ospeed(PB_2, MEDIUM_SPEED);
    GPIO_ospeed(PB_3, MEDIUM_SPEED);
    GPIO_ospeed(PB_4, MEDIUM_SPEED);
    GPIO_ospeed(PB_5, MEDIUM_SPEED);
    GPIO_ospeed(PB_6, MEDIUM_SPEED);
    GPIO_ospeed(PB_7, MEDIUM_SPEED);

    
    // FND Select 
    GPIO_init(PA_10, OUTPUT);   
    GPIO_init(PA_11, OUTPUT);

    // EXTI 
    EXTI_init(PD_2, FALL, 0);
    EXTI_init(PA_4, FALL, 1);

    // TIMx Default Initialization
    // ...
    // PWM Default Initialization
    // ...        
    // USART Default Initialization
    // ...
    // Others
}

#endif



 