
#include <ESP8266WiFi.h>
#include "AdafruitIO_WiFi.h"
#include "DHT.h"
const char* ssid = "OPPO A59 5G";
const char* password = "123456789";
#define IO_USERNAME  "divya_2416"
#define IO_KEY       "aio_Gyou399qpjZmkZ3hveiiHV9iW1fm"
AdafruitIO_WiFi io(IO_USERNAME, IO_KEY, ssid, password);
AdafruitIO_Feed *temperatureFeed   = io.feed("temperature");
AdafruitIO_Feed *humidityFeed      = io.feed("humidity");
AdafruitIO_Feed *tank1Feed         = io.feed("tank1");
AdafruitIO_Feed *tank2Feed         = io.feed("tank2");
AdafruitIO_Feed *soilFeed          = io.feed("soil");
AdafruitIO_Feed *motorFeed         = io.feed("motor_status"); 
#define DHTPIN D2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
#define TRIG1 D4
#define ECHO1 D3
#define TRIG2 D7
#define ECHO2 D8

#define SOIL_PIN A0
#define RELAY1 D5
#define RELAY2 D6
#define WATER_THRESHOLD 20
#define TEMP_THRESHOLD 15
#define POT_THRESHOLD 1000
void setup()
 {
  Serial.begin(115200);
  dht.begin();
  pinMode(TRIG1, OUTPUT);
  pinMode(ECHO1, INPUT);
  pinMode(TRIG2, OUTPUT);
  pinMode(ECHO2, INPUT);
  pinMode(SOIL_PIN, INPUT);
  pinMode(RELAY1, OUTPUT);
  pinMode(RELAY2, OUTPUT);
  digitalWrite(RELAY1, LOW);
  digitalWrite(RELAY2, LOW);
 io.connect();
  while(io.status() < AIO_CONNECTED) 
{
    Serial.print(".");
    delay(500);
  }
  Serial.println("\nConnected to Adafruit IO!");
}
long measureDistance(int trigPin, int echoPin)
 {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH, 30000);
  if(duration == 0) return -1;
  long distance = duration * 0.034 / 2;
  return distance;
}
void loop()
 {
  io.run();
   float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  long tank1Distance = measureDistance(TRIG1, ECHO1);
  long tank2Distance = measureDistance(TRIG2, ECHO2);
  int soilValue = analogRead(SOIL_PIN);

  int motorStatus = 0;
   if (tank1Distance > 0 && tank1Distance < WATER_THRESHOLD && temperature > TEMP_THRESHOLD && soilValue < POT_THRESHOLD)
 {
    digitalWrite(RELAY1, HIGH);
    digitalWrite(RELAY2, LOW);
    motorStatus = 1;
    Serial.println("Action: Tank1 needs water → Motor1 ON | Motor2 OFF");
  }
  else if (tank2Distance > 0 && tank2Distance < WATER_THRESHOLD && tank2Distance < tank1Distance && temperature > TEMP_THRESHOLD && soilValue < POT_THRESHOLD)
 {
    digitalWrite(RELAY1, LOW);
    digitalWrite(RELAY2, HIGH);
    motorStatus = 2;
    Serial.println("Action: Tank2 needs water → Motor2 ON | Motor1 OFF");
  }
  else 
{
    digitalWrite(RELAY1, LOW);
    digitalWrite(RELAY2, LOW);
    motorStatus = 0;
    Serial.println("Action: Conditions not met → Motor1 & Motor2 OFF");
  }
  temperatureFeed->save(temperature);
  humidityFeed->save(humidity);
  tank1Feed->save(tank1Distance);
  tank2Feed->save(tank2Distance);
  soilFeed->save(soilValue);
  motorFeed->save(motorStatus);
Serial.println("==== SMART IRRIGATION STATUS ====");
  Serial.printf("Temperature: %.1f°C | Humidity: %.1f%%\n", temperature, humidity);
  Serial.printf("Tank1 Water Level: %ld cm | Tank2 Water Level: %ld cm\n", tank1Distance, tank2Distance);
  Serial.printf("Soil Moisture (Analog): %d\n", soilValue);
  Serial.printf("Motor Status: %d\n", motorStatus);
  Serial.println("================================\n");
  delay(5000);
}
