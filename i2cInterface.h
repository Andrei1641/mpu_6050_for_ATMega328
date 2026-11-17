#if !defined I2C_INTERFACE_H
#define I2C_INTERFACE_H

struct i2cInterface
{
    uint8_t (*start)(void);
    uint8_t (*repeatedStart)(void);
    uint8_t (*readBytes)(uint8_t *, uint8_t);
    uint8_t (*writeBytes)(uint8_t *, uint8_t);
    uint8_t (*setAddressWrite)(uint8_t);
    uint8_t (*requestRegister)(uint8_t);
    uint8_t (*setAddressRead)(uint8_t);
    void (*stop)(void);

    //returnInfo/sendInfo, countOfReturnBytes, moduleAddress, requestReg
    uint8_t (*read)(uint8_t *, uint32_t, uint8_t, uint32_t);
    uint8_t (*write)(uint8_t *, uint32_t, uint8_t, uint32_t);
};
#endif
