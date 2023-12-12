#include <LiquidCrystal.h>
const int trigPin = 9;
const int echoPin = 10;
const int red = 8;
const int green = 7;
const int yellow = 6;
int seconds = 0;
long duration;
float distance;
String detection = "Vehicle Collided";  
LiquidCrystal lcd_1(12, 11, 5, 4, 3, 2);

void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  lcd_1.begin(16, 2); // Set up the number of columns and rows on the LCD.
  
  
}

void loop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = duration*0.034/2;
  float inches = distance/2.54;
  
  if(inches<=40)
  {
    digitalWrite(13,HIGH);
    digitalWrite(red,HIGH);
    digitalWrite(green,LOW);
    digitalWrite(yellow,LOW);
  }
   if(inches>40 && inches<=80)
  {
    digitalWrite(13,LOW);
    digitalWrite(red,LOW);
    digitalWrite(green,LOW);
    digitalWrite(yellow,HIGH);
  }
  if(inches>80)
  {
    digitalWrite(13,LOW);
    digitalWrite(red,LOW);
    digitalWrite(yellow,LOW);
    digitalWrite(green,HIGH);
  }
  if (inches >= 15)
  {
    lcd_1.clear();
    lcd_1.setCursor(0, 0);
    lcd_1.print("Dist. :");
    lcd_1.print(distance);
    lcd_1.print("cm");
    lcd_1.setCursor(0, 1);
    lcd_1.print("Dist. :");
    lcd_1.print(inches);
    lcd_1.print("in");

    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.print("cm");
    Serial.print(", Inches: ");
    Serial.print(inches);
    Serial.println("in");
    delay(1000); // Wait for 1000 millisecond(s)
  }
  else
  {
    
    Serial.println(detection);
    lcd_1.setCursor(0, 0);
    lcd_1.print(detection);
    lcd_1.setCursor(0, 1);
    lcd_1.print("Calling :: 911");
  }
  
  
  
}