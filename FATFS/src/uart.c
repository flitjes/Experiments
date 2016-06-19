/*
** This is a simple set of UART routines for debug purposes
** It's Tx only and the baud rate is fixed (see UART_init)
*/

#include "uart.h"

// Just enable the UART Tx and set baud rate for 38400 on 3.6864MHz (STK500)
void UART_init( unsigned int ubrr)
{
	/*Set baud rate */
	UBRR0H = (unsigned char)(ubrr>>8);
	UBRR0L = (unsigned char)ubrr;
	/* Enable receiver and transmitter */
	UCSR0B = (1<<TXEN0);
	/* Set frame format: 8data, 1stop bit */
	UCSR0C = (3<<UCSZ00); // (1<<USBS0)|(3<<UCSZ00); Used for 2 stop bits
}

// The classic Tx one character routine
void UART_put(uint8_t c) {
	while (!(UCSR0A & (1 << UDRE0)));
	UDR0 = c;
}

// classic Tx a C-string routine
void UART_puts(const char * str) {
	while (*str) {
		UART_put(*str++);
	}
}

// Just outputs "\r\n"
void UART_newline(void){
	UART_put('\r');
	UART_put('\n');
}

// used in printing a 2 digit hex number, outputs one of the two nibbles
// the parameter is expected to be 0..F
void UART_putnibble(uint8_t c) {
	if (c < 10) {
		UART_put('0' + c);
	}
	else {
		UART_put('A' + c - 10);
	}
}

// print both nibbles of an 8 bit hex number
void UART_puthex(uint8_t c) {
	UART_putnibble(c >> 4);
	UART_putnibble(c & 0x0F);
}

// print both bytes of a 16 bit hex number
void UART_puthex16(uint16_t n) {
	UART_puthex(n >> 8);
	UART_puthex(n & 0xFF);
}

// this expect the first parameter to be a string in dlash (that is PSTR())
// and then the second to be a value to print out in hex. typically used in
// the form UART_putsP(PSTR("SecPerClus = "), SecPerClus)
void UART_putsP(const char * str, uint16_t n) {
	while (pgm_read_byte(str) != 0) {
		UART_put(pgm_read_byte(str++));
	}
	UART_puthex16(n);
	UART_newline();
}

// dump the 512 bytes at the given address in the form:
// CD BF 10 E0 A0 E6 B0 E0  E4 E5 F0 E0 02 C0 05 90   Ϳ ������� � �
void UART_dumpsector(uint8_t * Buff) {
	for (uint16_t i=0; i<512; i++) {
		if ((i % 16) == 0) {
			UART_put(' ');
			for(uint16_t j=(i -16); j<=i; j++) {
				UART_put(((Buff[j]>=(uint8_t)32) && (Buff[j]<(uint8_t)127)) ? Buff[j] : '.');
			}
			UART_newline();
		}
		UART_puthex(Buff[i]);
		UART_put(' ');
	}
	UART_newline();
}
