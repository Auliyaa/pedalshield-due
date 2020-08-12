/*
 * PedalShield diagnostics.
 * Author: Gabriel Marti 
 * CODE FREE TO USE FOR ANYONE.
 * Licensed under a Creative Commons Attribution 3.0 Unported License.
 */
 
#define DEBUGADC0   0     // if you want to disable DEBUG set this value to 0
#define DEBUGADC1   0     // if you want to disable DEBUG set this value to 0
#define DEBUGPOT0   1     // if you want to disable DEBUG set this value to 0
#define DEBUGPOT1   0     // if you want to disable DEBUG set this value to 0
#define DEBUGPOT2   0     // if you want to disable DEBUG set this value to 0

#define LED         3     // Led pin
#define FOOTSWITCH  7     // Foot switch
#define AADC0       0     // AUDIO ADC 0
#define AADC1       1     // AUDIO ADC 1
#define POT0        8     // ADC8     
#define POT1        9     // ADC9
#define POT2        10    // ADC10

int in_ADC0, in_ADC1;     // variables for 2 ADCs values (ADC0, ADC1)
int out_DAC0, out_DAC1; 
 
// Previous and current value of every sensor (POT's and Audio)
int sensorV1a, sensorV1b, sensorV2a, sensorV2b, sensorV3a, sensorV3b, sensorV4a, sensorV4b, sensorV5a, sensorV5b;
 
void setup() {
  // initializes sensor variables monitor
  sensorV1a = sensorV1b = sensorV2a = sensorV2b = sensorV3a = sensorV3b = sensorV4a = sensorV4b = sensorV5a = sensorV5b = 0;
  if ( DEBUGADC0 || DEBUGADC1 || DEBUGPOT0 || DEBUGPOT1 || DEBUGPOT2 ) {
    Serial.begin(9600);
  }
 
  // pedalSHIELD pin configuration
  pinMode(LED, OUTPUT);  
  pinMode(FOOTSWITCH, INPUT_PULLUP);      
  pinMode(TOGGLE, INPUT_PULLUP);  
 
  // ADC Configuration
  ADC->ADC_MR |= 0x80;    // DAC in free running mode.
  ADC->ADC_CR=2;          // Starts ADC conversion.
  ADC->ADC_CHER=0x1CC0;   // Enable ADC channels 0,1,8,9 and 10   
 
  // DAC Configuration
  analogWrite(DAC0,0);    // Enables DAC0
  analogWrite(DAC1,0);    // Enables DAC0
}
 
void loop() {
  delay(1000);            // delay in between reads for stability
 
  // ADC Audio 0
  sensorV1a = sensorV1b;      
  sensorV1b = analogRead(AADC0);
  if ( DEBUGADC0 && sensorV1a != sensorV1b ) {
    Serial.print("ADC Audio 0: "); Serial.println(sensorV1b); 
  }
  // ADC Audio 1
  sensorV2a = sensorV2b;      
  sensorV2b = analogRead(AADC1);
  if ( DEBUGADC1 && sensorV2a != sensorV2b ) {
    Serial.print("ADC Audio 1: "); Serial.println(sensorV2b); 
  }
  // ADC POT 0
  sensorV3a = sensorV3b;      
  sensorV3b = analogRead(POT0);
  if ( DEBUGPOT0 && sensorV3a != sensorV3b ) {
    Serial.print("ADC POT 0: "); Serial.println(sensorV3b); 
  }
  // ADC POT 1
  sensorV4a = sensorV4b;      
  sensorV4b = analogRead(POT1);
  if ( DEBUGPOT1 && sensorV4a != sensorV4b ) {
    Serial.print("ADC POT 1: "); Serial.println(sensorV4b); 
  }    
  // ADC POT 2
  sensorV5a = sensorV5b;      
  sensorV5b = analogRead(POT2);
  if ( DEBUGPOT2 && sensorV5a != sensorV5b ) {
    Serial.print("ADC POT 2: "); Serial.println(sensorV5b); 
  }    
 
}