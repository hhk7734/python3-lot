import lot
from mpu9250_reg import *
import struct

mpu = lot.Spi("/dev/spidev0.0")

lot.init_time()
mpu.init()

mpu.write_reg(MPU9250_PWR_MGMT_1, bytes([MPU9250_H_RESET]))
lot.delay_ms(100)

mpu.write_reg(MPU9250_PWR_MGMT_1, bytes([MPU9250_CLKSEL_PLL]))
mpu.write_reg(MPU9250_USER_CTRL, bytes([MPU9250_I2C_MST_EN]))

while True:
    data = mpu.read_reg(MPU9250_ACCEL_XOUT_H, 6)

    '''
    XH, XL, YH, YL, ZH, ZL
    '>': big-endian
    'h' : int16_t
    '''
    xyz = struct.unpack('>hhh', data)
    print(xyz)

    lot.delay_ms(300)