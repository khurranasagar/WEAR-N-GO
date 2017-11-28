#include <SoftwareSerial.h>

SoftwareSerial BTserial(0, 1); // RX | TX
int inPin = 6;         // the number of the input pin
int inPin1 = 5;
int inPin2 = 9;
int inPin3 = 10;
int inPin4 = 12;
int inPin5 = 13;

int reading;           // the current reading from the input pin
int previous = LOW;    // the previous reading from the input pin

int reading1;           // the current reading from the input pin
int previous1 = LOW;

int reading2;           // the current reading from the input pin
int previous2 = LOW;

int reading3;           // the current reading from the input pin
int previous3 = LOW;

int reading4;           // the current reading from the input pin
int previous4 = LOW;    // the previous reading from the input pin

int reading5;           // the current reading from the input pin
int previous5 = LOW;    // the previous reading from the input pin

// the follow variables are long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long time = 0;
long time2 = 0;
long time3 = 0;
long time4 = 0;
long time5 = 0;
long time1 = 0;// the last time the output pin was toggled
long debounce = 400;   // the debounce time, increase if the output flickers

void setup()
{
  pinMode(inPin, INPUT);
  pinMode(inPin1, INPUT);
  pinMode(inPin2, INPUT);
  pinMode(inPin3, INPUT);
  pinMode(inPin4, INPUT);
  pinMode(inPin5, INPUT);
  BTserial.begin(9600);
}

void loop()
{
  reading = digitalRead(inPin);
  reading1 = digitalRead(inPin1);
  reading2 = digitalRead(inPin2);
  reading3 = digitalRead(inPin3);
  reading4 = digitalRead(inPin4);
  reading5 = digitalRead(inPin5);
//delay(500);
//BTserial.println(reading1);
//BTserial.println(reading2);

  // if the input just went from LOW and HIGH and we've waited long enough
  // to ignore any noise on the circuit, toggle the output pin and remember
  // the time
  if (reading == HIGH && previous == LOW && millis() - time > debounce) {
    BTserial.print("M ");
//    BTserial.println(reading);
//    BTserial.println(reading1);
//    BTserial.println(reading2);
//    BTserial.println(reading3);
//    BTserial.println(reading4);
//    BTserial.println(reading5);
    time = millis();    
  }
  if (reading1 == HIGH && previous1 == LOW && millis() - time1 > debounce) {
    BTserial.print("A ");
//    BTserial.println(reading);
//    BTserial.println(reading1);
//    BTserial.println(reading2);
//    BTserial.println(reading3);
//    BTserial.println(reading4);
//    BTserial.println(reading5);
    previous1 = reading1;
    time1 = millis();    
  }
  if (reading2 == HIGH && previous2 == LOW && millis() - time2 > debounce) {
    BTserial.print("B ");
//    BTserial.println(reading);
//    BTserial.println(reading1);
//    BTserial.println(reading2);
//    BTserial.println(reading3);
//    BTserial.println(reading4);
//    BTserial.println(reading5);
    previous2 = reading2;
    time2 = millis();    
  }
  if (reading3 == HIGH && previous3 == LOW && millis() - time3 > debounce) {
    BTserial.print("R ");
//    BTserial.println(reading);
//    BTserial.println(reading1);
//    BTserial.println(reading2);
//    BTserial.println(reading3);
//    BTserial.println(reading4);
//    BTserial.println(reading5);
    previous3 = reading3;
    time3 = millis();    
  }
  if (reading4 == HIGH && previous4 == LOW && millis() - time4 > debounce) {
    BTserial.print("P ");
//    BTserial.println(reading);
//    BTserial.println(reading1);
//    BTserial.println(reading2);
//    BTserial.println(reading3);
//    BTserial.println(reading4);
//    BTserial.println(reading5);
    previous4 = reading4;
    time4 = millis();    
  }
  if (reading5 == HIGH && previous5 == LOW && millis() - time5 > debounce) {
    BTserial.print("C ");
//    BTserial.println(reading);
//    BTserial.println(reading1);
//    BTserial.println(reading2);
//    BTserial.println(reading3);
//    BTserial.println(reading4);
//    BTserial.println(reading5);
    previous5 = reading5;
    time5 = millis();    
  }
  previous = reading;
  previous1 = reading1;
  previous2 = reading2;
  previous3 = reading3;
  previous4 = reading4;
  previous5 = reading5;
}
