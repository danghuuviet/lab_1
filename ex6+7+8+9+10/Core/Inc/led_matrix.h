/*
 * led_matrix.h
 *
 Created on: Nov 20, 2021
 *      Author: Admin
 */

#ifndef INC_LED_MATRIX_H_
#define INC_LED_MATRIX_H_

void get_buffer_set(void);
void set12Led(void);
// EX6
void test_led(void);
void write_led_row_col(int col, int row);
// Ex7
void clearAllClock(void);
// Ex8
void setNumberOnClock(int num);
// Ex9
void clearNumberOnClock(int num);
// Ex10
void clock_ledmatrix(void);
#endif /* INC_LED_MATRIX_H_ */
