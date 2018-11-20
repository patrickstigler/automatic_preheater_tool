#include <SimpleDHT.h>
#include <Servo.h>


int DHT11Pin = 4;
int servoPin = 9;

int pos = 0;    // variable to store the servo position

// config for the automatic heater tool
int minTempToReactivateHeater = 19;
int heaterMaxRunningTimeInMin = 120;
int temperatureCheckInvervalInMin = 2;
// config end

SimpleDHT11 dht11(DHT11Pin); // create dht11 object to read sensor data
Servo servo;  // create servo object to control a servo

void setup() {
  servo.attach(servoPin);

  //debugging
  Serial.begin(115200);
  Serial.println("Debug automatic preheater tool");
}

void loop() {
  // servo go pos 0
  servo.write(0);
  // read without samples.
  byte temperature = 0;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
    // debugging
    Serial.print("Read DHT11 failed, err="); Serial.println(err);delay(1000);
    return;
  }
  
  // debugging
  Serial.print((int)temperature); Serial.println(" *C, "); 
  Serial.print((int)humidity); Serial.println(" H");

  if((int)temperature < minTempToReactivateHeater)
  {
    // debugging
    Serial.println("temperature below threshold");
    
    pushButton();
    delay(500);
    releaseButton();
    
    // delay heater time + 5min
    delay(heaterMaxRunningTimeInMin * 1000 * 60 + 300);
  }

 // interval to check temperature
  delay(temperatureCheckInvervalInMin * 1000 * 60);
}

void pushButton(){
    for (pos = 0; pos <= 60; pos += 1) { // goes from 0 degrees to 90 degrees
    // in steps of 1 degree
    servo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  // debugging
   Serial.println("button pushed");
}

void releaseButton(){
    for (pos = 60; pos >= 0; pos -= 1) { // goes from 90 degrees to 0 degrees
    servo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  // debugging
  Serial.println("button released");
}



