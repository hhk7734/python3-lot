'''
MIT License

Copyright (c) 2019 Hyeonki Hong <hhk7734@gmail.com>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
'''

from lot._lot import *


class Uart:
    def __init__(self, *arg):
        self.this = new_Uart(*arg)

    def __del__(self):
        delete_Uart(self.this)

    def init(self, *arg):
        Uart_init(self.this, *arg)

    def set_baudrate(self, *arg):
        Uart_set_baudrate(self.this, *arg)

    def set_mode(self, *arg):
        Uart_set_mode(self.this, *arg)

    def available(self, *arg):
        return available(self.this, *arg)

    def put(self, *arg):
        Uart_put(self.this, *arg)

    def write(self, *arg):
        Uart_write(self.this, *arg)

    def transmit(self, *arg):
        Uart_transmit(self.this, *arg)

    def receive(self, *arg):
        return Uart_receive(self.this, *arg)


class Spi:
    def __init__(self, *arg):
        self.this = new_Spi(*arg)

    def __del__(self):
        delete_Spi(self.this)

    def init(self, *arg):
        Spi_init(self.this, *arg)

    def set_clock(self, *arg):
        Spi_set_clock(self.this, *arg)

    def set_mode(self, *arg):
        Spi_set_mode(self.this, *arg)

    def set_bit_order(self, *arg):
        Spi_set_bit_order(self.this, *arg)

    def transceive(self, *arg):
        return Spi_transceive(self.this, *arg)

    def write_reg(self, *arg):
        Spi_write_reg(self.this, *arg)

    def read_reg(self, *arg):
        return Spi_read_reg(self.this, *arg)


class I2c:
    def __init__(self, *arg):
        self.this = new_I2c(self, *arg)

    def __del__(self):
        delete_I2c(self.this)

    def init(self, *arg):
        I2c_init(self.this, *arg)

    def set_clock(self, *arg):
        I2c_set_clock(self.this, *arg)

    def transmit(self, *arg):
        I2c_transmit(self.this, *arg)

    def receive(self, *arg):
        return I2c_receive(self.this, *arg)

    def write_reg(self, *arg):
        I2c_write_reg(self.this, *arg)

    def read_reg(self, *arg):
        return I2c_read_reg(self.this, *arg)
