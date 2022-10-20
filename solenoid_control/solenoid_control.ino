#define sol1 9

// desired height of water image, in meters
double imgH = 1;

double g = 9.81;

// number of vertical divisions in image
double yDiv = 10;

// vertical resolution of water
double yRes = imgH / yDiv;

double times[10] = {};

// Beginning of array is top of image
int pxCol[10] = {0,0,1,1,1,1,0,0,1,1};

void setup() {
  // put your setup code here, to run once:
  pinMode(sol1, OUTPUT);
  Serial.begin(9600);

  // populate times array
  for(int i = 0; i<yDiv; i++) {
    double x1 = i * yRes;
    double x2 = (i + 1) * yRes;
    double t1 = sqrt(2 * x1 / g);
    double t2 = sqrt(2 * x2 / g);;
    times[i] = t2 - t1;
  }
  
}

void loop() {
  // display a column of an image
  for(int i = 0; i<10; i++) {
    if(pxCol[i]) {
      digitalWrite(sol1, HIGH);   // open valve
    } else {
      digitalWrite(sol1, LOW);    // close valve
    }

    

    // will need a variable delay based on the value of i
    delay(times[i]);
  }
                   
  
}
