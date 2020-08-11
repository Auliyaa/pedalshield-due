// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}
 
// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue1 = analogRead(0);
  int sensorValue2 = analogRead(1);
  int sensorValue3 = analogRead(8);
  int sensorValue4 = analogRead(9);
  int sensorValue5 = analogRead(10);
  // print out the value you read:
  Serial.print("ADC Audio 0: "); Serial.println(sensorValue1);
  Serial.print("ADC Audio 1: "); Serial.println(sensorValue2);
  Serial.print("ADC POT 0: ");Serial.println(sensorValue3);
  Serial.print("ADC POT 1: ");Serial.println(sensorValue4);
  Serial.print("ADC POT 2: ");Serial.println(sensorValue5);
  Serial.print("\n");
 
  delay(1000);        // delay in between reads for stability
}