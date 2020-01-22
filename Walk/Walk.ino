int sensorPin = 1;    // select the input pin for the potentiometer
int ledPin = 1;      // select the pin for the LED
int numbersPIN = 5;
int sensorValue = 0;  // variable to store the value coming from the sensor
int rocketFan = 9;

void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);  
  pinMode(numbersPIN, OUTPUT);  
  pinMode(rocketFan, OUTPUT);  

}

void printNumberOnLED(int number)
{
  // 255 -> 99, 0 -> 0
  analogWrite(numbersPIN, (2.55 * number));
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);

  digitalWrite(ledPin, LOW);  

  if (sensorValue > 500)
  {
    analogWrite(rocketFan, 0);

    for (int i = 10; i > 0; i--)
    {
      printNumberOnLED(i);

      if (i > 4)
      {
        digitalWrite(ledPin, HIGH);
        delay(1000);
      }
      else
      {
        digitalWrite(ledPin, LOW);
        delay(500);
        digitalWrite(ledPin, HIGH);
        delay(500); 
      }
    }
  } 
  else
  {  
    // turn the ledPin on
    analogWrite(numbersPIN, sensorValue);  
  }
  
  // stop the program for <sensorValue> milliseconds:
  delay(1000);          

  // turn the ledPin off:        
  digitalWrite(ledPin, LOW);   

  // stop the program for for <sensorValue> milliseconds:
  delay(sensorValue);                  
}
