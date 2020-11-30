
#include <LiquidCrystal.h>

int counter;
int diameter;
int state;
int previousState;

const int sensor = 7;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  pinMode(sensor, INPUT);
  Serial.begin(9600);
  
  lcd.begin(16, 2);

  counter = 0;
  diameter = 5;

  state = 0;
  previousState = 0;
}

void loop() {
  state = digitalRead(sensor);
 // Serial.println(state);

  // compare the buttonState to its previous state
  if (state != previousState) {
    if (state== HIGH) { // if the current state is HIGH then the button went from off to on:
      counter ++;
      //debug
      Serial.println("on");
      Serial.print("counter= ");
      Serial.println(counter);
    } else {
      // if the current state is LOW then the button went from on to off:
      Serial.println("off");
    }
  }
  // save the current state as the last state, for next time through the loop
  previousState = state;
  

  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 0);
  // print the number of seconds since reset:
  lcd.print("Rounds: ");
  lcd.print(counter);
  lcd.setCursor(0, 1);
  lcd.print("Distance:");
  lcd.print(counter * diameter *PI/ 100000);
  lcd.print("km");
}
