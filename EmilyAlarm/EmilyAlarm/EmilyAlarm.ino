  
/* 
 * Code by David McCormack
 */

/*
 * Global Ardunio PIN settings
 */
static int led1PIN = 9; 
static int led2PIN = 5;
static int buttonPIN = 1;

/*
 * Ardunio setup routine
 */
void setup() 
{
  pinMode(led1PIN, OUTPUT);  
  pinMode(led2PIN, OUTPUT);  
  pinMode(buttonPIN, INPUT);  
}

/*
 * Ardunio loop routine
 */
void loop()
{
  while (true)
  {
    // Ensure crossing lights are off
    digitalWrite(led1PIN, 0);
    digitalWrite(led2PIN, 0);

    if (analogRead(buttonPIN) > 1)
    {
      digitalWrite(led1PIN, 1);      
      digitalWrite(led2PIN, 0);      
      delay(200);
      digitalWrite(led1PIN, 0);      
      digitalWrite(led2PIN, 1);      
      delay(200);
      digitalWrite(led1PIN, 1);      
      digitalWrite(led2PIN, 0);      
      delay(200);
      digitalWrite(led1PIN, 0);      
      digitalWrite(led2PIN, 1);      
      delay(200);
      digitalWrite(led1PIN, 1);      
      digitalWrite(led2PIN, 0);      
      delay(200);
    }
    else
    { 
      digitalWrite(led1PIN, 0);      
      digitalWrite(led2PIN, 0);      
    }
  }
}
