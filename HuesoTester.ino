#include "definitions.h"
#include "electronics.h"

void setup() {
  //Set the display
  debug = false;
  wait_after_error = 3000;
  welcome_display();
  

  //Led blinking
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);

  //Relay is Low at the start
  pinMode(relay, OUTPUT);
  digitalWrite(relay, LOW);
  
  //Set Mux first states
  pinMode(en_a, OUTPUT);
  digitalWrite(en_a, LOW);
  pinMode(en_b, OUTPUT);
  digitalWrite(en_b, HIGH);

  if(debug)
  {
    Serial.begin(9600);
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  
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
    while (true)
    {
      blink_led(1000);
    }
  }
}