#include "definitions.h"
#include "electronics.h"

void setup() {
  
  //Set Mux first states
  pinMode(en_a, OUTPUT);
  digitalWrite(en_a, LOW);
  pinMode(en_b, OUTPUT);
  digitalWrite(en_b, HIGH);

  //4N25 is Low at the start
  pinMode(opto, OUTPUT);
  digitalWrite(opto, LOW);

  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  //check_short_circuit();
  //delay(1000);
  check_continuity();
  delay(1000);  
}
