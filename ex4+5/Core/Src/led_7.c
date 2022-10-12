/*
 * led_7.c
 *
 Created on: Oct 7, 2022
 *      Author: Admin
 */

#include "main.h"
#include "led_7.h"

#define NUMBER_OF_DECIMAL_DIGITS			10
#define	NUMBER_OF_SEVEN_SEGMENT_LEDS		1

static uint8_t sevenSegmentLEDConversion[NUMBER_OF_DECIMAL_DIGITS] = {0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90};
static uint8_t sevenSegmentLEDBuffer;
uint8_t update_seven_segment_led_buffer(uint8_t val){
	if(val > NUMBER_OF_DECIMAL_DIGITS) return 0;
	sevenSegmentLEDBuffer = val;
	return 1;
}
void seven_segment_led_driver(void){
	uint8_t temp = sevenSegmentLEDConversion[sevenSegmentLEDBuffer];
		if(temp & 0x01){
			HAL_GPIO_WritePin(SEVEN_SEGMENT_PORT, SEVEN_SEGMENT_A, SET);
		} else{
			HAL_GPIO_WritePin(SEVEN_SEGMENT_PORT, SEVEN_SEGMENT_A, RESET);
		}

		if(temp & 0x02){
			HAL_GPIO_WritePin(SEVEN_SEGMENT_PORT, SEVEN_SEGMENT_B, SET);
		} else{
			HAL_GPIO_WritePin(SEVEN_SEGMENT_PORT, SEVEN_SEGMENT_B, RESET);
		}

		if(temp & 0x04){
			HAL_GPIO_WritePin(SEVEN_SEGMENT_PORT, SEVEN_SEGMENT_C, SET);
		} else{
			HAL_GPIO_WritePin(SEVEN_SEGMENT_PORT, SEVEN_SEGMENT_C, RESET);
		}

		if(temp & 0x08){
			HAL_GPIO_WritePin(SEVEN_SEGMENT_PORT, SEVEN_SEGMENT_D, SET);
		} else{
			HAL_GPIO_WritePin(SEVEN_SEGMENT_PORT, SEVEN_SEGMENT_D, RESET);
		}
		if(temp & 0x10){
			HAL_GPIO_WritePin(SEVEN_SEGMENT_PORT, SEVEN_SEGMENT_E, SET);
		} else{
			HAL_GPIO_WritePin(SEVEN_SEGMENT_PORT, SEVEN_SEGMENT_E, RESET);
		}

		if(temp & 0x20){
			HAL_GPIO_WritePin(SEVEN_SEGMENT_PORT, SEVEN_SEGMENT_F, SET);
		} else{
			HAL_GPIO_WritePin(SEVEN_SEGMENT_PORT, SEVEN_SEGMENT_F, RESET);
		}

		if(temp & 0x40){ //true or false?
	 		HAL_GPIO_WritePin(SEVEN_SEGMENT_PORT, SEVEN_SEGMENT_G, SET);
		} else{
			HAL_GPIO_WritePin(SEVEN_SEGMENT_PORT, SEVEN_SEGMENT_G, RESET);
		}
}
void test_seven_segment_led(int counter){
	update_seven_segment_led_buffer(counter);
	seven_segment_led_driver();
	HAL_Delay(1000);
}
