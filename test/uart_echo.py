import lot

uart = lot.Uart("/dev/ttyS1")

uart.transmit("hello world\r\n".encode())

while True:
    if uart.available() != 0:
        uart.transmit(uart.receive())
