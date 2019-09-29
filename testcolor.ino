#include "colorfade.h"

void setup() {
  Serial.begin(9600);
  Serial.println(F("colorfade test"));
  color onColor = { 255, 0,0 };
  color offColor = { 0 , 0, 255 };
  SetColors(offColor, onColor);
}

void loop() {
   bool flux = true;
   while (true) {
      if(!UpdateColor(flux))
         flux = !flux; // no flux given
      color outputColor;
      GetCurrentColor(outputColor);
      Serial.print("flux= ");
      Serial.print(flux);
      Serial.print(" R= ");
      Serial.print(outputColor.r);
      Serial.print(" G= ");
      Serial.print(outputColor.g);
      Serial.print(" B= ");
      Serial.println(outputColor.b);
      delay(100);
   }
}
