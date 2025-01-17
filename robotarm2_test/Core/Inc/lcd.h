/*
 * lcd.h
 *
 *  Created on: 2021. febr. 17.
 *      Author: borsa
 */

#ifndef LCD_H_
#define LCD_H_

#include "main.h"

#define LCD_E 2
#define LCD_Curzor 1
#define LCD_Curzor_blink 0
#define CURZORLEFT 0x10
#define CURZORRIGHT 0x14

void LCD_enable(void);
void LCD_init(void);
void LCD_data(uint8_t data);
void LCD_command(uint8_t cmd);
void LCD_string(char *p);
void LCD_goto(uint8_t row, uint8_t col);
void LCD_init_customcurzor(bool on, bool blink);
void LCD_test(void);
void LCD_ide(u8 sor, u8 hely);
void LCD_int(uint32_t number, int lenght,char *res);
void LCD_float(float f_number, int lenght);
void ftoa(float n, char* res, int afterpoint);
int intToStr(int x, char str[], int d);
void reverse(char* str, int len);
void LCD_int2(uint32_t number, int lenght);

#endif /* LCD_H_ */
