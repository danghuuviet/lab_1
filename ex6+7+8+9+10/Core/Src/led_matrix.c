/*
 * led_matrix.c
 *
 Created on: Oct 10, 2022
 *      Author: Admin
 */

#include "main.h"
#include "led_matrix.h"


#define NUMBER_OF_LEDS	12

static int clock_second = 0;
static int clock_minute = 0;
static int clock_hour = 0;
static int buffer[NUMBER_OF_LEDS] = {0};

void get_buffer_set(void){
	for(int i = 0; i < NUMBER_OF_LEDS; i++){
		buffer[i] = 1;
	}
}

void write_led_row_col(int col, int row){
	 if(col == 0){
		 HAL_GPIO_WritePin(COL_PORT, COL_1,1);
		 HAL_GPIO_WritePin(COL_PORT, COL_2|COL_3|COL_4|COL_5,0);
	 }
	 else if(col == 1){
		 HAL_GPIO_WritePin(COL_PORT, COL_2,1);
		 HAL_GPIO_WritePin(COL_PORT, COL_1|COL_3|COL_4|COL_5,0);
	 }
	 else if(col == 2){
		 HAL_GPIO_WritePin(COL_PORT, COL_3,1);
		 HAL_GPIO_WritePin(COL_PORT, COL_1|COL_2|COL_4|COL_5,0);
	 }
	 else if(col == 3){
		 HAL_GPIO_WritePin(COL_PORT, COL_4,1);
		 HAL_GPIO_WritePin(COL_PORT, COL_1|COL_2|COL_3|COL_5,0);
	 }
	 else if(col == 4){
		 HAL_GPIO_WritePin(COL_PORT, COL_5,1);
		 HAL_GPIO_WritePin(COL_PORT, COL_1|COL_2|COL_3|COL_4,0);
	 }

	 if(row == 0){
		 HAL_GPIO_WritePin(ROW_PORT, ROW_6,0);
		 HAL_GPIO_WritePin(ROW_PORT, ROW_0|ROW_1|ROW_2|ROW_3|ROW_4|ROW_5,1);
	 }
	 else if(row == 1){
		 HAL_GPIO_WritePin(ROW_PORT, ROW_5,0);
		 HAL_GPIO_WritePin(ROW_PORT, ROW_0|ROW_1|ROW_2|ROW_3|ROW_4|ROW_6,1);
	 }
	 else if(row == 2){
		 HAL_GPIO_WritePin(ROW_PORT, ROW_4,0);
		 HAL_GPIO_WritePin(ROW_PORT, ROW_0|ROW_1|ROW_2|ROW_3|ROW_5|ROW_6,1);
	 }
	 else if(row == 3){
		 HAL_GPIO_WritePin(ROW_PORT, ROW_3,0);
		 HAL_GPIO_WritePin(ROW_PORT, ROW_0|ROW_1|ROW_2|ROW_4|ROW_5|ROW_6,1);
	 }
	 else if(row == 4){
		 HAL_GPIO_WritePin(ROW_PORT, ROW_2,0);
		 HAL_GPIO_WritePin(ROW_PORT, ROW_0|ROW_1|ROW_3|ROW_4|ROW_5|ROW_6,1);
	 }
	 else if(row == 5){
		 HAL_GPIO_WritePin(ROW_PORT, ROW_1,0);
		 HAL_GPIO_WritePin(ROW_PORT, ROW_0|ROW_2|ROW_3|ROW_4|ROW_5|ROW_6,1);
	 }
	 else if(row == 6){
		 HAL_GPIO_WritePin(ROW_PORT, ROW_0,0);
		 HAL_GPIO_WritePin(ROW_PORT, ROW_1|ROW_2|ROW_3|ROW_4|ROW_5|ROW_6,1);
	 }
}

void test_led(void){
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 7; j++){
			write_led_row_col(i,j);
			HAL_Delay(200);
		}
	}
}

void clearAllClock(void){
	HAL_GPIO_WritePin(COL_PORT,COL_1|COL_2|COL_3|COL_4|COL_5,0);
	for(int i = 0; i <NUMBER_OF_LEDS; i++ ){
		buffer[i] = 0;
	}
}

