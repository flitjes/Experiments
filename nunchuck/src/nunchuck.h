#ifndef NUNCHUCK_H_
#define NUNCHUCK_H_

#include <util/delay.h>
#include "usart.h"
#include "twi.h"
struct nunchuck{
    int joy_x_axis;
    int joy_y_axis;
    int accel_x_axis; 
    int accel_y_axis;
    int accel_z_axis;
    int z_button;
    int c_button;
};

void nunchuck_init(void);
struct nunchuck* nunchuck_data();
char nunchuk_decode_byte (char x);
void nuchuck_get_data(void);

#endif
