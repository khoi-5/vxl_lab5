/*
 * command_parser_fsm.c
 *
 *  Created on: Nov 25, 2025
 *      Author: Admin
 */

#include "command_parser.h"

void clearBuffer() {
   	for (int i = 0; i < MAX_SIZE_BUFFER; i++) {
		buffer[i] = 0;
	}

	index_buffer = 0;
}

void clearCMDdata() {
	for (int i = 0; i < MAX_SIZE_BUFFER; i++) {
		cmd_data[i] = 0;
	}

	cmd_index = 0;
}

void command_parser_fsm(){
	switch(status_parser) {

		case UART_WAIT:
			if (buffer[index_buffer - 1] == '!') {
				status_parser = UART_RECEIVE;
				clearCMDdata();
			}
			break;

		case UART_RECEIVE:
			if (buffer[index_buffer - 1] == '#') {
				cmd_data[cmd_index] = 0;
				status_parser = UART_WAIT;
				cmd_flag = 1;
			} else {
				cmd_data[cmd_index++] = buffer[index_buffer - 1];
			}
			break;

		default:
			break;
	}
}
