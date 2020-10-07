#include "utilities.h"
#include "oled.h"

bool check_short_circuit()
{
  bool error = false;
  int data = 0;
  float dataV = 0;

  for(short int ch = 15; ch > 5; ch--)
  {
    mux_a.channel(ch);
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
      short_circuit_error(short_ch_to_pin(ch), dataV);
    }
    delay(1000/10);
  }

  if(debug)
  {
    Serial.println(" ");
    Serial.println("====== END OF SHORT CIRCUIT TEST ======");
    Serial.println(" ");
  }

  if(error)
  {
    return false;
  }
  return true;
}

bool check_continuity()
{
  //Setting hardware enabled
  
  digitalWrite(opto, HIGH);
  digitalWrite(en_b, LOW);

  bool error = false;
  int data = 0;
  float dataV = 0;

  for(int ch=15; ch>-1; ch--)
  {
    mux_a.channel(ch);
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
    }
    delay(1000/6);
  }
  for(int ch=15; ch>11; ch--)
  {
    mux_b.channel(ch);
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
    }
    delay(1000/4);
  }

  if(debug){
    Serial.println(" ");
    Serial.println("====== END OF CONTINUITY TEST ======");
    Serial.println(" ");
  }
  
  if(error)
  {
    return false;
  }
  return true;
}