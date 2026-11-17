#if !defined MPU_H
#define MPU_H

struct i2cInterface;

uint8_t initGyro(const struct i2cInterface *i2c);
uint8_t initAccel(const struct i2cInterface *i2c);
uint8_t readGyro(const struct i2cInterface *i2c, uint8_t returnValues[6]);
uint8_t readAccel(const struct i2cInterface *i2c, uint8_t returnValues[6]);

#endif
