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
//set stream pointer
FILE usart0_str = FDEV_SETUP_STREAM(USART0SendByte, USART0ReceiveByte, _FDEV_SETUP_RW);

void nunchuck_init(void);
void nunchuck_print_data();
char nunchuk_decode_byte (char x);
void nuchuck_get_data(void);
int main(void)
{
    //Initialize USART0
    USART0Init();
    //
    TWIInit();
    //assign our stream to standard I/O streams
    stdin=stdout=&usart0_str;
    printf("Nunchuck test\n");
    nunchuck_init();
    nuchuck_get_data();
    nunchuck_print_data();
    while(1){
        nuchuck_get_data();
        nunchuck_print_data();
        _delay_ms(250);
    }
}

static uint8_t nunchuck_buf[6];   // array to store nunchuck data,
uint8_t ctrlr_type[6]; 

void nuchuck_get_data(void){
    uint8_t cnt = 0;
    TWIStart();
 if (TWIGetStatus() != 0x08)
    printf("Something went wrong");     
//setup for reading
 TWIWrite((0x52 << 1) | 0x01);      // device address
 for (cnt = 0; cnt < 6; cnt++) {
     if (TWIGetStatus() != 0x28){
         if (cnt < 5)
             nunchuck_buf[cnt] = nunchuk_decode_byte(TWIReadACK()); // Should be 0x0000 A420 0101 for Classic Controller, 0x0000 A420 0000 for nunchuck
         else
             nunchuck_buf[cnt] = nunchuk_decode_byte(TWIReadNACK()); // Should be 0x0000 A420 0101 for Classic Controller, 0x0000 A420 0000 for nunchuck
   }
 }
 TWIStop();
 TWIStart();
 if (TWIGetStatus() != 0x08)
    printf("Something went wrong");     
 TWIWrite(0x52 << 1);      // device address
 TWIWrite(0x00);                    // 1st initialisation register
 TWIStop();

}

// Encode data to format that most wiimote drivers except
// only needed if you use one of the regular wiimote drivers
char nunchuk_decode_byte (char x)
{
 x = (x ^ 0x17) + 0x17;
 return x;
}

// Print the input data we have recieved
// accel data is 10 bits long
// so we read 8 bits, then we have to add
// on the last 2 bits.  That is why I
// multiply them by 2 * 2
void nunchuck_print_data()
{ 
 static int i=0;
 int joy_x_axis = nunchuck_buf[0];
 int joy_y_axis = nunchuck_buf[1];
 int accel_x_axis = nunchuck_buf[2]; // * 2 * 2; 
 int accel_y_axis = nunchuck_buf[3]; // * 2 * 2;
 int accel_z_axis = nunchuck_buf[4]; // * 2 * 2;

 int z_button = 0;
 int c_button = 0;

 // byte nunchuck_buf[5] contains bits for z and c buttons
 // it also contains the least significant bits for the accelerometer data
 // so we have to check each bit of byte outbuf[5]
 if ((nunchuck_buf[5] >> 0) & 1) 
   z_button = 1;
 if ((nunchuck_buf[5] >> 1) & 1)
   c_button = 1;

 if ((nunchuck_buf[5] >> 2) & 1) 
   accel_x_axis += 2;
 if ((nunchuck_buf[5] >> 3) & 1)
   accel_x_axis += 1;

 if ((nunchuck_buf[5] >> 4) & 1)
   accel_y_axis += 2;
 if ((nunchuck_buf[5] >> 5) & 1)
   accel_y_axis += 1;

 if ((nunchuck_buf[5] >> 6) & 1)
   accel_z_axis += 2;
 if ((nunchuck_buf[5] >> 7) & 1)
   accel_z_axis += 1;

 printf("joy: %d , %d \t", joy_x_axis, joy_y_axis);

 printf("acc: %x, %x, %x\t", accel_x_axis, accel_y_axis, accel_z_axis);

 printf("but: %d, %d\n", z_button, c_button);
}

void nunchuck_init(void){
 uint8_t cnt;
 printf("Begin nunchuck init\n");

 printf("Step 1\n");
 // init controller
 _delay_ms(1);
 TWIStart();
 if (TWIGetStatus() != 0x08)
    printf("Something went wrong");     
 TWIWrite(0x52 << 1);      // device address
 TWIWrite(0xF0);                    // 1st initialisation register
 TWIWrite(0x55);                    // 1st initialisation value
 TWIStop();
 _delay_ms(1);
 
 TWIStart();
 if (TWIGetStatus() != 0x08)
    printf("Something went wrong");     
 TWIWrite(0x52 << 1);      // device address
 TWIWrite(0xFB);                    // 2nd initialisation register
 TWIWrite(0x00);                    // 2nd initialisation value
 TWIStop();
 _delay_ms(1);
           
 printf("Step 2\n");
 // read the extension type from the register block        
 TWIStart();
 if (TWIGetStatus() != 0x08)
    printf("Something went wrong");     
 TWIWrite(0x52 << 1);      // device address
 TWIWrite(0xFA);                    // extension type register
 TWIStop();
 TWIStart();
 if (TWIGetStatus() != 0x08)
    printf("Something went wrong");     
//setup for reading
 TWIWrite((0x52 << 1) | 0x01);      // device address
 for (cnt = 0; cnt < 6; cnt++) {
     if (TWIGetStatus() != 0x28){
         if (cnt < 5)
             ctrlr_type[cnt] = TWIReadACK(); // Should be 0x0000 A420 0101 for Classic Controller, 0x0000 A420 0000 for nunchuck
         else
             ctrlr_type[cnt] = TWIReadNACK(); // Should be 0x0000 A420 0101 for Classic Controller, 0x0000 A420 0000 for nunchuck
   }
 }
 TWIStop();
 TWIStart();
 TWIWrite(0x52 << 1);      // device address
 TWIStop();
 _delay_ms(1);
           
 printf("Step 3\n");
 // send the crypto key (zeros), in 3 blocks of 6, 6 & 4.
 TWIStart();
 TWIWrite(0x52 << 1);      // device address
 TWIWrite(0xF0);                    // crypto key command register
 TWIWrite(0xAA);                    // sends crypto enable notice
 TWIStop();
 _delay_ms(1);
 TWIStart();
 TWIWrite(0x52 << 1);      // device address
 TWIWrite(0x40);                    // crypto key data address
 for (cnt = 0; cnt < 6; cnt++) {
     TWIWrite(0x00);                    // sends 1st key block (zeros)
 }
 TWIStop();
 TWIStart();
 TWIWrite(0x52 << 1);      // device address
 TWIWrite(0x40);                    // sends memory address
 for (cnt = 6; cnt < 12; cnt++) {
     TWIWrite(0x00);                    // sends 2nd key block (zeros)
 }
 TWIStop();
 TWIStart();
 TWIWrite(0x52 << 1);      // device address
 TWIWrite(0x40);                    // sends memory address
 for (cnt = 12; cnt < 16; cnt++) {
   TWIWrite(0x00);                    // sends 3rd key block (zeros)
 }
 TWIStop();
 _delay_ms(1);
 printf("Done\n");
 // end device init 
}
