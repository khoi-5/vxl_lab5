/*
 * global.c
 *
 *  Created on: Nov 25, 2025
 *      Author: Admin
 */

#include "global.h"

uint8_t temp = 0;
uint8_t buffer[MAX_SIZE_BUFFER];
uint8_t index_buffer = 0;
uint8_t buffer_flag = 0;

int cmd_flag = 0;
char cmd_data[MAX_SIZE_BUFFER];
int cmd_index = 0;

int status_parser = UART_WAIT;
int status_uart = CMD_WAIT;

uint32_t ADC_value = 0;
char str[16];

ADC_HandleTypeDef hadc1;
UART_HandleTypeDef huart2;


void ADC_Transmit() {
	ADC_value = HAL_ADC_GetValue(&hadc1);
	sprintf(str, "\r\n!ADC=%ld#\r\n", ADC_value);
	HAL_UART_Transmit(&huart2 , (uint8_t*) str, strlen(str), 1000);
	setTimer(0, 3000);
}
