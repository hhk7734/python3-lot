import lot
from mpu9250_reg import *
import struct

spi = lot.Spi("/dev/spidev0.0")

cs_pin = 11
cs = lot.Gpio(cs_pin)
cs.mode(lot.DOUT)

spi.write_reg(MPU9250_PWR_MGMT_1, bytes([MPU9250_H_RESET]), cs_pin)
lot.delay_ms(300)

spi.write_reg(MPU9250_PWR_MGMT_1, bytes([MPU9250_CLKSEL_PLL]), cs_pin)
spi.write_reg(MPU9250_USER_CTRL, bytes([MPU9250_I2C_MST_EN]), cs_pin)

while True:
    data = spi.read_reg(MPU9250_ACCEL_XOUT_H, 6, cs_pin)

    '''
    XH, XL, YH, YL, ZH, ZL
    '>': big-endian
    'h' : int16_t
    '''
    xyz = struct.unpack('>hhh', data)
    print(xyz)

    lot.delay_ms(300)
