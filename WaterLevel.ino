#include <LiquidCrystal.h>

// LCD Pin Mapping
LiquidCrystal lcd(1, A1, A2, A3, A4, A5);

// Hardware Pin Definitions
const int sensorPin = A0;      // Water Tank Sensor
const int buzzerPin = 0;       // Buzzer
const int drainPumpPin = 7;    // Motor 1: Pumps OUT 
const int fillPumpPin = 6;     // Motor 2: Pumps IN 

// Thresholds
const int emptyLevel = 300;  
const int mediumLevel = 750;

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(drainPumpPin, OUTPUT); 
  pinMode(fillPumpPin, OUTPUT);  
  
  lcd.begin(16, 2);
  lcd.print("Water Monitor");
  lcd.setCursor(0, 1);
  lcd.print("System Starting");
  delay(2000);
  lcd.clear();
}

void loop() {
  int sensorValue = analogRead(sensorPin);

  // Logic for Dual-Pump System
  if (sensorValue <= emptyLevel) {
    lcd.setCursor(0, 0);
    lcd.print("Level: Low      "); 
    lcd.setCursor(0, 1);
    lcd.print("State: FILLING  "); 
    digitalWrite(fillPumpPin, HIGH);  
    digitalWrite(drainPumpPin, LOW);  
    digitalWrite(buzzerPin, LOW); 
    
  } else if (sensorValue > emptyLevel && sensorValue <= mediumLevel) {
    lcd.setCursor(0, 0);
    lcd.print("Level: Medium   ");
    lcd.setCursor(0, 1);
    lcd.print("State: STABLE   ");
    digitalWrite(fillPumpPin, LOW);   
    digitalWrite(drainPumpPin, LOW);  
    digitalWrite(buzzerPin, LOW); 
    
  } else { // High Level
    lcd.setCursor(0, 0);
    lcd.print("Level: HIGH!    ");
    lcd.setCursor(0, 1);
    lcd.print("State: DRAINING!");
    digitalWrite(fillPumpPin, LOW);   
    digitalWrite(drainPumpPin, HIGH); 
    digitalWrite(buzzerPin, HIGH);    
  }

  delay(250); 
}