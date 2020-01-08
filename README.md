# python3-lot

## Installation

```bash
sudo add-apt-repository -y ppa:loliot/ppa &&\
sudo apt install lot
```

```bash
sudo lot install
```

```bash
sudo apt update &&\
sudo apt install -y python3 python3-dev python3-pip &&\
python3 -m pip install -U --user pip setuptools
```

```bash
python3 -m pip install -U --user lot
```

## Blink example

```python
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
```

## Changelog

Ref: debian/changelog
