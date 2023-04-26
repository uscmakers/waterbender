from pymongo import MongoClient
from time import sleep
import RPi.GPIO as GPIO
import math

NUM_VALVES = 23

def mongo(sortOrder, delete=False):
    try:
        conn = MongoClient("mongodb+srv://waterbender:waterbender@cluster0.leahp9h.mongodb.net/?retryWrites=true&w=majority")
        print("Connected successfully!!!")
        
        # database name: mydatabase
        db = conn.Waterbender
          
        # Created or Switched to collection names: myTable
        collection = db.Drawings
          
        # To find() all the entries inside collection
        cursor = collection.find().sort("_id", sortOrder).limit(1)

        for record in cursor:
            print("Mongo ID: ", record["_id"])

            image = record["image"]
            for row in range(len(image)):
                print(record["image"][row])

            if delete:
                db.collection.remove({"_id":record["_id"]})

            return image
        
        return []
        
    except e:  
        print("Could not connect to MongoDB")
        print(e)
      
    

def main():
    print("Main running")
    GPIO.setmode(GPIO.BCM)
    GPIO.setwarnings(False)
    
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
    buttonTop = -1 #CHANGE THIS TO WHATEVER IT REALLY IS
    buttonBottom = -1 #CHANGE THIS TO WHATEVER IT REALLY IS
    runButton = -1
    
    # Setup Valves' IO
    for i in range(NUM_VALVES):
        GPIO.setup(ioMap[i], GPIO.OUT)
    
    # Setup Buttons IO
    GPIO.setup(buttonTop, GPIO.IN, pull_up_down=GPIO.PUD_UP);
    GPIO.setup(buttonBottom, GPIO.IN, pull_up_down=GPIO.PUD_UP);
    GPIO.setup(runButton, GPIO.IN, pull_up_down=GPIO.PUD_UP);

    # desired height of water image, in meters
    imgH = 1;

    # gravity
    g = 9.81;

    # number of vertical divisions in image
    yDiv = 10;

    # vertical resolution of water
    yRes = imgH / yDiv;

#     times[10] = {};
    times = []

    # populate times array
    for i in range(yDiv): 
        x1 = i * yRes;
        x2 = (i + 1) * yRes;
        t1 = math.sqrt(2 * x1 / g);
        t2 = math.sqrt(2 * x2 / g);
        # Delay for pixel i
        times.append(t2 - t1);
        times[i] = times[i] * 1000;

    for j in range(NUM_VALVES):
        GPIO.output(ioMap[j], GPIO.LOW);
    
    isRunning = False
    
    image = []

    while (True):
        if GPIO.input(runButton) == GPIO.LOW:
            isRunning = not isRunning
            sleep(0.1)

        if GPIO.input(buttonTop) == GPIO.LOW and isRunning:
            image = mongo(-1, False)
            sleep(1)
        elif GPIO.input(buttonBottom) == GPIO.LOW and isRunning:
            image = mongo(1, False)
            sleep(1)
        elif image and isRunning: 
            i = yDiv-1
            while i >= 0:
                for j in range(NUM_VALVES):
                    if(image[i][j]):
                        GPIO.output(ioMap[j], GPIO.HIGH)
                    else:
                        GPIO.output(ioMap[j], GPIO.LOW)
                
               
                #timeIndex = i;
                #delay(times[timeIndex]);
                sleep(0.05)
                i -= 1
                
            for j in range(NUM_VALVES):
                GPIO.output(ioMap[j], GPIO.LOW)
            sleep(0.25)

        if not isRunning:
            for j in range(NUM_VALVES):
                GPIO.output(ioMap[j], GPIO.LOW);
        
    
#Actually run this code
main()


