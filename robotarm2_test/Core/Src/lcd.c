/*
 * lcd.c
 *
 *  Created on: 2021. febr. 17.
 *      Author: borsa
 */

#include "lcd.h"

void LCD_int(uint32_t number, int lenght, char *res){
	unsigned char stringecske[lenght];
	//sprintf(stringecske, "%d",number);
	sprintf(res, "%d",number);
	//LCD_string(stringecske);
}

void LCD_int2(uint32_t number, int lenght){
	unsigned char stringecske[lenght];
	sprintf(stringecske, "%d",number);
	//sprintf(res, "%d",number);
	LCD_string(stringecske);
}

void reverse(char* str, int len)
{
    int i = 0, j = len - 1, temp;
    while (i < j) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

int intToStr(int x, char str[], int d) {
    int i = 0;
    while (x) {
        str[i++] = (x % 10) + '0';
        x = x / 10;
    }
    // If number of digits required is more, then
    // add 0s at the beginning
    while (i < d)
        str[i++] = '0';

    reverse(str, i);
    str[i] = '\0';

    return i;
}

void ftoa(float n, char* res, int afterpoint) {
    // Extract integer part
    int ipart = (int)n;

    // Extract floating part
    float fpart = n - (float)ipart;

    // convert integer part to string
    int i = intToStr(ipart, res, 0);

    // check for display option after point
    if (afterpoint != 0) {
        res[i] = '.'; // add dot

        // Get the value of fraction part upto given no.
        // of points after dot. The third parameter
        // is needed to handle cases like 233.007
        fpart = fpart * pow(10, afterpoint);

        intToStr((int)fpart, res + i + 1, afterpoint);
    }
}

void LCD_ide(u8 sor, u8 hely){
	if(sor>=2){
		sor = sor-2;
		hely = hely+16;
	}
	LCD_command((1<<7)|(sor<<6)|hely);

}

void LCD_test(){
	LCD_goto(0,0);
	LCD_string("Menjen - Menjen");
	LCD_goto(1,0);
	LCD_string("Menjen - Menjen");
	HAL_Delay(1000);
	LCD_command(0x01);
}

void LCD_string(char *p){
	while(*p ){
		LCD_data(*p); // lehet igy is LCD_data(*p++)
		p++; //l�p�nk mindig tovabb
	}
}

void LCD_goto(uint8_t row, uint8_t col){
	switch(row){
		case 0:
			LCD_command(0x80);
			for(uint8_t i = col; i--; i>0){
				LCD_command(0x14);
			}
			break;

		case 1:
			LCD_command(0xC0);
			for(uint8_t i = col; i--; i>0){
				LCD_command(0x14);
			}
			break;

		default:
			break;
	}
}

void LCD_enable(void){
	//LCD_E 0-1-0 atmenetet kell megcsinalnunk
	HAL_GPIO_WritePin(LCD_E_GPIO_Port,LCD_E_Pin,RESET);
	//kell bele kesleltetes is , adatlapb�l kiolvasni mi�rt
	HAL_Delay(5);
	HAL_GPIO_WritePin(LCD_E_GPIO_Port,LCD_E_Pin,SET);
	HAL_Delay(5);
	HAL_GPIO_WritePin(LCD_E_GPIO_Port,LCD_E_Pin,RESET);
	HAL_Delay(5);
}

void LCD_command(uint8_t cmd){
	//Rs -> 0-ba kell rakni,
	// R/W(neg) -> 0-ba kell rakni, mert irunk ------------> de ez mar f�ld�n van
	//1. felso 4 adatbit
	HAL_GPIO_WritePin(LCD_Rs_GPIO_Port,LCD_Rs_Pin,RESET);

	HAL_GPIO_WritePin(LCD_DATA_7_GPIO_Port,LCD_DATA_7_Pin, (cmd>>7)&0x01);
	HAL_GPIO_WritePin(LCD_DATA_6_GPIO_Port,LCD_DATA_6_Pin, (cmd>>6)&0x01);
	HAL_GPIO_WritePin(LCD_DATA_5_GPIO_Port,LCD_DATA_5_Pin, (cmd>>5)&0x01);
	HAL_GPIO_WritePin(LCD_DATA_4_GPIO_Port,LCD_DATA_4_Pin, (cmd>>4)&0x01);


	//enable k�zte, meg utana

	LCD_enable();

	//2. also 4 adatbit

	HAL_GPIO_WritePin(LCD_DATA_7_GPIO_Port,LCD_DATA_7_Pin, (cmd>>3)&0x01);
	HAL_GPIO_WritePin(LCD_DATA_6_GPIO_Port,LCD_DATA_6_Pin, (cmd>>2)&0x01);
	HAL_GPIO_WritePin(LCD_DATA_5_GPIO_Port,LCD_DATA_5_Pin, (cmd>>1)&0x01);
	HAL_GPIO_WritePin(LCD_DATA_4_GPIO_Port,LCD_DATA_4_Pin, (cmd>>0)&0x01);

	//enable

	LCD_enable();
}

//LCD_data kin�zetre ugyan az mint command, csak itt set van  es mast shiftel�nk
void LCD_data(uint8_t data){
	//Rs -> 0-ba kell rakni,
	// R/W(neg) -> 0-ba kell rakni, mert irunk ------------> de ez mar f�ld�n van
	//1. felso 4 adatbit

	HAL_GPIO_WritePin(LCD_Rs_GPIO_Port,LCD_Rs_Pin,SET);

	HAL_GPIO_WritePin(LCD_DATA_7_GPIO_Port,LCD_DATA_7_Pin, (data>>7)&0x01);
	HAL_GPIO_WritePin(LCD_DATA_6_GPIO_Port,LCD_DATA_6_Pin, (data>>6)&0x01);
	HAL_GPIO_WritePin(LCD_DATA_5_GPIO_Port,LCD_DATA_5_Pin, (data>>5)&0x01);
	HAL_GPIO_WritePin(LCD_DATA_4_GPIO_Port,LCD_DATA_4_Pin, (data>>4)&0x01);

	//enable k�zte, meg utana

	LCD_enable();

	//2. also 4 adatbit

	HAL_GPIO_WritePin(LCD_DATA_7_GPIO_Port,LCD_DATA_7_Pin, (data>>3)&0x01);
	HAL_GPIO_WritePin(LCD_DATA_6_GPIO_Port,LCD_DATA_6_Pin, (data>>2)&0x01);
	HAL_GPIO_WritePin(LCD_DATA_5_GPIO_Port,LCD_DATA_5_Pin, (data>>1)&0x01);
	HAL_GPIO_WritePin(LCD_DATA_4_GPIO_Port,LCD_DATA_4_Pin, (data>>0)&0x01);

	//enable

	LCD_enable();
}

void LCD_init(void){
	//eroszakolos, 4 bites technika
		//4 bites mod - 2 sor - 5*8 pixel - lcd on - cursor on - cursor blink on
	HAL_Delay(15);
	LCD_command(0x20);

	LCD_enable();
	LCD_enable();
	LCD_enable();

	//azert kell 3szor mert nem tudjuk milyen modban van
	LCD_command(0x28);		//mod allitas : 4bit, 2 sor, 5*8 pixel
	LCD_command(0x28);
	LCD_command(0x28);

	LCD_command(0x01);		//lcd clear
	LCD_command(0x02); 		//lcd home

	LCD_command(0x0F);		//lcd - kurzor blinking

}

void LCD_init_customcurzor(bool on, bool blink){
	//eroszakolos, 4 bites technika
		//4 bites mod - 2 sor - 5*8 pixel - lcd on - cursor on - cursor blink on
	HAL_Delay(15);
	LCD_command(0x20);

	LCD_enable();
	LCD_enable();
	LCD_enable();

	//azert kell 3szor mert nem tudjuk milyen modban van
	LCD_command(0x28);		//mod allitas : 4bit, 2 sor, 5*8 pixel
	LCD_command(0x28);
	LCD_command(0x28);

	LCD_command(0x01);		//lcd clear
	LCD_command(0x02); 		//lcd home

	//LCD_command(0x0F);		//lcd - kurzor blinking
	LCD_command(0x08|(1<<LCD_E)|(on<<LCD_Curzor)|(blink<<LCD_Curzor_blink));
}

