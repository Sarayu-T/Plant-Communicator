 #include "DHT.h" //humidity & temperature
 #define DHTPIN 2 
 #define DHTTYPE DHT11
 #include <Wire.h>           // ADDRESS of lcd 
 #include <LiquidCrystal_I2C.h>    // lcd library
 LiquidCrystal_I2C lcd(0x27,16,2); // 16col x2row
 DHT dht(DHTPIN,DHT11); //data pin #, type of sensor
 const int sensor_pin = A0; 
 void setup()  
 {  
  Serial.begin(9600);  // baud rate
  lcd.init();      // initialize
  lcd.backlight(); // green light
  dht.begin();  
 }  
 void loop()  
 {  
  delay(2000);
  float moisture_percentage;
  moisture_percentage = ( 101.00 - ( (analogRead(sensor_pin)/1023.00) * 100.00 ) );
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
      Serial.println("Failed to read from DHT sensor!");
      return;
   }  
  
  Serial.print("Soil Moisture %: ");
  Serial.print(moisture_percentage);
  Serial.println("%");
   Serial.print("Temperature in Celsius:");  
   Serial.print(t); 
   Serial.println(" *C"); 
   Serial.print("Humidity% :");  
   Serial.println(h);  
   delay(5000);  
   if(moisture_percentage>50 && h>40 && h<=70 && t>0 && t<=35)
  {
    lcd.clear();
    lcd.setCursor(0,0);  
    lcd.print("   Plant is ");  
    lcd.setCursor(0,1);  
    lcd.print("  HAPPY :)) ");  
  }    
  else
  {
    lcd.clear();
    lcd.setCursor(0,0);  
    lcd.print("    Plant is  ");  
    lcd.setCursor(0,1);  
    lcd.print("  SAD :(( ");
  }
 }  