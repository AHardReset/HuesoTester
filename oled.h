#include "U8glib.h"
#include "pictures.h"
//https://diyusthad.com/image2cpp
// (x ini, y ini, width/8, height)
U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NO_ACK);

bool debug = true;
int wait_after_error = 500;

void welcome_display()
{
  // (x ini, y ini, width/8, height)
  u8g.firstPage();  
  do 
  {
    u8g.drawBitmapP(0, 0, 16, 64, allegion_logo);
  } while( u8g.nextPage() );
  
}

void short_circuit_error(int ch, float dataV)
{
  int pin = short_ch_to_pin(ch);

  //Convert pin to char
  char pin_char[16];
  sprintf(pin_char, "%d", pin);

  if(debug)
  {
    //Serial warning
    Serial.println("");
    Serial.print("Short Circuit in Pin ");
    Serial.print(pin);
    Serial.print(" || ");
    Serial.print(dataV);
    Serial.println(" V");
    Serial.println("");
  }
  
  //Screen warning
  u8g.firstPage();
  do 
  {
    u8g.setFont(u8g_font_unifont);
    u8g.drawStr(2, 19, "Short Circuit");
    u8g.drawStr(2, 38, "in Pin");
    u8g.setFont(u8g_font_fub25);
    u8g.drawStr(60, 55, pin_char);
  } while( u8g.nextPage() );
  delay(wait_after_error);
}

void continuity_error(int ch, float dataV, bool first_mux)
{
  int pin = continuity_ch_to_pin(ch, first_mux);

  //Convert pin to char
  char pin_char[16];
  sprintf(pin_char, "%d", pin);

  if(debug){
    Serial.println("");
    Serial.print("No Continuity in Pin ");
    Serial.print(pin);
    Serial.print(" || ");
    Serial.print(dataV);
    Serial.println(" V");
  }

  //Screen warning
  u8g.firstPage();
  do 
  {
    u8g.setFont(u8g_font_unifont);
    u8g.drawStr(2, 19, "No Enough Continuity");
    u8g.drawStr(2, 38, "in Pin");
    u8g.setFont(u8g_font_fub25);
    u8g.drawStr(60, 55, pin_char);
  } while( u8g.nextPage() );

  delay(wait_after_error);
}

void test_success()
{
  u8g.firstPage();
  do 
  {
    u8g.setFont(u8g_font_fub25);
    u8g.drawStr(2, 19, "All Ok");
  } while( u8g.nextPage() );
}
