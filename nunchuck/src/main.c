/*
 * _24C16.c
 *
 * Created: 1/7/2012 19:11:24
 *  Author: embedds.com
 */ 
#include <stdio.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include "usart.h"
#include "twi.h"
#include <util/delay.h>
#include "nunchuck.h"
//set stream pointer
FILE usart0_str = FDEV_SETUP_STREAM(USART0SendByte, USART0ReceiveByte, _FDEV_SETUP_RW);

int main(void)
{
    //Initialize USART0
    USART0Init();
    //
    //assign our stream to standard I/O streams
    stdin=stdout=&usart0_str;
    printf("Nunchuck test\n");
    nunchuck_init();
    nuchuck_get_data();
    struct nunchuck* data = nunchuck_data();
    printf("joy: %d , %d \t", data->joy_x_axis, data->joy_y_axis);
    printf("acc: %x, %x, %x\t", data->accel_x_axis, data->accel_y_axis, data->accel_z_axis);
    printf("but: %d, %d\n", data->z_button, data->c_button);
    while(1){
        nuchuck_get_data();
        data = nunchuck_data();
        printf("joy: %d , %d \t", data->joy_x_axis, data->joy_y_axis);
        printf("acc: %x, %x, %x\t", data->accel_x_axis, data->accel_y_axis, data->accel_z_axis);
        printf("but: %d, %d\n", data->z_button, data->c_button);
        _delay_ms(250);
    }
}

