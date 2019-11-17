# lot-python

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
sudo apt install -y swig python3 python3-dev python3-pip &&\
python3 -m pip install -U pip setuptools
```

```bash
python3 -m pip install lot
```

## Blink example

```python
import lot

LED_PIN = 7

lot.init(lot.PHY)
lot.set_pin_mode(LED_PIN, lot.OUTPUT)

while True:
    lot.digital_write(LED_PIN, lot.HIGH)
    lot.delay_ms(100)
    lot.digital_write(LED_PIN, lot.LOW)
    lot.delay_ms(100)
```
