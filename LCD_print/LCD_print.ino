#include <rgb_lcd.h>

rgb_lcd lcd;

const int R = 0;
const int G = 200;
const int B = 0;

void setup() {
    // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
    lcd.setRGB(R, G, B);
    
    lcd.print("Hello World!!!");
    delay(1000);
}

void loop() {
}
