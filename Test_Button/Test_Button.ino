#include <Adafruit_NeoPixel.h>
#define PIN        9 // On Trinket or Gemma, suggest changing this to 1
#define NUMPIXELS 16 // Popular NeoPixel ring size


Adafruit_NeoPixel pixels (NUMPIXELS, 9, NEO_GRB + NEO_KHZ800);

#include <Wire.h> // Enable this line if using Arduino Uno, Mega, etc.
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"

Adafruit_7segment matrix1 = Adafruit_7segment();
Adafruit_7segment matrix2 = Adafruit_7segment();

int x;
int y;


#define RED 943
#define ORANGE 8
#define YELLOW 350
#define GREEN 900
#define BLUE 400
#define PURPLE 800

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
#ifndef __AVR_ATtiny85__
  Serial.begin(9600);
  Serial.println("7 Segment Backpack Test");
#endif
  matrix1.begin(0x70);
//  matrix2.begin(0x72)
  pixels.begin();
}

void loop() {
  // put your main code here, to run repeatedly:

  x = analogRead(3);
  // Displaying value of Pentiometer 1
  matrix1.print(x);
  matrix1.writeDisplay();
  delay(50);

  /*  y = analogRead(2);
    // Displaying value of Pentiometer 2
    matrix.print(y);
    matrix.writeDisplay();
    delay(50); */

  if ((x > GREEN) && (y > GREEN)) {
    Serial.println("GREEN");
    Serial.println(x);
    Serial.println(y);
    for (int i = 0; i < NUMPIXELS; i++) {
      pixels.setPixelColor(i, pixels.Color(0, 150, 0));
    }
  }

  if ((x == RED) && (y == RED)) {
    Serial.println("RED");
    Serial.println(x);
    Serial.println(y);
    for (int i = 0; i < NUMPIXELS; i++) {
      pixels.setPixelColor(i, pixels.Color(150, 0, 0));
    }
  }

    if ((x == BLUE) && (y == BLUE)) {
    Serial.println("BLUE");
    Serial.println(x);
    Serial.println(y);
    for (int i = 0; i < NUMPIXELS; i++) {
      pixels.setPixelColor(i, pixels.Color(0, 0, 150));
    }
  }

  if ((x == BLUE) && (y < RED)) {
    Serial.println("PURPLE");
    Serial.println(x);
    Serial.println(y);
    for (int i = 0; i < NUMPIXELS; i++) {
      pixels.setPixelColor(i, pixels.Color(50, 0, 150));
    }
  }

  if ((x / 2 == RED) && (y < GREEN)) {
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
