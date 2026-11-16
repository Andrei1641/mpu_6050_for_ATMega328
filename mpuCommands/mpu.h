#if !defined MPU_H
#define MPU_H

struct i2cInterface;

uint8_t initGyro(struct i2cInterface *i2c);
uint8_t initAccel(struct i2cInterface *i2c);
uint8_t readGyro(struct i2cInterface *i2c, uint8_t returnValues[6]);
uint8_t readAccel(struct i2cInterface *i2c, uint8_t, returnValues[6]);

#endif
