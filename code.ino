import RPi.GPIO as GPIO                                                             code.py                                                                         import RPi.GPIO as GPIO
import smbus
import time

DEVICE = 0x23
MODE = 0x10

bus = smbus.SMBus(1)

def readLight():
        data = bus.read_i2c_block_data(DEVICE, MODE)
        return (data[1] + (256 * data[0])) / 1.2

try:
        while True:
                lightLevel=readLight()
                if(lightLevel < 50):
                        print("Too dark.")
                elif(lightLevel < 100):
                        print("Dark")
                elif(lightLevel < 500):
                        print("Medium")
                elif(lightLevel < 1000):
                        print("Bright")
                else:
                        print("Too bright")
                time.sleep(0.5)

except KeyboardInterrupt:
        GPIO.cleanup()