void setNumberOnClock(int num){
	buffer[num] = 1;
	if(num == 0){
		 HAL_GPIO_WritePin(COL_PORT, COL_2,1);
		 HAL_GPIO_WritePin(COL_PORT, COL_1|COL_3|COL_4|COL_5,0);

		 HAL_GPIO_WritePin(ROW_PORT, ROW_5,0);
		 HAL_GPIO_WritePin(ROW_PORT, ROW_0|ROW_1|ROW_2|ROW_3|ROW_4|ROW_6,1);
		 HAL_Delay(50);
	}
	else if(num == 1){
		 HAL_GPIO_WritePin(COL_PORT,  COL_3,1);
		 HAL_GPIO_WritePin(COL_PORT,  COL_1| COL_2| COL_4|COL_5,0);

		 HAL_GPIO_WritePin(ROW_PORT, ROW_5,0);
		 HAL_GPIO_WritePin(ROW_PORT, ROW_0|ROW_1|ROW_2|ROW_3|ROW_4|ROW_6,1);
		 HAL_Delay(50);
	}
	else if(num == 2){
		 HAL_GPIO_WritePin(COL_PORT, COL_4,1);
		 HAL_GPIO_WritePin(COL_PORT, COL_1|COL_3|COL_2|COL_5,0);

		 HAL_GPIO_WritePin(ROW_PORT, ROW_5,0);
		 HAL_GPIO_WritePin(ROW_PORT, ROW_0|ROW_1|ROW_2|ROW_3|ROW_4|ROW_6,1);
		 HAL_Delay(50);
	}
	else if(num == 3){
		 HAL_GPIO_WritePin(COL_PORT, COL_5,1);
		 HAL_GPIO_WritePin(COL_PORT, COL_1|COL_3|COL_4|COL_2,0);

		 HAL_GPIO_WritePin(ROW_PORT,ROW_4,0);
		 HAL_GPIO_WritePin(ROW_PORT, ROW_0|ROW_1|ROW_2|ROW_3|ROW_5|ROW_6,1);
		 HAL_Delay(50);
	}
	else if(num == 4){
		 HAL_GPIO_WritePin(COL_PORT, COL_5,1);
		 HAL_GPIO_WritePin(COL_PORT, COL_1|COL_3|COL_4|COL_2,0);

		 HAL_GPIO_WritePin(ROW_PORT,ROW_3,0);
		 HAL_GPIO_WritePin(ROW_PORT, ROW_0|ROW_1|ROW_2|ROW_4|ROW_5|ROW_6,1);
		 HAL_Delay(50);
	}
	else if(num == 5){
		 HAL_GPIO_WritePin(COL_PORT, COL_5,1);
		 HAL_GPIO_WritePin(COL_PORT, COL_1|COL_3|COL_4|COL_2,0);

		 HAL_GPIO_WritePin(ROW_PORT,ROW_2,0);
		 HAL_GPIO_WritePin(ROW_PORT, ROW_0|ROW_1|ROW_3|ROW_4|ROW_5|ROW_6,1);
		 HAL_Delay(50);
	}
	else if(num == 6){
		 HAL_GPIO_WritePin(COL_PORT, COL_4,1);
		 HAL_GPIO_WritePin(COL_PORT, COL_1|COL_3|COL_2|COL_5,0);

		 HAL_GPIO_WritePin(ROW_PORT,ROW_1,0);
		 HAL_GPIO_WritePin(ROW_PORT, ROW_0|ROW_2|ROW_3|ROW_4|ROW_5|ROW_6,1);
		 HAL_Delay(50);
	}
	else if(num == 7){
		 HAL_GPIO_WritePin(COL_PORT, COL_3,1);
		 HAL_GPIO_WritePin(COL_PORT, COL_1|COL_2|COL_4|COL_5,0);

		 HAL_GPIO_WritePin(ROW_PORT,ROW_1,0);
		 HAL_GPIO_WritePin(ROW_PORT, ROW_0|ROW_2|ROW_3|ROW_4|ROW_5|ROW_6,1);
		 HAL_Delay(50);
	}
	else if(num == 8){
		 HAL_GPIO_WritePin(COL_PORT, COL_2,1);
		 HAL_GPIO_WritePin(COL_PORT, COL_1|COL_3|COL_4|COL_5,0);

		 HAL_GPIO_WritePin(ROW_PORT,ROW_1,0);
		 HAL_GPIO_WritePin(ROW_PORT, ROW_0|ROW_2|ROW_3|ROW_4|ROW_5|ROW_6,1);
		 HAL_Delay(50);
	}
	else if(num == 9){
		 HAL_GPIO_WritePin(COL_PORT, COL_1,1);
		 HAL_GPIO_WritePin(COL_PORT, COL_2|COL_3|COL_4|COL_5,0);

		 HAL_GPIO_WritePin(ROW_PORT,ROW_2,0);
		 HAL_GPIO_WritePin(ROW_PORT, ROW_0|ROW_1|ROW_3|ROW_4|ROW_5|ROW_6,1);
		 HAL_Delay(50);
	}
	else if(num == 10){
		HAL_GPIO_WritePin(COL_PORT, COL_1,1);
		HAL_GPIO_WritePin(COL_PORT, COL_2|COL_3|COL_4|COL_5,0);

		 HAL_GPIO_WritePin(ROW_PORT,ROW_3,0);
		 HAL_GPIO_WritePin(ROW_PORT, ROW_0|ROW_1|ROW_2|ROW_4|ROW_5|ROW_6,1);
		 HAL_Delay(50);
	}
	else if(num == 11){
		HAL_GPIO_WritePin(COL_PORT, COL_1,1);
		HAL_GPIO_WritePin(COL_PORT, COL_2|COL_3|COL_4|COL_5,0);

		 HAL_GPIO_WritePin(ROW_PORT,ROW_4,0);
		 HAL_GPIO_WritePin(ROW_PORT, ROW_0|ROW_1|ROW_2|ROW_3|ROW_5|ROW_6,1);
		 HAL_Delay(50);
	}
}

