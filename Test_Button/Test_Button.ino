#include <Adafruit_NeoPixel.h>
#define PIN        9 // On Trinket or Gemma, suggest changing this to 1
#define NUMPIXELS 16 // Popular NeoPixel ring size


Adafruit_NeoPixel pixels (NUMPIXELS, 9, NEO_GRB + NEO_KHZ800);

int x;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  // pinMode(5, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  pixels.begin();
  x = digitalRead(5);
  //Serial.println(x);
  delay(200);

  if (x == 0) {
    Serial.println("GREEN");
    for (int i = 0; i < NUMPIXELS; i++) {
      pixels.setPixelColor(i, pixels.Color(0, 150, 0));
    }
  }
  if (x == 1) {
    Serial.println("RED");
    for (int i = 0; i < NUMPIXELS; i++) {
      pixels.setPixelColor(i, pixels.Color(150, 0, 0));
    }
  }
  pixels.show();
  pixels.clear();
}
