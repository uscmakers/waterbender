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

// counter for iteration of design
int count = 0;

/* DISPLAY A COLUMN OF PIXELS */
// Beginning of array is bottom of image
int pxCol[10] = {1,0,0,0,0,0,0,0,0,0};

int pxMatrixCactus[10][10] = {
{0,0,0,0,0,0,0,0,0,0},
{0,0,0,1,1,1,1,0,0,0},
{1,1,0,1,1,1,1,0,0,0},
{1,1,0,1,1,1,1,0,0,0},
{1,1,0,1,1,1,1,0,1,1},
{1,1,1,1,1,1,1,0,1,1},
{0,0,0,1,1,1,1,0,1,1},
{0,0,0,1,1,1,1,1,1,1},
{0,0,0,1,1,1,1,0,0,0},
{0,0,0,1,1,1,1,0,0,0}
};

int pxMatrixDoubleZag[10][10] = {
{1,1,1,1,1,1,1,1,1,1},
{0,1,1,1,1,1,1,1,1,0},
{0,0,1,1,1,1,1,1,0,0},
{0,0,0,1,1,1,1,0,0,0},
{0,0,0,0,1,1,0,0,0,0},
{0,0,0,0,1,1,0,0,0,0},
{0,0,0,1,1,1,1,0,0,0},
{0,0,1,1,1,1,1,1,0,0},
{0,1,1,1,1,1,1,1,1,0},
{1,1,1,1,1,1,1,1,1,1},
};

int pxRocketFull[10][10] = {
{0,0,0,0,1,1,0,0,0,0},
{0,0,0,1,1,1,1,0,0,0},
{0,0,1,1,1,1,1,1,0,0},
{0,0,1,1,1,1,1,1,0,0},
{0,0,1,1,1,1,1,1,0,0},
{0,0,1,1,1,1,1,1,0,0},
{0,0,1,1,1,1,1,1,0,0},
{0,0,1,1,1,1,1,1,0,0},
{0,1,1,0,0,0,0,1,1,0},
{0,1,0,0,0,0,0,0,1,0}
};

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
  {0,0,0,0,0,0,0,0,0,0}};


int pxCurve[10][10] = {
{1,1,1,1,0,0,0,0,0,0},
{0,0,0,1,1,1,1,0,0,0},
{0,0,0,0,0,0,1,1,1,0},
{0,0,0,0,0,0,0,0,1,1},
{0,0,0,0,0,0,0,0,0,1},
{0,0,0,0,0,0,0,0,1,1},
{0,0,0,0,0,0,1,1,1,0},
{0,0,0,1,1,1,1,0,0,0},
{1,1,1,1,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0}
};

