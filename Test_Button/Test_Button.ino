#include <Adafruit_NeoPixel.h>
#define PIN        9 // On Trinket or Gemma, suggest changing this to 1
#define NUMPIXELS 16 // Popular NeoPixel ring size


Adafruit_NeoPixel pixels (NUMPIXELS, 9, NEO_GRB + NEO_KHZ800);

#include <Wire.h> // Enable this line if using Arduino Uno, Mega, etc.
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"

Adafruit_7segment matrix = Adafruit_7segment();

int x;
int y;


#define Red 943
#define Orange 8
#define Yellow 350
#define Green 1023
#define Blue 400
#define Purple 800

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
#ifndef __AVR_ATtiny85__
  Serial.begin(9600);
  Serial.println("7 Segment Backpack Test");
#endif
  matrix.begin(0x70);
}

void loop() {
  // put your main code here, to run repeatedly:
  pixels.begin();
  x = analogRead(3);
  y = analogRead(2);
  //  Serial.println(x);
  delay(200);

  // Displaying value of Pentiometer 1
  matrix.print(x);
  matrix.writeDisplay();
  delay(50);

  // Displaying value of Pentiometer 2
  matrix.print(y);
  matrix.writeDisplay();
  delay(50);

  if ((x == Green) && (y == Green)) {
    Serial.println("GREEN");
    Serial.println(x);
    Serial.println(y);
    for (int i = 0; i < NUMPIXELS; i++) {
      pixels.setPixelColor(i, pixels.Color(0, 150, 0));
    }
  }

  if ((x == Red) && (y == Red)) {
    Serial.println("RED");
    Serial.println(x);
    Serial.println(y);
    for (int i = 0; i < NUMPIXELS; i++) {
      pixels.setPixelColor(i, pixels.Color(150, 0, 0));
    }
  }

  if ((x > Blue) && (y < Red)) {
    Serial.println("PURPLE");
    Serial.println(x);
    Serial.println(y);
    for (int i = 0; i < NUMPIXELS; i++) {
      pixels.setPixelColor(i, pixels.Color(50, 0, 150));
    }
  }

  if ((x / 2 < Red) && (y < Green)) {
    Serial.println("YELLOW");
    Serial.println(x);
    Serial.println(y);
    for (int i = 0; i < NUMPIXELS; i++) {
      pixels.setPixelColor(i, pixels.Color(100, 150, 0));
    }
  }

  pixels.show();
  pixels.clear();
}
