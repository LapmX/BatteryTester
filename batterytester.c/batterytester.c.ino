/*
 Battery tester helper code

 Arduino configured to read voltage every 1 minute and send it over usb serial
 */

// These constants won't change.  They're used to give names
// to the pins used:
const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
int sensorValue = 0;        // value read from the analog in
float outputValue = 0;        // Actual calculated Voltage
int analogOutPin = 9;


void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(115200);

  pinMode(analogOutPin, OUTPUT);
  analogWrite(analogOutPin, 6);

}

void loop() {
  // read the analog in value and scale it to voltage:
  sensorValue = analogRead(analogInPin);
  outputValue = (5.0/1024)*sensorValue;
  // print the results to the serial monitor:
  //Serial.print(outputValue);
  Serial.println(outputValue);
 
  // 6000 ms = 6 seconds
  // 60.000 = 1 min
  // 600.000 = 10 min
  delay(60000);
}
