#include <avr/io.h>
#include "I2C/i2cInterface.h"

#define MPU_ADDRESS 0b1101000

uint8_t initGyro(struct i2cInterface *i2c)
{
    uint8_t check = 0;
    uint8_t fifoEnable[1];
    check |= i2c->read(fifoEnable, 1, MPU_ADDRESS, 35);

    fifoEnable |= 0b01110000;
    check |= i2c->write(fifoEnable, 1, MPU_ADDRESS, 35);
    return check;
}

uint8_t initAccel(struct i2cInterface *i2c)
{
    uint8_t check = 0;
    uint8_t fifoEnable[1];
    check |= i2c->read(fifoEnable, 1, MPU_ADDRESS, 35);

    fifoEnable |= 0b00001000;
    check |= i2c->write(fifoEnable, 1, MPU_ADDRESS, 35);
    return check;
}

//returnValue = x 2bytes, y 2bytes, z 2bytes
uint8_t readGyro(struct i2cInterface *i2c, uint8_t returnValues[6])
{
    uint8_t check = 0;
    check |= i2c->read(returnValues, 6, MPU_ADDRESS, 67);
    return check;
}

//returnValue = x 2bytes, y 2bytes, z 2bytes
uint8_t readAccel(struct i2cInterface *i2c, uint8_t returnValues[6])
{
    uint8_t check = 0;
    check |= i2c->read(returnValues, 6, MPU_ADDRESS, 59);
    return check;
}
