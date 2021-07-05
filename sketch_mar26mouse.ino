#include <Mouse.h>

const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  17;      // the number of the LED pin

// variables will change:
int isON = false;         // variable for reading the pushbutton status
int lastButtonState = 1;
int buttonState = 1;
int ticks = 0;

void setup() {
  // initialize serial communication:
  Serial.begin(9600);
  delay(1000);
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);

  

 
  Serial.println("Device is Ready");
}

void loop() {
  randomSeed(analogRead(0));
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  
  if(buttonState != lastButtonState) {
    if(buttonState == LOW){
      lastButtonState = 0;
      isON = !isON;
    }else{
      lastButtonState = 1;
    }
    
    delay(50);
    
    if (isON == true) {
      // turn LED on:
      Serial.println("Device is ON");
      digitalWrite(ledPin, LOW);
      Mouse.begin();
    } else {
      // turn LED off:
      Serial.println("Device is OFF");
      digitalWrite(ledPin, HIGH);
      Mouse.end();
      ticks = 0;
    }
  }

  if(isON == true ) {
    if(ticks < 6000) {
      int rand1 = random(-1, 2);
      int rand2 = random(-1, 2);
      Serial.print(rand1);
      Serial.print(" : "); 
      Serial.print(rand2);
      Serial.println("------------ ");
      Mouse.move(rand1, rand2, 0);
    }
//    if(ticks >= 2000 && ticks < 8000) {
//      Mouse.move(random(-10, 10), random(-10, 10), 0);
//    }
//    if(ticks > 4000 && ticks < 6000) {
//      Mouse.move(0, 0, 1);
//    }
    if(ticks > 6000 && ticks < 6050) {
      Mouse.move(0, 0, random(-1, 2));
      delay(25);
      Serial.print(ticks);
      Serial.println("ticks: ");
    }
    if(ticks > 8000) {
//      Serial.print(random(-2, 2));
//      Serial.print(random(-2, 2));
      Serial.print(ticks);
      Serial.println("ticks ------------ ");
    }
    if(ticks > 25000) {
      ticks = 0;
    }
     
    ticks++;
  }
  
  

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  
  
}
