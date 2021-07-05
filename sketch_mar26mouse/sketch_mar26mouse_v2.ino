#include <Mouse.h>

const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  17;      // the number of the LED pin

// variables will change:
int buttonState = false;         // variable for reading the pushbutton status
int isButtonPressed;
int ticks = 0;

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
 
}

void loop() {
  // read the state of the pushbutton value:
  //buttonState = digitalRead(buttonPin);
  isButtonPressed = digitalRead(buttonPin);
  
  delay(5);
  
  int isButtonPressed2 = digitalRead(buttonPin);
  
  if(isButtonPressed2 != LOW && isButtonPressed == LOW) {
    if(isButtonPressed == LOW) {
      buttonState = !buttonState;
    }
  
    if (buttonState == true) {
      // turn LED on:
      digitalWrite(ledPin, LOW);
      Mouse.begin();
    } else {
      // turn LED off:
      digitalWrite(ledPin, HIGH);
      Mouse.end();
    }
  }

  if(buttonState == true ) {
    if(ticks < 200) {
      Mouse.move(1, 1, 0);
    }
    if(ticks >= 200 && ticks < 400) {
      Mouse.move(-1, -1, 0);
    }
    if(ticks > 400 && ticks < 700) {
      Mouse.move(0, 0, 1);
    }
    if(ticks > 700 && ticks < 1000) {
      Mouse.move(0, 0, -1);
    }
    if(ticks > 1000) {
      Serial.println(ticks);
    }

    if(ticks > 1100) {
      ticks = 0;
    }
     
    ticks++;
  }
  
  

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  
  
}
