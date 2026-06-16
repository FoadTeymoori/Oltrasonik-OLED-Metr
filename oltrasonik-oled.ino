//FoadTeymoori
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h> 
#include <Adafruit_SSD1306.h> 
Adafruit_SSD1306 display(-1); 
    long duration;
    int distance;
    const int trig = 7;
    const int echo = 6;
    void setup() {
    pinMode(trig, OUTPUT); 
    pinMode(echo, INPUT);
    }
    void loop() {
  distance = calculateDistance();
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE); 
  display.setCursor(10,10);
  display.println(distance);
  display.setCursor(50,10);
  display.println("cm");
  display.setCursor(0,0);
  display.setTextSize(1);
  display.println("(:");
  display.display();
}
  int calculateDistance(){ 
  digitalWrite(trig, LOW); 
  delayMicroseconds(2);
  digitalWrite(trig, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH); 
  distance= duration*0.034/2;
  return distance;
}