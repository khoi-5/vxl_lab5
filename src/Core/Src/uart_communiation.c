/*
 * uart_communiation_fsm.c
 *
 *  Created on: Nov 25, 2025
 *      Author: Admin
 */

#include "uart_communiation.h"
#include "softwareTimer.h"
#include <string.h>


void uart_communication_fsm() {
	switch (status_uart) {

		case CMD_WAIT:
			HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, 1);

			if (cmd_flag == 1 ) {
			    cmd_flag = 0;

				if (strcmp(cmd_data, "RST") == 0 ) {
				    status_uart = CMD_PROCESS;
				    ADC_Transmit();
				}
			}

			break;

		case CMD_PROCESS:
			HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, 0);

			if (timer_flag[0] == 1) {
				ADC_Transmit();
			}

			if (cmd_flag == 1) {
				cmd_flag = 0;

				if (strcmp(cmd_data, "RST") == 0 ) {
					ADC_Transmit();
				}

				if (strcmp(cmd_data, "OK") == 0 ) {
					status_uart = CMD_WAIT;
				}
			}

			break;
	}
}

