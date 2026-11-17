#include <avr/io.h>
#include "../i2cInterface.h"

#define MPU_ADDRESS 0b1101000

uint8_t initGyro(const struct i2cInterface *i2c)
{
    uint8_t check = 0;
    uint8_t fifoEnable;
    check |= i2c->read(&fifoEnable, 1, MPU_ADDRESS, 35);

    fifoEnable |= 0b01110000;
    check |= i2c->write(&fifoEnable, 1, MPU_ADDRESS, 35);
    return check;
}

uint8_t initAccel(const struct i2cInterface *i2c)
{
    uint8_t check = 0;
    uint8_t fifoEnable;
    check |= i2c->read(&fifoEnable, 1, MPU_ADDRESS, 35);

    fifoEnable |= 0b00001000;
    check |= i2c->write(&fifoEnable, 1, MPU_ADDRESS, 35);
    return check;
}

//returnValue = x 2bytes, y 2bytes, z 2bytes
uint8_t readGyro(const struct i2cInterface *i2c, uint8_t returnValues[6])
{
    uint8_t check = 0;
    check |= i2c->read(returnValues, 6, MPU_ADDRESS, 67);
    return check;
}

//returnValue = x 2bytes, y 2bytes, z 2bytes
uint8_t readAccel(const struct i2cInterface *i2c, uint8_t returnValues[6])
{
    uint8_t check = 0;
    check |= i2c->read(returnValues, 6, MPU_ADDRESS, 59);
    return check;
}
