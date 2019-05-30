const int gLEDPin = 6;                                       // green LED- pin 11
const int rLEDPin = 9;                                       // red LED - pin 11
const int bLEDPin = 11;                                      // blue LED - pin 9
void setup() {
  Serial.begin(9600);                                        
  pinMode(gLEDPin, OUTPUT);
  pinMode(bLEDPin, OUTPUT);
  pinMode(rLEDPin, OUTPUT);
}

void loop() {                         
  int sensorValue = analogRead(A0);                           // citeste de la A0
  Serial.println(sensorValue);                                
  if ( sensorValue > 20) {                                    // ignora sunetul ambiental
    if ( sensorValue > 20 && sensorValue < 101 ) {            // aprinde green
      digitalWrite(gLEDPin, HIGH);
      delayMicroseconds(50);                                   
    }
    else if ( sensorValue > 100 && sensorValue < 176 ) {      // aprind cyan
      digitalWrite(gLEDPin, HIGH);
      digitalWrite(bLEDPin, HIGH);
      delayMicroseconds(50);                                  
    }
    else if ( sensorValue > 175 && sensorValue < 238) {       //aprinde blue
      digitalWrite(bLEDPin, HIGH);
      delayMicroseconds(50);                                 
    }
    else if ( sensorValue > 237 && sensorValue < 326) {       // aprinde purple
      digitalWrite(bLEDPin, HIGH);
      digitalWrite(rLEDPin, HIGH);
      delayMicroseconds(50);                                   
    }
    else if ( sensorValue > 325 && sensorValue < 700) {       // aprinde red
      digitalWrite(rLEDPin, HIGH);
      delayMicroseconds(50);                                 
    }
    else {
      digitalWrite(rLEDPin, LOW);
      digitalWrite(gLEDPin, LOW);
      digitalWrite(bLEDPin, LOW);
    }
  }
  else {
    digitalWrite(rLEDPin, LOW);                               
    digitalWrite(gLEDPin, LOW);                               
    digitalWrite(bLEDPin, LOW);                               
  }

  digitalWrite(rLEDPin, LOW);                                 // stinge ledurile
  digitalWrite(gLEDPin, LOW);                                
  digitalWrite(bLEDPin, LOW);                                

  delayMicroseconds(10);                                        
                                     
}
