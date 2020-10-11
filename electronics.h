#include "utilities.h"
#include "oled.h"
int wait_after_error = 3000;
bool check_short_circuit()
{
  bool error = false;
  int data = 0;
  float dataV = 0;
  digitalWrite(relay, LOW);

  for(short int ch = 15; ch > 5; ch--)
  {
    mux_a.channel(ch);
    delay(50);
    data = analogRead(sig_a);
    dataV = convert_data_to_V(data);

    if(debug)
    {
      print_ch_result(ch, dataV);
    }
    //if data in analogread exceds
    if(data > max_shortV)
    {
      error = true;
      short_circuit_error(ch, dataV);
      delay(wait_after_error);
    }
  }

  if(debug)
  {
    Serial.println(" ");
    Serial.println("====== END OF SHORT CIRCUIT TEST ======");
    Serial.println(" ");
  }

  if(error)
  {
    test_failed();
    delay(1000);
    return false;
  }
  return true;
}

bool check_continuity()
{
  //Setting hardware enabled
  
  digitalWrite(relay, HIGH);
  digitalWrite(en_b, LOW);
  delay(500);
  bool error = false;
  int data = 0;
  float dataV = 0;

  for(int ch=15; ch>-1; ch--)
  {
    mux_a.channel(ch);
    delay(50);
    data = analogRead(sig_a);
    dataV = convert_data_to_V(data);

    if(debug)
    {
      print_ch_result(ch, dataV);
    }
    
    if (data < min_continuityV)
    {
      error = true;
      continuity_error(ch, dataV, true);
      delay(wait_after_error);
    }
  }
  for(int ch=15; ch>11; ch--)
  {
    mux_b.channel(ch);
    delay(50);
    data = analogRead(sig_b);
    dataV = convert_data_to_V(data);

    if(debug)
    {
      print_ch_result(ch, dataV);
    }
    
    if (data < min_continuityV)
    {
      error = true;
      continuity_error(ch, dataV, false);
      delay(wait_after_error);
    }
  }

  if(debug){
    Serial.println(" ");
    Serial.println("====== END OF CONTINUITY TEST ======");
    Serial.println(" ");
  }
  
  if(error)
  {
    test_failed();
    delay(1000);
    return false;
  }
  return true;
}