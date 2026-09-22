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



## Class or Header name

### Function Name

```text

```

**Parameters**

* p1
* p2

**Example code**

```text

```
