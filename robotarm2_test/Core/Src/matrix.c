/*
 * matrix.c
 *
 *  Created on: 2021. febr. 17.
 *      Author: borsa
 */
/*
#include "matrix.h"

unsigned char billmatrix(unsigned char *row){
	const unsigned char billtomb[12]={69, 14, 13, 11, 22, 21, 19, 38, 37, 35, 70, 67};
	u8 billgomb = 0, bill = 0, num = 0;

	switch(*row){
		case 0:
			HAL_GPIO_WritePin(KB_PC3_OUT_row1_GPIO_Port, KB_PC3_OUT_row1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(KB_PC4_OUT_row2_GPIO_Port, KB_PC4_OUT_row2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(KB_PC5_OUT_row3_GPIO_Port, KB_PC5_OUT_row3_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(KB_PC6_OUT_row4_GPIO_Port, KB_PC6_OUT_row4_Pin, GPIO_PIN_RESET);
			bill = 0x08;
		 break;

		case 1:
			HAL_GPIO_WritePin(KB_PC3_OUT_row1_GPIO_Port, KB_PC3_OUT_row1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(KB_PC4_OUT_row2_GPIO_Port, KB_PC4_OUT_row2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(KB_PC5_OUT_row3_GPIO_Port, KB_PC5_OUT_row3_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(KB_PC6_OUT_row4_GPIO_Port, KB_PC6_OUT_row4_Pin, GPIO_PIN_RESET);
			bill=0x10;
		 break;

		case 2:
			HAL_GPIO_WritePin(KB_PC3_OUT_row1_GPIO_Port, KB_PC3_OUT_row1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(KB_PC4_OUT_row2_GPIO_Port, KB_PC4_OUT_row2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(KB_PC5_OUT_row3_GPIO_Port, KB_PC5_OUT_row3_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(KB_PC6_OUT_row4_GPIO_Port, KB_PC6_OUT_row4_Pin, GPIO_PIN_RESET);
			bill = 0x20;
		 break;

		case 3:
			HAL_GPIO_WritePin(KB_PC3_OUT_row1_GPIO_Port, KB_PC3_OUT_row1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(KB_PC4_OUT_row2_GPIO_Port, KB_PC4_OUT_row2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(KB_PC5_OUT_row3_GPIO_Port, KB_PC5_OUT_row3_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(KB_PC6_OUT_row4_GPIO_Port, KB_PC6_OUT_row4_Pin, GPIO_PIN_SET);
			bill = 0x40;
		 break;
	}

	HAL_Delay(1);

	bill+=(HAL_GPIO_ReadPin(KB_PC0_IN_LEFT_GPIO_Port, KB_PC0_IN_LEFT_Pin)+(HAL_GPIO_ReadPin(KB_PC1_IN_CENTER_GPIO_Port, KB_PC1_IN_CENTER_Pin)<<1)+(HAL_GPIO_ReadPin(KB_PC2_IN_RIGHT_GPIO_Port, KB_PC2_IN_RIGHT_Pin)<<2));
	for (num=0; num<12; num++){
		if (bill==billtomb[num]){
			billgomb = num;
			*row = *row+1;
			if(*row == 4)
				*row = 0;
			return billgomb;
		}
	}
	*row = *row+1;
	if(*row == 4)
		*row = 0;

	return 12;
}*/
/*
const unsigned char billtomb1[12] = {69, 14, 13, 11, 22, 21, 19, 38, 37, 35, 70, 67};
uint8_t row = 3;
uint8_t matrix_in = 0x00;
							//		0	1	2	3	4	5	6	7	8	9	*	#

//pin: uint16_t
//port tipus: GPIO_TypeDef *

//uint16_t matrix_pin[7] = {KB_PC0_IN_LEFT_Pin...};
GPIO_TypeDef *matrix_pin[7] = {KB_PC6_OUT_row4_Pin,
								KB_PC5_OUT_row3_Pin,
								KB_PC4_OUT_row2_Pin,
								KB_PC3_OUT_row1_Pin,
								KB_PC2_IN_RIGHT_Pin,
								KB_PC1_IN_CENTER_Pin,
								KB_PC0_IN_LEFT_Pin};

GPIO_TypeDef *matrix_port[7] = {KB_PC6_OUT_row4_GPIO_Port,
								KB_PC5_OUT_row3_GPIO_Port,
								KB_PC4_OUT_row2_GPIO_Port,
								KB_PC3_OUT_row1_GPIO_Port,
								KB_PC2_IN_RIGHT_GPIO_Port,
								KB_PC1_IN_CENTER_GPIO_Port,
								KB_PC0_IN_LEFT_GPIO_Port};

//0. Init
//1. Sor cimzes
//2. Pin-ek olvasasa
//3. Ha volt bill. nyomas,akkor mi lett lenyomva?
/*	---Beolvasott ertek keresese a tombben
 *			Megtalaljuk(taroljuk, esetleg felasznaljuk) */
//4. Kovetkezo sort cimezzuk - 1.lepes
/*
void matrix_sor_cimzes(){
	uint8_t i = 3;

	while(i >= 3){
		//ha az index == row -> 1st rakunk
					//egyebkent 0-t
		if(i == row){
			HAL_GPIO_WritePin(matrix_port[i], matrix_pin[i], GPIO_PIN_SET);
		}else {
			HAL_GPIO_WritePin(matrix_port[i], matrix_pin[i], GPIO_PIN_RESET);
		}
		i--;
	}
}

void matrix_olvas(){

}

void matrix_keres(){
	uint8_t num = 0, bill = 0;
	matrix_sor_cimez();		//PORTC = row helyett
	HAL_Delay(5);			//bill = PINC helyett
	matrix_olvas();

	while(num < 12){

	}
}
*/
