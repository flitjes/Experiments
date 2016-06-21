/*----------------------------------------------------------------------*/
/* FAT file system sample project for FatFs            (C)ChaN, 2014    */
/*----------------------------------------------------------------------*/


#include <avr/io.h>
#include <avr/interrupt.h>
#include <string.h>
#include <stdio.h>
#include "diskio.h"
#include "ff.h"
#include "uart.h"
#include <util/delay.h>

/* Defines for UART Configurations */
#define FOSC 16000000 /* Clock speed */
#define BAUD 9600 /* Baud Rate */
#define MYUBBR FOSC/16/BAUD-1 /* Macro to calculate the correct baud rate register */

FATFS fs;
FIL fin;

char line[80];
char sec[512];
char msg[30];

int main(void)
{
	FRESULT res;
	//unsigned char status;
	UART_init( MYUBBR );
	UART_puts("UART READY MAN!\r\n");
	TCCR1B = (1 << WGM12) | (1 << CS11); //CTC div 8
	OCR1A = 0x270F; //For 10 ms
	TIMSK1 = (1 << OCIE1A); //Output compare match A int enable
	sei();
	
    /* Give Wiznet module time to intilize, this prevents the spi bus from working correctly */ 
    _delay_ms(100);    
    PSTR("%u:");
	UART_puts("Trying...\r\n");
	res = f_mount(&fs,"1", 0);
	sprintf(msg,"fmount result: %02i\r\n",res);
	UART_puts(msg);
	if (res == FR_OK) {
		UART_puts("Seems to work...\r\n");
		res = f_open(&fin, "test.txt", FA_OPEN_EXISTING | FA_READ);
		sprintf(msg,"fopen result: %02i\r\n",res);
		UART_puts(msg);
		if (res == FR_OK) {
			do {
				f_gets(line, sizeof(line), &fin);
				UART_puts(line);
				UART_put('\r');
			} while (!f_eof(&fin));
			f_close(&fin);
		}
	}
	while(1)
	{
	}
}

ISR(TIMER1_COMPA_vect) {
	disk_timerproc();
}

DWORD get_fattime (void)
{
	/* Pack date and time into a DWORD variable */
	return	  ((DWORD)(2013 - 1980) << 25)
	| ((DWORD)3 << 21)
	| ((DWORD)23 << 16)
	| ((DWORD)12 << 11)
	| ((DWORD)0 << 5)
	| ((DWORD)0 >> 1);
}
