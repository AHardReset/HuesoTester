#include "definitions.h"
#include "electronics.h"

void setup() {
  //Set the display
  welcome_display();
  

  //4N25 is Low at the start
  pinMode(opto, OUTPUT);
  digitalWrite(opto, LOW);

  //Set Mux first states
  pinMode(en_a, OUTPUT);
  digitalWrite(en_a, LOW);
  pinMode(en_b, OUTPUT);
  digitalWrite(en_b, HIGH);

  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  /* 
  bool success = false;
  success = check_short_circuit();
  if(success)
  {
    delay(1000);
    success = check_continuity();
    delay(1000);
  }
  if (success)
  {
    //Imprimir todo bien!
    test_success();
    while (true);
  }
  */
  check_continuity();
  delay(5000);
}