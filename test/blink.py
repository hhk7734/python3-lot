import lot
import sys

LED_PIN = 13

if len(sys.argv) > 1:
    LED_PIN = int(sys.argv[1])

lot.init_time()
led = lot.Gpio(LED_PIN)
led.mode(lot.DOUT)

while True:
    led.toggle()
    lot.delay_ms(200)
