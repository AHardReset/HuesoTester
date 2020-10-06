#include "utilities.h"

void check_short_circuit()
{
  bool error = false;
  int data = 0;
  float dataV = 0;
  Serial.println("===============================");
  for(short int ch = 15; ch > 5; ch--)
  {
    mux_a.channel(ch);
    data = analogRead(sig_a);
    dataV = convert_data_to_V(data);
    print_ch_result(ch, dataV);
    if(data > max_shortV)
    {
      error = true;
      Serial.println("");
      Serial.print("Short Circuit in Pin ");
      Serial.print(short_ch_to_pin(ch));
      Serial.print(" || ");
      Serial.print(convert_data_to_V(data));
      Serial.println(" V");
      Serial.println("");
      delay(1000);
      //while (true);
    }
    delay(100);
  }
  Serial.println(" ");
  Serial.println("====== END OF SHORT CIRCUIT TEST ======");
  Serial.println(" ");
  if(error)
  {
    while (true);
  }
}

void check_continuity()
{
  digitalWrite(opto, HIGH);

  bool error = false;
  int data = 0;
  float dataV = 0;
  Serial.println("===============================");
  for(int ch=15; ch>-1; ch--)
  {
    mux_a.channel(ch);
    data = analogRead(sig_a);
    dataV = convert_data_to_V(data);
    print_ch_result(ch, dataV);
    if (data < min_continuityV)
    {
      error = true;
      Serial.println("");
      Serial.print("No Continuity in Pin ");
      Serial.print(continuity_ch_to_pin(ch, true));
      Serial.print(" || ");
      Serial.print(convert_data_to_V(data));
      Serial.println(" V");
      delay(1000);
    }
    delay(1000/6);
  }
  for(int ch=15; ch>11; ch--)
  {
    mux_b.channel(ch);
    data = analogRead(sig_b);
    dataV = convert_data_to_V(data);
    print_ch_result(ch, dataV);
    if (data < min_continuityV)
    {
      Serial.println("");
      Serial.print("No Continuity in Pin ");
      Serial.print(continuity_ch_to_pin(ch, false));
      Serial.print(" || ");
      Serial.print(convert_data_to_V(data));
      Serial.println(" V");
      delay(1000);
    }
    delay(1000/6);
  }
  Serial.println(" ");
  Serial.println("====== END OF CONTINUITY TEST ======");
  Serial.println(" ");
  if(error)
  {
    while (true);
  }
}