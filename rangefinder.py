#Libraries
import RPi.GPIO as GPIO
import time

#GPIO Mode (BOARD / BCM)
GPIO.setmode(GPIO.BOARD)

#set GPIO Pins
GPIO1_TRIGGER = 2
GPIO1_ECHO = 3
GPIO2_TRIGGER = 4
GPIO2_ECHO = 17

#set GPIO direction (IN / OUT)
GPIO.setup(GPIO1_TRIGGER, GPIO.OUT)
GPIO.setup(GPIO1_ECHO, GPIO.IN)
GPIO.setup(GPIO2_TRIGGER, GPIO.OUT)
GPIO.setup(GPIO2_ECHO, GPIO.IN)

def distance1():
    # set Trigger to HIGH
    GPIO.output(GPIO1_TRIGGER, True)

    # set Trigger after 0.01ms to LOW
    time.sleep(0.00001)
    GPIO.output(GPIO1_TRIGGER, False)

    StartTime = time.time()
    StopTime = time.time()

    # save StartTime
    while GPIO.input(GPIO1_ECHO) == 0:
        StartTime = time.time()

    # save time of arrival
    while GPIO.input(GPIO1_ECHO) == 1:
        StopTime = time.time()

    # time difference between start and arrival
    TimeElapsed = StopTime - StartTime
    # multiply with the sonic speed (34300 cm/s)
    # and divide by 2, because there and back
    distance = (TimeElapsed * 34300) / 2
    return distance

def distance2():
    # set Trigger to HIGH
    GPIO.output(GPIO2_TRIGGER, True)

    # set Trigger after 0.01ms to LOW
    time.sleep(0.00001)
    GPIO.output(GPIO2_TRIGGER, False)

    StartTime = time.time()
    StopTime = time.time()

    # save StartTime
    while GPIO.input(GPIO2_ECHO) == 0:
        StartTime = time.time()

    # save time of arrival
    while GPIO.input(GPIO2_ECHO) == 1:
        StopTime = time.time()

    # time difference between start and arrival
    TimeElapsed = StopTime - StartTime
    # multiply with the sonic speed (34300 cm/s)
    # and divide by 2, because there and back
    distance = (TimeElapsed * 34300) / 2
    return distance

if __name__ == '__main__':
    try:
        while True:
            dist1 = distance1()
            print ("Measured Distance 1 = %.1f cm" % dist1)

            dist2 = distance2()
            print ("Measured Distance 2 = %.1f cm" % dist2)
            time.sleep(1)

        # Reset by pressing CTRL + C
    except KeyboardInterrupt:
        print("Measurement stopped by User")
        GPIO.cleanup()
