from pymongo import MongoClient
from time import sleep
import RPi.GPIO as GPIO
import math

SOL1 = 1
NUM_VALVES = 10

def mongo(sortOrder):
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
            return image
        
    except e:  
        print("Could not connect to MongoDB")
        print(e)
      
    

def main():
    print("Main running")
    GPIO.setmode(GPIO.BCM)
    GPIO.setwarnings(False)


    # desired height of water image, in meters
    imgH = 1;

    g = 9.81;

    # number of vertical divisions in image
    yDiv = 10;

    # vertical resolution of water
    yRes = imgH / yDiv;

#     times[10] = {};
    times = []
    
    ioMap = {}
    ioMap[1] = 15
    ioMap[2] = 16
    ioMap[3] = 18
    ioMap[4] = 22
    ioMap[5] = 7
    ioMap[6] = 3
    ioMap[7] = 5
    ioMap[8] = 24
    ioMap[9] = 26
    ioMap[10] = 19
    buttonTop = 4 #CHANGE THIS TO WHATEVER IT REALLY IS
#     buttonBottom = 2 #CHANGE THIS TO WHATEVER IT REALLY IS
    
  # put your setup code here, to run once:
    GPIO.setup(ioMap[1], GPIO.OUT);#3
    GPIO.setup(ioMap[2], GPIO.OUT);#4
    GPIO.setup(ioMap[3], GPIO.OUT);#5
    GPIO.setup(ioMap[4], GPIO.OUT);#6
    GPIO.setup(ioMap[5], GPIO.OUT);#7
    GPIO.setup(ioMap[6], GPIO.OUT);#8
    GPIO.setup(ioMap[7], GPIO.OUT);#9
    GPIO.setup(ioMap[8], GPIO.OUT);#10
    GPIO.setup(ioMap[9], GPIO.OUT);#11
    GPIO.setup(ioMap[10], GPIO.OUT);#12
    GPIO.setup(buttonTop, GPIO.IN, pull_up_down=GPIO.PUD_UP);
#     GPIO.setup(buttonBottom, GPIO.IN, pull_up_down=GPIO.PUD_DOWN);

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
        GPIO.output(ioMap[SOL1+j], GPIO.LOW);
    
    #image = mongo()
    
    image = []

    while (True):
        if GPIO.input(buttonTop) == GPIO.LOW:
            image = mongo(-1)
#         elif GPIO.input(buttonBottom) == GPIO.LOW:
#             image = mongo(-1)
        elif image: 
            i = yDiv-1
            while i >= 0:
                for j in range(NUM_VALVES):
                    if(image[i][j]):
                        GPIO.output(ioMap[SOL1+j], GPIO.HIGH)
                    else:
                        GPIO.output(ioMap[SOL1+j], GPIO.LOW)
                
               
                #timeIndex = i;
                #delay(times[timeIndex]);
                sleep(0.05)
                i -= 1
                
            for j in range(NUM_VALVES):
                GPIO.output(ioMap[SOL1+j], GPIO.LOW)
            sleep(0.25)
        

    # IDK what this is for ngl
    for j in range(NUM_VALVES):
        GPIO.output(ioMap[SOL1+j], GPIO.LOW);
    
#Actually run this code
main()