int pxSine[10][10] = {
{0,0,0,0,0,1,1,1,0,0},
{0,0,0,0,0,0,0,1,1,0},
{0,0,0,0,0,0,0,0,1,1},
{0,0,0,0,0,0,0,1,1,0},
{0,0,0,0,0,1,1,1,0,0},
{0,0,1,1,1,0,0,0,0,0},
{0,1,1,0,0,0,0,0,0,0},
{1,1,0,0,0,0,0,0,0,0},
{0,1,1,0,0,0,0,0,0,0},
{0,0,1,1,1,0,0,0,0,0}
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

int pxMatrix3_squished[10][10] = {
{0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0},
{0,0,0,1,1,1,1,1,1,1},
{0,0,1,0,0,0,0,0,0,0},
{0,1,0,0,0,0,0,0,0,0},
{0,0,1,0,0,0,0,0,0,0},
{0,0,0,1,1,1,1,1,1,1},
{0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0}
};

int pxZigZag[16][10] = {
{1,1,1,0,0,0,0,0,0,0},
{0,1,1,1,0,0,0,0,0,0},
{0,0,1,1,1,0,0,0,0,0},
{0,0,0,1,1,1,0,0,0,0},
{0,0,0,0,1,1,1,0,0,0},
{0,0,0,0,0,1,1,1,0,0},
{0,0,0,0,0,0,1,1,1,0},
{0,0,0,0,0,0,0,1,1,1},
{0,0,0,0,0,0,0,1,1,1},
{0,0,0,0,0,0,1,1,1,0},
{0,0,0,0,0,1,1,1,0,0},
{0,0,0,0,1,1,1,0,0,0},
{0,0,0,1,1,1,0,0,0,0},
{0,0,1,1,1,0,0,0,0,0},
{0,1,1,1,0,0,0,0,0,0},
{1,1,1,0,0,0,0,0,0,0}
};

int pxHeart[10][10] = {
{0,1,1,1,0,0,1,1,1,0},
{1,0,0,0,1,1,0,0,0,1},
{0,1,0,0,0,0,0,0,1,0},
{0,0,1,0,0,0,0,1,0,0},
{0,0,0,1,0,0,1,0,0,0},
{0,0,0,0,1,1,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0}
};

int pxStar[10][10] = {
{0,1,0,0,0,0,0,0,1,0},
{0,0,1,0,0,0,0,1,0,0},
{0,0,0,1,0,0,1,0,0,0},
{0,0,0,0,1,1,0,0,0,0},
{1,1,1,1,1,1,1,1,1,1},
{0,0,0,0,1,1,0,0,0,0},
{0,0,0,1,0,0,1,0,1,0},
{0,0,1,0,0,0,0,1,0,0},
{0,1,0,0,0,0,0,0,1,0},
{0,0,0,0,0,0,0,0,0,0}
};

int pxMoon[10][10] = {
{0,0,0,0,0,0,0,1,1,0},
{0,0,0,0,0,0,0,1,1,0},
{0,0,0,0,0,1,1,0,1,0},
{0,0,0,0,1,1,0,1,0,0},
{0,0,0,1,1,0,1,1,0,0},
{0,0,0,1,1,0,1,1,0,0},
{0,0,0,1,1,0,1,1,0,0},
{0,0,0,0,1,1,0,1,1,0},
{0,0,0,0,0,1,1,0,1,1},
{0,0,0,0,0,0,0,1,0,0}
};

int pxChode[6][10] = {
{1,1,1,0,0,0,1,1,1,0},
{1,1,1,0,0,0,1,1,1,0},
{1,1,1,0,0,0,1,1,1,0},
{0,0,0,1,1,1,0,0,0,0},
{0,0,0,1,1,1,0,0,0,0},
{0,0,0,1,1,1,0,0,0,0}
};

int pxStickFig[10][10] = {
{0,0,0,0,1,1,0,0,0,0},
{0,0,0,1,0,0,1,0,0,0},
{0,1,0,0,1,1,0,0,1,0},
{0,0,1,1,1,1,1,1,0,0},
{0,0,0,0,1,1,0,0,0,0},
{0,0,0,0,1,1,0,0,0,0},
{0,0,0,0,1,1,0,0,0,0},
{0,0,0,1,0,0,1,0,0,0},
{0,1,1,0,0,0,0,1,1,0},
{0,0,0,0,0,0,0,0,0,0}
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

void calc_times(int yDiv) {
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

  // -----------SINE DESIGN-------------------
  if(count < 30){
    for(int i = 9; i>=0; i--) {
      for(int j = 0; j<NUM_VALVES; j++) {
        if(pxSine[i][j]) {
          digitalWrite(SOL1+j, HIGH);
        } else {
          digitalWrite(SOL1+j, LOW);
        }
         
      }
      delay(30* (1+((yDiv-1)/(100*yDiv))));
      
    }

  //------------HEART DESIGN---------------------
  }else if(count < 35){
    for(int i = 9; i>=0; i--) {
      for(int j = 0; j<NUM_VALVES; j++) {
        if(pxHeart[i][j]) {
          digitalWrite(SOL1+j, HIGH);
        } else {
          digitalWrite(SOL1+j, LOW);
        }
         
      }
      //int timeIndex = i;
      //delay(times[timeIndex]);
      delay(30* (1+((yDiv-1)/(100*yDiv))));
      
    }
  
    
    
    for(int j = 0; j<NUM_VALVES; j++) {
      digitalWrite(SOL1+j, LOW);
      
    }
  
    delay(2000);

  //---------------ZIGZAG DESIGN----------------
  }else if(count < 60){                    
    for(int i = 9; i>=0; i--) {
      for(int j = 0; j<NUM_VALVES; j++) {
        if(pxZigZag[i][j]) {
          digitalWrite(SOL1+j, HIGH);
        } else {
          digitalWrite(SOL1+j, LOW);
        }
         
      }
      //int timeIndex = i;
      //delay(times[timeIndex]);
      delay(30* (1+((yDiv-1)/(100*yDiv))));
      
    }
  
    
    /*
    for(int j = 0; j<NUM_VALVES; j++) {
      digitalWrite(SOL1+j, LOW);
      
    }
  
    delay(2000);
    */

  //------------CHODE CHECKERS DESIGN--------
  }else if(count < 80){
    for(int i = 9; i>=0; i--) {
      for(int j = 0; j<NUM_VALVES; j++) {
        if(pxChode[i][j]) {
          digitalWrite(SOL1+j, HIGH);
        } else {
          digitalWrite(SOL1+j, LOW);
        }
         
      }
      //int timeIndex = i;
      //delay(times[timeIndex]);
      delay(30* (1+((yDiv-1)/(100*yDiv))));
      
    }
  
    
    /*
    for(int j = 0; j<NUM_VALVES; j++) {
      digitalWrite(SOL1+j, LOW);
      
    }
  
    delay(2000);
    */
  //------------ROCKET DESIGN--------
  }else if(count < 90){
    for(int i = 9; i>=0; i--) {
      for(int j = 0; j<NUM_VALVES; j++) {
        if(pxRocketFull[i][j]) {
          digitalWrite(SOL1+j, HIGH);
        } else {
          digitalWrite(SOL1+j, LOW);
        }
         
      }
      //int timeIndex = i;
      //delay(times[timeIndex]);
      delay(30* (1+((yDiv-1)/(100*yDiv))));
      
    }
  
    
    
    for(int j = 0; j<NUM_VALVES; j++) {
      digitalWrite(SOL1+j, LOW);
      
    }
    
    delay(2000);
  //-------------HOURGLASS DESIGN--------
  }else if(count < 110){
    for(int i = 9; i>=0; i--) {
      for(int j = 0; j<NUM_VALVES; j++) {
        if(pxMatrixDoubleZag[i][j]) {
          digitalWrite(SOL1+j, HIGH);
        } else {
          digitalWrite(SOL1+j, LOW);
        }
         
      }
      //int timeIndex = i;
      //delay(times[timeIndex]);
      delay(30* (1+((yDiv-1)/(100*yDiv))));
      
    }
  
    
    
    for(int j = 0; j<NUM_VALVES; j++) {
      digitalWrite(SOL1+j, LOW);
      
    }

  //------------CACTUS DESIGN-------
  }else if(count < 120){
    for(int i = 9; i>=0; i--) {
      for(int j = 0; j<NUM_VALVES; j++) {
        if(pxMatrixCactus[i][j]) {
          digitalWrite(SOL1+j, HIGH);
        } else {
          digitalWrite(SOL1+j, LOW);
        }
         
      }
      //int timeIndex = i;
      //delay(times[timeIndex]);
      delay(30* (1+((yDiv-1)/(100*yDiv))));
      
    }
  
    
    
    for(int j = 0; j<NUM_VALVES; j++) {
      digitalWrite(SOL1+j, LOW);
      
    }
    delay(2000);
    if(count == 139){
      count = 0;
    }
  }
  count++;
  //-------DONE---------------//
  /*
  for(int i = 9; i>=0; i--) {
    for(int j = 0; j<NUM_VALVES; j++) {
      if(pxStickFig[i][j]) {
        digitalWrite(SOL1+j, HIGH);
      } else {
        digitalWrite(SOL1+j, LOW);
      }
       
    }
    //int timeIndex = i;
    //delay(times[timeIndex]);
    delay(30* (1+((yDiv-1)/(100*yDiv))));
    
  }

  
  
  for(int j = 0; j<NUM_VALVES; j++) {
    digitalWrite(SOL1+j, LOW);
    
  }

  delay(2000);
  */
  
  

  
  
}
