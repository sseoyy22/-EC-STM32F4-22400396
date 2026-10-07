/*----------------------------------------------------------------\
@ Embedded Controller by Young-Keun Kim - Handong Global University
Author           : Seoyoon Shin - 22400396
Created          : 05-03-2021
Modified         : 10-07-2026
Language/ver     : C++ in VS Code

Description      : LAB - EXTI and SysTick: Counter on 7-Segment 
/----------------------------------------------------------------*/

#include "ecSTM32F4v2.h"

#define SW1      PD_2
#define SW2      PA_4
#define FND_SEL  PA_10  
#define FND_SEL1 PA_11  // Challenge: 0 ~ 59

// counter and pause state initialize
volatile uint8_t count = 0;
volatile uint8_t pause = 0;

// Time variables for counting and switch debouncing 
volatile uint32_t lastCount = 0;
volatile uint32_t lastSW2 = 0;


// Initialization
void setup(void)
{
    MCU_init();
}


int main(void)
{
    setup();
    
    // Display initial count and select FND 
    FND_display(count);
    GPIO_write(FND_SEL, HIGH);

    // Save initial time 
    lastCount = msTicks;

    while (1)
    {
        if (!pause && (msTicks - lastCount >= 1000)) // Count every 1 sec when not paused
        {
            lastCount = msTicks;  

            count++;
            
            // Reset count after 9
            if (count > 9)
                count = 0;

            FND_display(count);
        }
    }
}


// SW1: Reset count to 0
void EXTI2_IRQHandler(void)
{
    if (is_pending_EXTI(SW1))
    {
        count = 0;
        FND_display(count);

        lastCount = msTicks;

        // clear_pending_EXTI(SW1);
    }
}


// SW2 : Pause / Resume
void EXTI4_IRQHandler(void)
{
    if (is_pending_EXTI(SW2))
    {
        // Debounce switch input 
        if (msTicks - lastSW2 >= 200)
        {
            // Toggle pause state
            pause = !pause;
            lastSW2 = msTicks;
            
            // Restart counting from the current time 
            if (!pause)
            {
                lastCount = msTicks;
            }
        }

        clear_pending_EXTI(SW2);        // Clear EXTI pending flag 
    }
}


// // Challenge: 0~59
// // Initialization
// void setup(void)
// {
//     MCU_init();

//     GPIO_init(FND_SEL1, OUTPUT);
// }


// // MAIN
// int main(void)
// {
//     setup();

//     lastCount = msTicks;

//     while (1)
//     {
//         // Count 0 ~ 59
//         if (!pause && (msTicks - lastCount >= 1000))
//         {
//             lastCount = msTicks;

//             count++;

//             if (count > 59)
//                 count = 0;
//         }

//         // 7-segment multiplexing
//         // Tens digit
//         GPIO_write(FND_SEL, LOW);
//         GPIO_write(FND_SEL1, HIGH);
//         FND_display(count / 10);

//         delay_ms(5);

//         // Ones digit
//         GPIO_write(FND_SEL, HIGH);
//         GPIO_write(FND_SEL1, LOW);
//         FND_display(count % 10);

//         delay_ms(5);
//     }
// }


// // SW1
// void EXTI2_IRQHandler(void)
// {
//     if (is_pending_EXTI(SW1))
//     {
//         count = 0;
//         lastCount = msTicks;

//         clear_pending_EXTI(SW1);
//     }
// }


// // SW2 : Pause / Resume
// void EXTI4_IRQHandler(void)
// {
//     if (is_pending_EXTI(SW2))
//     {
//         if (msTicks - lastSW2 >= 200)
//         {
//             pause = !pause;
//             lastSW2 = msTicks;

//             if (!pause)
//             {
//                 lastCount = msTicks;
//             }
//         }

//         clear_pending_EXTI(SW2);
//     }
// }