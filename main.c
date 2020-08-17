#include "stm32f4xx.h"

int i=0;
int j=0;
char data[15]="abcdefghi\n";

int main(void){	

	//USART2 için clock sinyali
	RCC->APB1ENR |= RCC_APB1ENR_USART2EN;

	//A portu için clock sinyali
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
			
	//Tx PA2
	GPIOA->MODER |= GPIO_MODER_MODE2_1;
	
	//Rx PA3
	GPIOA->MODER |= GPIO_MODER_MODE3_1;
	
	//GPIOA->OSPEEDR |=GPIO_OSPEEDR_OSPEED3_1;
	//GPIOA->OSPEEDR |=GPIO_OSPEEDR_OSPEED2_1;

	GPIOA->AFR[0] |= GPIO_AFRL_AFSEL3_2 | GPIO_AFRL_AFSEL3_1 | GPIO_AFRL_AFSEL3_0;
	GPIOA->AFR[0] |= GPIO_AFRL_AFSEL2_2 | GPIO_AFRL_AFSEL2_1 | GPIO_AFRL_AFSEL2_0;
		
	//9600
	USART2->BRR =  0x683U;
		
	USART2->CR2 = USART_CR2_LINEN | USART_CR2_LBDIE;
	//TE enable
	USART2->CR1 |= USART_CR1_TE | USART_CR1_UE | USART_CR1_RXNEIE | USART_CR1_RE;

	while(1){		
		for(i=0;i<=10;i++){
			USART2->DR=data[i];
			while(!(USART2->SR & USART_SR_TXE));
			while(!(USART2->SR & USART_SR_TC));
		}
		for(j=0;j<1000000;j++);					
	}
}