
#define echoPin 2 
#define trigPin 3 
// defines variables
long duration; 
int distance; 
int ledPin = 6;    // LED connected to digital pin 9








  

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);




  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  
 
}

void loop(){
     int analogVal = analogRead(A0); //read values from A0
   int Resistance= 5; //I am using a 10k ohms resistor

   double Vout= analogVal*0.0048828125;
  int lux=((2500/Vout-500)/Resistance);

   Serial.print("Light Intensity:");
   Serial.print(lux);
   Serial.println(" lux");


if (lux <= 1000)
{
  //CODE FOR ULTRASONIC SENSOR
digitalWrite(trigPin, LOW);
              delayMicroseconds(10);
              // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
              digitalWrite(trigPin, HIGH);
              delayMicroseconds(10);
              digitalWrite(trigPin, LOW);
              // Reads the echoPin, returns the sound wave travel time in microseconds
              duration = pulseIn(echoPin, HIGH);
              // Calculating the distance
              distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
              // Displays the distance on the Serial Monitor
              Serial.print("Distance: ");
              Serial.print(distance);
              Serial.println(" cm");



              //CODE FOR LED OUTPUT 
              
  
if (distance < 100)
{
   // fade in from min to max in increments of 5 points:
  for (int fadeValue = 120 ; fadeValue <= 255; fadeValue += 135) {
   
    analogWrite(ledPin, fadeValue);
    // wait for 30 milliseconds to see the dimming effect
    delay(1000);
  }

  // fade out from max to min in increments of 5 points:
  for (int fadeValue = 255 ; fadeValue >= 120; fadeValue -= 5) {
    
    analogWrite(ledPin, fadeValue);
    // wait for 30 milliseconds to see the dimming effect
    delay(30);
  }
}

else{
  
  analogWrite(ledPin, 130);  
}

}

if (lux > 1000)
{
   analogWrite(ledPin, 0);
}

delayMicroseconds(10);




   
}
