---
description: EC_HAL API
---


# Embedded Controller - STM32f411 HAL API

Documentation for HAL functions

Written by:   신서윤

Course:  임베디드컨트롤러

Program: C/C++

IDE/Compiler: Keil uVision 5

OS: WIn10

MCU:  STM32F411RE (Nucleo-64)



---

[TOC]

  * [GPIO Digital In/Out](#gpio-digital-inout)
    + [Header File](#header-file)
    + [GPIO_init\(\)](#gpio_init)
    + [GPIO_mode\(\)](#gpio_mode)
    + [GPIO_write\(\)](#gpio_write)
    + [GPIO_read\(\)](#gpio_read)
    + [GPIO_ospeed\(\)](#gpio_ospeed)
    + [GPIO_otype\(\)](#gpio_otype)
    + [GPIO_pupd\(\)](#gpio_pupd)

  * [7-Segment Display](#7-segment-display)
    + [Header File](#header-file-1)
    + [FND_init()](#fnd_init)
    + [FND_select_init()](#fnd_select_init)
    + [FND_display()](#fnd_display)
    + [FND_select()](#fnd_select)

---

## GPIO Digital InOut 

### Header File

 `#include "ecGPIO.h"`


```c++
#include "stm32f411xe.h"
#include "ecRCC2.h"
#include "ecPinNames.h"

#ifndef __ECGPIO2_H
#define __ECGPIO2_H

// MODER
#define INPUT  		0x00
#define OUTPUT 		0x01
#define AF     		0x02
#define ANALOG 		0x03

// IDR & ODR
#define HIGH 		1
#define LOW  		0

// PUPDR
#define NO_PUPD      0x00
#define PU           0x01
#define PD           0x02
#define RESERVED     0x03

// OTYPER
#define PUSH_PULL 		0	// Push-pull
#define OPEN_DRAIN 		1 	// Open-Drain

// OSPEED
#define LOW_SPEED		0x00
#define MID_SPEED		0x01
#define FAST_SPEED		0x02
#define HIGH_SPEED		0x03

// PIN
#define LED_PIN 		PA_5
#define BUTTON_PIN 		PC_13

#ifdef __cplusplus
 extern "C" {
#endif /* __cplusplus */
	 
void GPIO_init(PinName_t pinName, uint32_t mode);     
void GPIO_mode(PinName_t pinName, uint32_t mode);
void GPIO_ospeed(PinName_t pinName, uint32_t speed);
void GPIO_otype(PinName_t pinName, uint32_t type);
void GPIO_pupd(PinName_t pinName, uint32_t pupd);
void GPIO_write(PinName_t pinName, uint32_t Output);
uint32_t  GPIO_read(PinName_t pinName);

// ARDUINO Syntax  (Optional)
void pinMode(PinName_t pin, uint32_t mode);
void digitalWrite(PinName_t pin, uint32_t value);
uint32_t  digitalRead(PinName_t pin);

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif // __ECGPIO2_H
```




### GPIO_init\(\)

Initializes GPIO pins with default setting and Enables GPIO Clock. Mode: In/Out/AF/Analog

```c++
void GPIO_init(PinName_t pinName, uint32_t mode);  
```

**Parameters**

* **Port:**  Port Number,  GPIOA~GPIOH

* **pin**:  pin number (int) 0~15

* **mode**:   INPUT(0), OUTPUT(1),  AF(02), ANALOG (03)

  

**Example code**

```c++
GPIO_init(BUTTON_PIN, INPUT);
GPIO_init(PA_5, OUTPUT);
```



### GPIO_mode\(\)

Configures  GPIO pin modes: In/Out/AF/Analog

```c++
void GPIO_mode(PinName_t pinName, uint32_t mode);
```

**Parameters**

* **Port:**  Port Number,  GPIOA~GPIOH

* **pin**:  pin number (int) 0~15

* **mode**:   INPUT (0), OUTPUT (1),  AF(02), ANALOG (03)

  

**Example code**

```c++
GPIO_mode(GPIOA, 5, OUTPUT);
```



### GPIO_write\(\)

Write the data to GPIO pin: High, Low

```c++
void GPIO_write(PinName_t pinName, uint32_t Output);
```

**Parameters**

* **Port:**  Port Number,  GPIOA~GPIOH
* **pin**:  pin number (int) 0~15
* **output**:   LOW(0), HIGH(1)



**Example code**

```c++
GPIO_write(PA_6, LOW);
GPIO_write(PA_7, HIGH);
```



### GPIO_read\(\)

Read the data from GPIO pin

```c++
uint32_t  GPIO_read(PinName_t pinName);
```

**Parameters**

* **Port:**  Port Number,  GPIOA~GPIOH
* **pin**:  pin number (int) 0~15



**Example code**

```c++
GPIO_read(BUTTON_PIN);
```



### GPIO_ospeed\(\)

Configures  output speed of GPIO pin : Low, Mid, Fast, High

```c++
void GPIO_ospeed(PinName_t pinName, uint32_t speed);
```

**Parameters**

* **Port:**  Port Number,  GPIOA~GPIOH
* **pin**:  pin number (int) 0~15
* **speed**:   LOW_SPEED(0), MID_SPEED(1), FAST_SPEED(2) , HIGH_SPEED(3)



**Example code**

```c++
GPIO_ospeed(LED_PIN, MEDIUM_SPEED);
```



### GPIO_otype\(\)

Configures  output type of GPIO pin: Push-Pull / Open-Drain

```c++
void GPIO_otype(PinName_t pinName, uint32_t type);
```

**Parameters**

* **Port:**  Port Number,  GPIOA~GPIOH
* **pin**:  pin number (int) 0~15
* **type**:   PUSH_PULL(0), OPEN_DRAIN(1)



**Example code**

```c++
GPIO_otype(LED_PIN, OPEN_DRAIN);
```



### GPIO_pupdr\(\)

Configures  Pull-up/Pull-down mode of GPIO pin: No Pull-up, Pull-down/ Pull-up/ Pull-down/ Reserved

```c++
void GPIO_pupd(PinName_t pinName, uint32_t pupd);
```

**Parameters**

* **Port:**  Port Number,  GPIOA~GPIOH
* **pin**:  pin number (int) 0~15
* **pupd**:   NO_PUPD(0), PULL_UP(1), PULL_DOWN(2), RESERVED(3)



**Example code**

```c++
GPIO_pupd(BUTTON_PIN, PU);
```




------



## 7-Segment Display

### Header File

 `#include "ecGPIO.h"`


```c++
// FND for JKIT board
extern int numberFND[12][8];
void FND_init(PinName_t *pinFND);
void FND_select_init(PinName_t *selectFND);
void FND_display(uint8_t num);
void FND_select(uint8_t digit);
```



### FND_init\(\)
Initializes the 8 GPIO pins connected to the FND segment pins.

```c++
void FND_init(PinName_t *pinFND);
```

**Parameters**

* **pinFND**: Array of 8 PinName_t values for the FND segment pins.


**Example code**

```c++
PinName_t pinFND[8] = {
    PB_0, PB_1, PB_2, PB_3,
    PB_4, PB_5, PB_6, PB_7
};

FND_init(pinFND);
```



### FND_select_init\(\)
Initializes the GPIO pins used to select the FND digits.

```c++
void FND_select_init(PinName_t *selectFND);
```

**Parameters**

* **selectFND**: Array of 4 PinName_t values for the FND selection pins.


**Example code**

```c++
PinName_t selectFND[4] = {
    PA_10, PA_11, PC_4, PC_3
};

FND_select_init(selectFND);
```



### FND_display\(\)
Displays a number on the selected FND using the corresponding segment pattern stored in `numberFND`.

```c++
void FND_display(uint8_t num);
```

**Parameters**

* **num**: Index of the number pattern to display. The current numberFND array provides patterns for 0 to 9, decimal point, and blank.


**Example code**

```c++
FND_display(5);
```



### FND_select\(\)
Selects one FND digit from the four available FND selection pins.

```c++
void FND_select(uint8_t digit);
```

**Parameters**

* **digit**: FND digit selection number from 0 to 3.


**Example code**

```c++
FND_select(0);
FND_display(5);
```

 


------



## LAB Name

### Header File

 `#include "ecGPIO.h"`


```c++

```



### Function Name \(\)
Function description

```c++

```

**Parameters**

* **p1**: 


**Example code**

```c++

```
