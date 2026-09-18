/*----------------------------------------------------------------\
@ Embedded Controller by Young-Keun Kim - Handong Global University
Author           : [Seoyoon Shin - 22400396]
Created          : 05-03-2021
Modified         : 09-18-2026 
Language/ver     : C++ in VS Code

Description      : GPIO Library. Distributed to Students for LAB_GPIO
/----------------------------------------------------------------*/


#include "ecGPIO2.h"
//#include "ecGPIO2.h"


/*---------------------------------------------------------------- 
				[EXERCISE]
---------------------------------------------------------------- */
void GPIO_init(PinName_t pinName, uint32_t mode){     
	GPIO_TypeDef * Port;
	unsigned int pin;
	ecPinmap(pinName, &Port, &pin); // 참조값으로 들어감 
	
	// mode  : Input(0), Output(1), AlterFunc(2), Analog(3)   
	if (Port == GPIOA)
		RCC_GPIOA_enable();
	if (Port == GPIOB)
		RCC_GPIOB_enable();
	
	// Make it for GPIOC, GPIOD..GPIOH   // C, D 하기 
	// [TO-DO] YOUR CODE GOES HERE !!!
	if (Port == GPIOC) 
		RCC_GPIOC_enable(); 

	if (Port == GPIOD)
		RCC_GPIOD_enable(); 

	if (Port == GPIOE)
		RCC_GPIOE_enable(); 
	// You can also make and use a more general function of
	// void RCC_GPIO_enable(GPIO_TypeDef *Port); 

	GPIO_mode(pinName, mode);
}


// GPIO Mode          : Input(00), Output(01), AlterFunc(10), Analog(11)
void GPIO_mode(PinName_t pinName, uint32_t mode){
   GPIO_TypeDef * Port;
   unsigned int pin;
   ecPinmap(pinName,&Port,&pin);

   Port->MODER &= ~(3UL<<(2*pin));      
   Port->MODER |= mode<<(2*pin);    
}


// GPIO Speed          : Low speed (00), Medium speed (01), Fast speed (10), High speed (11)
void GPIO_ospeed(PinName_t pinName, uint32_t speed){
	GPIO_TypeDef * Port;
	unsigned int pin;
	ecPinmap(pinName,&Port,&pin);

	Port->OSPEEDR &= ~(3UL<<(2*pin)); //[TO-DO] YOUR CODE GOES HERE 
	Port->OSPEEDR |=   2UL<<(2*pin);  //[TO-DO] YOUR CODE GOES HERE
}

// GPIO Output Type: Output push-pull (0, reset), Output open drain (1)
void GPIO_otype(PinName_t pinName, uint32_t type){
	GPIO_TypeDef * Port;
	unsigned int pin;
	ecPinmap(pinName,&Port,&pin);

   	Port->OTYPER &= ~(1UL<<(1*pin)); //[TO-DO] YOUR CODE GOES HERE  
	Port->OTYPER |=   1UL<<(2*pin);  //[TO-DO] YOUR CODE GOES HERE
}

// GPIO Push-Pull    : No pull-up, pull-down (00), Pull-up (01), Pull-down (10), Reserved (11)
void GPIO_pupd(PinName_t pinName, uint32_t pupd){
	GPIO_TypeDef * Port;
	unsigned int pin;
	ecPinmap(pinName,&Port,&pin);

   	Port->PUPDR &= ~(3UL<<(2*pin)); //[TO-DO] YOUR CODE GOES HERE   
	Port->PUPDR |=   2UL<<(2*pin);  //[TO-DO] YOUR CODE GOES HERE
}

void GPIO_write(PinName_t pinName, uint32_t Output){ 
	GPIO_TypeDef *port;  // 여기서 소문자 p면 아래에서도 p 대문자도 같음 
	unsigned int pin;
	ecPinmap(pinName, &port, &pin);

   	port->ODR &= 0UL<<pin;    //[TO-DO] YOUR CODE GOES HERE
	port->ODR |= Output<<pin;     // [TO-DO] YOUR CODE GOES HERE

}


uint32_t GPIO_read(PinName_t pinName){
	GPIO_TypeDef * Port;
	unsigned int pin;
	ecPinmap(pinName,&Port,&pin);

   	//[TO-DO] YOUR CODE GOES HERE 
	//[TO-DO] YOUR CODE GOES HERE
	return Port->IDR & (1UL << pin) >> pin;  //[TO-DO] YOUR CODE GOES HERE	 // return을 0으로 두면 안됨 
}


/*---------------------------------------------------------------- 
				[Optional EXERCISE]
---------------------------------------------------------------- */
// void pinMode(PinName_t pin, uint32_t mode){}   // 다하면 이거 하기 비트와이스 넣지 마시고 위에서 했던 거만 가지고 넣어도됨 
// void digitalWrite(PinName_t pin, uint32_t value){}  // 아두이노에서의 코드 
// uint32_t  digitalRead(PinName_t pin){}      // 위에서 만든 함수를 호출하면 되는거야 

/*
void pinMode(PinName_t pin, uint32_t mode) {

}
*/


// FND - JKIT board
static PinName_t _fndPins[8];
static PinName_t _fndSel[4];

//Each led that has to light up gets a 1, every other led gets a 0
//its in order  { (a,b,c,d,e,f,g,dp) }
int numberFND[12][8]={
                    {1,1,1,0,1,1,1,0},          //zero
                    {0,0,1,0,0,1,0,0},          //one
                    {1,0,1,1,1,0,1,0},          //two
                    // [YOUR CODE GOES HERE]
                    // [YOUR CODE GOES HERE]
                    // [YOUR CODE GOES HERE]
                    {0,0,0,0,0,0,0,1}          //dot
                   	{0,0,0,0,0,0,0,0}		      //blank
                  };
                  

// Initialize DOUT pins for 7 segment leds
void FND_init(PinName_t *pinFND){
	for (int i=0; i<8; i++){
		_fndPins[i] = pinFND[i];
		GPIO_init(_fndPins[i], OUTPUT);
	}
}

// Initialize select pins (FND0~FND3) as DOUT
void FND_select_init(PinName_t *selectFND){	
    // [YOUR CODE GOES HERE]
    // [YOUR CODE GOES HERE]
}

// Display a number 0 - 9 only
void FND_display(uint8_t num){
    // [YOUR CODE GOES HERE]    
    // [YOUR CODE GOES HERE]        
}

// Select display: FND0 to FND3  
void FND_select(uint8_t digit){
    // [YOUR CODE GOES HERE]    
    // [YOUR CODE GOES HERE]        
}





