from time import sleep
import RPi.GPIO as GPIO
import math

NUM_VALVES = 23

def main():
    print("Main running")
    GPIO.setmode(GPIO.BCM)
    GPIO.setwarnings(False)
    
    # rpi skips gpio 1, 14, 15, 22
    
    ioMap = {}
    ioMap[0] = 2
    ioMap[1] = 3
    ioMap[2] = 4
    ioMap[3] = 17
    ioMap[4] = 27
    ioMap[5] = 22
    ioMap[6] = 10
    ioMap[7] = 9
    ioMap[8] = 11
    ioMap[9] = 0
    ioMap[10] = 5
    ioMap[11] = 6
    ioMap[12] = 13 #Sounds funny 
    ioMap[13] = 19
    ioMap[14] = 26
    ioMap[15] = 14
    ioMap[16] = 16
    ioMap[17] = 18
    ioMap[18] = 23
    ioMap[19] = 24
    ioMap[20] = 25
    ioMap[21] = 8
    ioMap[22] = 7
    button = 1
    button2 = 12
    
  # put your setup code here, to run once:
    for i in range(NUM_VALVES):
#         print("setup: ", i)
        GPIO.setup(ioMap[i], GPIO.OUT)
    

    for j in range(NUM_VALVES):
        GPIO.output(ioMap[j], GPIO.LOW);
        
    sleep(1)
    
    while (True):
        for j in range(NUM_VALVES):
            GPIO.output(ioMap[j], GPIO.HIGH)
        sleep(1)  
          
        for j in range(NUM_VALVES):
            GPIO.output(ioMap[j], GPIO.LOW)
        sleep(1)

    
#Actually run this code
main()



