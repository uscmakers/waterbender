#define SOL1 3
#define NUM_VALVES 10

// desired height of water image, in meters
double imgH = 1;

double g = 9.81;

// number of vertical divisions in image
double yDiv = 10;

// vertical resolution of water
double yRes = imgH / yDiv;

double times[10] = {};

/* DISPLAY A COLUMN OF PIXELS */
// Beginning of array is bottom of image
int pxCol[10] = {1,0,0,0,0,0,0,0,0,0};


int pxMatrixLines[10][10] = {
{1,1,1,1,1,1,1,1,1,1},
{0,0,0,0,0,0,0,0,0,0},
{1,1,1,1,1,1,1,1,1,1},
{0,0,0,0,0,0,0,0,0,0},
{1,1,1,1,1,1,1,1,1,1},
{0,0,0,0,0,0,0,0,0,0},
{1,1,1,1,1,1,1,1,1,1},
{0,0,0,0,0,0,0,0,0,0},
{1,1,1,1,1,1,1,1,1,1},
{0,0,0,0,0,0,0,0,0,0}
};


int pxMatrix[10][10] = {
{1,0,0,0,0,0,0,0,0,0},
{0,1,0,0,0,0,0,0,0,0},
{0,0,1,0,0,0,0,0,0,0},
{0,0,0,1,0,0,0,0,0,0},
{0,0,0,0,1,0,0,0,0,0},
{0,0,0,0,0,1,0,0,0,0},
{0,0,0,0,0,0,1,0,0,0},
{0,0,0,0,0,0,0,1,0,0},
{0,0,0,0,0,0,0,0,1,0},
{0,0,0,0,0,0,0,0,0,1}
};


int pxMatrix1[10][10] = {
{0,1,0,0,0,0,0,0,1,0},
{0,1,0,0,0,0,0,0,1,0},
{0,1,0,0,0,0,0,0,1,0},
{0,1,0,0,0,0,0,0,1,0},
{0,1,0,0,0,0,0,0,1,0},
{0,1,0,0,0,0,0,0,1,0},
{0,1,0,0,0,0,0,0,1,0},
{0,0,1,0,0,0,0,1,0,0},
{0,0,0,1,1,1,1,0,0,0},
{0,0,0,0,0,0,0,0,0,0}
};

int pxMatrix1_1[10][10] = {
{1,1,0,0,0,0,0,0,1,1},
{1,1,0,0,0,0,0,0,1,1},
{1,1,0,0,0,0,0,0,1,1},
{1,1,0,0,0,0,0,0,1,1},
{1,1,0,0,0,0,0,0,1,1},
{1,1,0,0,0,0,0,0,1,1},
{1,1,0,0,0,0,0,0,1,1},
{0,1,1,0,0,0,0,1,1,0},
{0,0,1,1,1,1,1,1,0,0},
{0,0,0,1,1,1,1,0,0,0}
};

int pxMatrix2[10][10] = {
{0,0,0,0,1,1,1,1,1,0},
{0,0,0,1,0,0,0,0,0,0},
{0,0,1,0,0,0,0,0,0,0},
{0,0,0,1,0,0,0,0,0,0},
{0,0,0,0,1,0,0,0,0,0},
{0,0,0,0,0,1,0,0,0,0},
{0,0,0,0,0,0,1,0,0,0},
{0,0,0,0,0,0,0,1,0,0},
{0,0,0,0,0,0,0,0,1,0},
{0,0,1,1,1,1,1,1,0,0}
};

int pxMatrix3[10][10] = {
{0,0,0,1,1,1,1,1,1,0},
{0,0,1,0,0,0,0,0,0,0},
{0,1,0,0,0,0,0,0,0,0},
{0,1,0,0,0,0,0,0,0,0},
{0,1,0,0,0,0,0,0,0,0},
{0,1,0,0,0,0,0,0,0,0},
{0,1,0,0,0,0,0,0,0,0},
{0,1,0,0,0,0,0,0,0,0},
{0,0,1,0,0,0,0,0,0,0},
{0,0,0,1,1,1,1,1,1,0}
};



void setup() {
  // put your setup code here, to run once:
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  
  Serial.begin(9600);

  // populate times array
  for(int i = 0; i<yDiv; i++) {
    double x1 = i * yRes;
    double x2 = (i + 1) * yRes;
    double t1 = sqrt(2 * x1 / g);
    double t2 = sqrt(2 * x2 / g);
    // Delay for pixel i
    times[i] = t2 - t1;
    times[i] = times[i] * 1000;
    Serial.print("div ");
    Serial.print(i);
    Serial.print(": ");
    Serial.println(times[i]);
  }
  for(int j = 0; j<NUM_VALVES; j++) {
    digitalWrite(SOL1+j, LOW);
    
  }
  
}

void loop() {
  /*
  // display a column of an image
  for(int i = 0; i<yDiv; i++) {
    for(int j = 0; j<NUM_VALVES; j++) {
      if(pxMatrix[i][j] == 1) {
        digitalWrite(SOL1+j, HIGH);
      } else {
        digitalWrite(SOL1+j, LOW);
      }
       
    }
    
    
    if(pxCol[i]) {
      digitalWrite(3, HIGH);   // open valve
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(12, HIGH);
    } else {
      digitalWrite(3, LOW);   // close valve
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
      digitalWrite(11, LOW);
      digitalWrite(12, LOW);
    }
    
    // variable delay which changes for each pixel based due to gravitational accel
    int timeIndex = (int)yDiv - i;
    delay(times[timeIndex]);
    //delay(100);
    
  }

  for(int j = 0; j<NUM_VALVES; j++) {
    digitalWrite(SOL1+j, LOW);
    
  }
  */

  for(int i = yDiv - 1; i>=0; i--) {
    for(int j = 0; j<NUM_VALVES; j++) {
      if(pxMatrixLines[i][j]) {
        digitalWrite(SOL1+j, HIGH);
      } else {
        digitalWrite(SOL1+j, LOW);
      }
       
    }
    int timeIndex = (int)yDiv - i;
    delay(times[timeIndex]);
    //delay(100);
    
  }
  for(int j = 0; j<NUM_VALVES; j++) {
    digitalWrite(SOL1+j, LOW);
    
  }
  
  
  delay(2000);
  /*
  for(int i = 0; i<yDiv; i++) {
    for(int j = 0; j<NUM_VALVES; j++) {
      if(pxMatrix2[i][j]) {
        digitalWrite(SOL1+j, HIGH);
      } else {
        digitalWrite(SOL1+j, LOW);
      }
       
    }
    int timeIndex = (int)yDiv - i;
    delay(5*times[timeIndex]);
    //delay(100);
    
  }
  for(int j = 0; j<NUM_VALVES; j++) {
    digitalWrite(SOL1+j, LOW);
    
  }

  delay(2000);

  for(int i = 0; i<yDiv; i++) {
    for(int j = 0; j<NUM_VALVES; j++) {
      if(pxMatrix3[i][j]) {
        digitalWrite(SOL1+j, HIGH);
      } else {
        digitalWrite(SOL1+j, LOW);
      }
       
    }
    int timeIndex = (int)yDiv - i;
    delay(5*times[timeIndex]);
    //delay(100);
    
  }

  
  for(int j = 0; j<NUM_VALVES; j++) {
    digitalWrite(SOL1+j, LOW);
    
  }
  
  delay(2000);
  */
  
}