void clearNumberOnClock(int num){
	buffer[num] = 0;
}

void set12Led(void){
	int period = 100;
	static long long initial = 0;
	if(HAL_GetTick()-initial < period){
		HAL_GPIO_WritePin(COL_PORT, COL_1,1);
		HAL_GPIO_WritePin(COL_PORT, COL_2|COL_3|COL_4|COL_5,0);
		HAL_GPIO_WritePin(ROW_PORT, ROW_0|ROW_1|ROW_5|ROW_6,1);

		if(buffer[11] == 1) HAL_GPIO_WritePin(ROW_PORT,ROW_4, 0);
		else HAL_GPIO_WritePin(ROW_PORT,ROW_4,1);

		if(buffer[10] == 1)	HAL_GPIO_WritePin(ROW_PORT,ROW_3,0);
		else HAL_GPIO_WritePin(ROW_PORT,ROW_3,1);

		if(buffer[9] == 1)	HAL_GPIO_WritePin(ROW_PORT,ROW_2,0);
		else HAL_GPIO_WritePin(ROW_PORT,ROW_2,1);
	}
	else if(HAL_GetTick()-initial < period*2){
		HAL_GPIO_WritePin(COL_PORT, COL_2, 1);
		HAL_GPIO_WritePin(COL_PORT, COL_1|COL_3|COL_4|COL_5,0);
		HAL_GPIO_WritePin(ROW_PORT, ROW_0|ROW_2|ROW_3|ROW_4|ROW_6,1);

		if(buffer[0] == 1) 	HAL_GPIO_WritePin(ROW_PORT,ROW_5,0);
		else HAL_GPIO_WritePin(ROW_PORT,ROW_5,1);

		if(buffer[8] == 1)	HAL_GPIO_WritePin(ROW_PORT,ROW_1,0);
		else HAL_GPIO_WritePin(ROW_PORT,ROW_1,1);
	}
	else if(HAL_GetTick()-initial < period*3){
		HAL_GPIO_WritePin(COL_PORT, COL_3,1);
		HAL_GPIO_WritePin(COL_PORT, COL_1|COL_2|COL_4|COL_5,0);
		HAL_GPIO_WritePin(ROW_PORT, ROW_0|ROW_2|ROW_3|ROW_4|ROW_6,1);

		if(buffer[1] == 1)	HAL_GPIO_WritePin(ROW_PORT,ROW_5,0);
		else HAL_GPIO_WritePin(ROW_PORT,ROW_5,1);

		if(buffer[7] == 1)	HAL_GPIO_WritePin(ROW_PORT,ROW_1,0);
		else HAL_GPIO_WritePin(ROW_PORT,ROW_1,1);
	}
	else if(HAL_GetTick()-initial < period*4){
		HAL_GPIO_WritePin(COL_PORT, COL_4,1);
		HAL_GPIO_WritePin(COL_PORT, COL_1|COL_2|COL_3|COL_5,0);
		HAL_GPIO_WritePin(ROW_PORT, ROW_0|ROW_2|ROW_3|ROW_4|ROW_6,1);

		if(buffer[2] == 1) 	HAL_GPIO_WritePin(ROW_PORT,ROW_5,0);
		else HAL_GPIO_WritePin(ROW_PORT,ROW_5,1);

		if(buffer[6] == 1)	HAL_GPIO_WritePin(ROW_PORT,ROW_1,0);
		else HAL_GPIO_WritePin(ROW_PORT,ROW_1,1);
	}
	else if(HAL_GetTick()-initial < period*5){
		HAL_GPIO_WritePin(COL_PORT, COL_5,1);
		HAL_GPIO_WritePin(COL_PORT, COL_1|COL_2|COL_3|COL_4,0);
		HAL_GPIO_WritePin(ROW_PORT, ROW_0|ROW_1|ROW_5|ROW_6,1);

		if(buffer[3] == 1) HAL_GPIO_WritePin(ROW_PORT,ROW_4, 0);
		else HAL_GPIO_WritePin(ROW_PORT,ROW_4,1);

		if(buffer[4] == 1)	HAL_GPIO_WritePin(ROW_PORT,ROW_3,0);
		else HAL_GPIO_WritePin(ROW_PORT,ROW_3,1);

		if(buffer[5] == 1)	HAL_GPIO_WritePin(ROW_PORT,ROW_2,0);
		else HAL_GPIO_WritePin(ROW_PORT,ROW_2,1);
	}
	else initial = HAL_GetTick();
}

void clock_ledmatrix(void){
	static long long timer = 0;
	if(HAL_GetTick()-timer >= 500){
		clock_second += 1;
		timer = HAL_GetTick();
	}
	if(clock_second >= 12){
		clock_second = 0;
		clock_minute += 1;
	}
	if(clock_minute >= 12){
		clock_minute = 0;
		clock_hour += 1;
	}
	if(clock_hour >= 12){
		clock_hour = 0;
	}
	clearAllClock();
	setNumberOnClock(clock_second);
	setNumberOnClock(clock_minute);
	setNumberOnClock(clock_hour);
}
