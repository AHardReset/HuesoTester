int short_ch_to_pin(int ch)
{
  switch (ch) {
  case 15: return 2;
  case 14: return 6;
  case 13: return 10;
  case 12: return 14;
  case 11: return 18;
  case 10: return 19;
  case 9: return 15;
  case 8: return 11;
  case 7: return 7;
  case 6: return 3;
  default: 
    Serial.println("");
    Serial.println("SOMETHING WENT WRONG!!!");
    return -1;
  }
}

float convert_data_to_V(int data)
{
  return (data*5) / 1023.0;
}

int continuity_ch_to_pin(int ch, bool first_mux)
{

  if(first_mux)
  {
    switch (ch) {
      case 15: return 2;
      case 14: return 6;
      case 13: return 10;
      case 12: return 14;
      case 11: return 18;
      case 10: return 19;
      case 9: return 15;
      case 8: return 11;
      case 7: return 7;
      case 6: return 3;
      case 5: return 4;
      case 4: return 8;
      case 3: return 12;
      case 2: return 16;
      case 1: return 20;
      case 0: return 17;
      default: 
        Serial.println("");
        Serial.println("SOMETHING WENT WRONG!!!");
        return -1;
    }
  }

  else {
    switch (ch) {
      case 15: return 13;
      case 14: return 9;
      case 13: return 5;
      case 12: return 1;
      default: 
        Serial.println("");
        Serial.println("SOMETHING WENT WRONG!!!");
        return -1;
    }
  }
  
}

void print_ch_result(int ch, float dataV)
{
  Serial.print(ch);
  Serial.print(" ");
  Serial.print(dataV);
  Serial.print("V || ");
}

