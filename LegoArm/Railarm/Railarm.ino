  
/* 
 * Code by David McCormack
 */

/*
 * Global Ardunio PIN settings
 */
static int ledPIN = 9;        // PIN for the flashing rail lights
static int numbersPIN = 5;    // PIN for train counter
static int sensorPin = 1;     // PIN for Pressure sensor
static int crossingArm = 1;   // PIN for crossing arm servo

// Global variable to keep track of number of times the train has passed.
int numberOfTrains = 0;

/*
 * Ardunio setup routine
 */
void setup() 
{
  pinMode(ledPIN, OUTPUT);  
  pinMode(numbersPIN, OUTPUT);  
  pinMode(crossingArm, OUTPUT);  
  
}

/* 
 * Routine to try and print a number on an analog PIN.  This is an approximation and may be off some of the time.
 */
void printNumberOnLED(int number)
{
  // 255 maps to 99, while 0 maps to 0
  analogWrite(numbersPIN, number * 2.55);
}

/* 
 * Count that the train has passed over and update the number.
 */
void countTrain()
{
    numberOfTrains++; 
    printNumberOnLED(numberOfTrains);  
}

/*
 * Ardunio loop routine
 */
void loop()
{
  while (true)
  {
    // Ensure crossing lights are off
    digitalWrite(ledPIN, 0);
    
    // Check to see if a train is on top
    if (analogRead(sensorPin) > 1)
    {
      // Lower the crossing arm
      digitalWrite(crossingArm, 1);

      // white the train is on the sensor, lets flash the LEDs
      while (analogRead(sensorPin) > 0)
      {
        // Turn LEDs on
        digitalWrite(ledPIN, 1);
        delay(150);
        
        // Turn LEDs off
        digitalWrite(ledPIN, 0);
        delay(150);
      }

      // Raise the crossing arm.
      digitalWrite(crossingArm, 0);
      
      // Update the count and display of trains.
      countTrain(); 
      
      delay(1000);   
    }
  }
}
