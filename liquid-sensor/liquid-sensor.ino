// Liquid level detection using an SST sensor
//
// when a liquid touches the tip of the sensor, turn power relay off.
// once it no longer detects water, wait 60 seconds.
// turn power relay back on.
// once water sensor detects water again, turn power relay off.
// 
// Hardware:
//     Sensor    | Arduino
//  -------------|---------
//    Vs (RED)   |    5V
//   Out (GREEN) |   pin 7
//   GND (BLUE)  |    GND

// Pins
const int LIQUID_SENSOR_PIN = 7;
const int RELAY_PIN = 3;

void setup() { 
  pinMode(LIQUID_SENSOR_PIN, INPUT);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH);
  Serial.begin(9600);
}

void loop() {
  int isWet = digitalRead(LIQUID_SENSOR_PIN);
  if ( isWet ) {
    digitalWrite(RELAY_PIN, LOW);
    Serial.println("relay and pump off");
  } else {
    for (int count = 0; count < 120; count++) { // pause relay for 60 seconds
      delay(500);
      isWet = digitalRead(LIQUID_SENSOR_PIN);
      if (!isWet) {
        break;
      }
    }
    digitalWrite(RELAY_PIN, HIGH);
    Serial.println("relay and pump on");
  }
}
