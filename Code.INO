#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <dht.h>

dht DHT;


#define DHT22_PIN 2     // DHT 22  (AM2302) - pin used for DHT22 
LiquidCrystal_I2C lcd(0x27,16,2);

float hum;  //Stores humidity value
float temp;

int sensor_pin = A0; // Soil Sensor input at Analog PIN A0
int output_value ;


void setup() {
    Serial.begin(9600);
    lcd.init();                      // initialize the lcd 
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setBacklight(HIGH);


  // put your setup code here, to run once:
  pinMode(4,OUTPUT);
     Serial.begin(9600);
   Serial.println("Reading From the Sensor ...");
   delay(2000);

   
}


  // put your main code here, to run repeatedly:

  void loop() {
int chk = DHT.read22(DHT22_PIN);
    //Read data and store it to variables hum and temp
    hum = DHT.humidity;
    temp= DHT.temperature;
    //Print temp and humidity values to LCD
    lcd.setCursor(0,0);
    lcd.print("Humidity: ");
    lcd.print(hum);
    lcd.print("%");
    lcd.setCursor(0,1);
    lcd.print("Temp: "); 
    lcd.print(temp);
    lcd.println("Celcius");
    delay(2000);
    
   output_value= analogRead(sensor_pin);
 output_value = map(output_value,550,10,0,100);
   Serial.print("Mositure : ");
   Serial.print(output_value);
   Serial.println("%");
   if(output_value<0){
      digitalWrite(4,HIGH);
     }
     else{
            digitalWrite(4,LOW);
     }
   delay(1000);
}
