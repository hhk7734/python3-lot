import lot
from mpu9250_reg import *
import struct

i2c = lot.I2c("/dev/i2c-2")

i2c.write_reg(MPU9250_ADDRESS, MPU9250_PWR_MGMT_1, bytes([MPU9250_H_RESET]))
lot.delay_ms(300)

i2c.write_reg(MPU9250_ADDRESS, MPU9250_PWR_MGMT_1, bytes([MPU9250_CLKSEL_PLL]))
i2c.write_reg(MPU9250_ADDRESS, MPU9250_USER_CTRL, bytes([MPU9250_I2C_MST_EN]))

while True:
    data = i2c.read_reg(MPU9250_ADDRESS, MPU9250_ACCEL_XOUT_H, 6)

    '''
    XH, XL, YH, YL, ZH, ZL
    '>': big-endian
    'h' : int16_t
    '''
    xyz = struct.unpack('>hhh', data)
    print(xyz)

    lot.delay_ms(300)
