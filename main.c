#include<avr/io.h>
#include <stdlib.h>
#include "uart.h"
#include "I2C/i2c.h"

#define FOSC 16000000UL
#define BAUD 9600
#define MYUBRR FOSC/16/BAUD-1


void byteToHex(char *s, uint8_t b)
{
       const char *hexValues = "0123456789ABCDEF";
       s[0] = hexValues[b & 0x0F];
       s[1] = hexValues[b >> 4];
}

int main(void)
{
    USART_Init(MYUBRR);
    while(1)
    {
        start();
        setAddressWrite(0b1101000);
        requestRegister(35);
        uint8_t enable[1] = {0b11111000};
        writeBytes(enable, 1);
        stop();

        start();
        setAddressWrite(0b1101000);
        requestRegister(66);
        repeatedStart();
        setAddressRead(0b1101000); 
        uint8_t data[2];
        readBytes(data, 2);
        stop();

        char s[2];
        for (int i = 0; i < 2; i++)
        {
            byteToHex(s, data[i]);       
            USART_Transmit(s[0]);
            USART_Transmit(s[1]);
            USART_Transmit(' ');
        }
    }
}
