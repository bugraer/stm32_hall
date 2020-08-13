#include "U8glib.h"


U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE|U8G_I2C_OPT_DEV_0);  // I2C / TWI 

void sayfaYazdir() {
  u8g.setFont(u8g_font_unifont);
  u8g.drawStr( 0, 11, "        hfhfg");
  u8g.drawStr( 0, 22, "    fghgfh   ");
  u8g.drawStr( 0, 33, "   hfhf     g");
  u8g.drawStr( 0, 44, "hfhf        g");
  u8g.drawStr( 0, 55, "gfdgfd       ");
  u8g.drawStr( 0, 66, "   f  56    g");
}

void setup(void) {
  
}

void loop(void) {
  // picture loop
  u8g.firstPage();
  int i = 0;
  do {
    sayfaYazdir();
  } while( u8g.nextPage() );
  
  delay(1000);
}

