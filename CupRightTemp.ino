#include <dht.h>
dht DHT;
#define DHT11_PIN 7 //Assigning temperature sensor to pin 7

void setup() {
  Serial.begin(9600);
}

void loop()
{
  int sensorValue = DHT.read11(DHT11_PIN); //Reads temperature and humidity from sensor
  int temperature = DHT.temperature;
  int humidity = DHT.humidity;
  
  Serial.print("Temperature = "); //Next 4 for debugging
  Serial.println(temperature);
  Serial.print("Humidity = ");
  Serial.println(humidity);
  
  if (humidity >= 10) { //Makes sure enough water is detected for accurate measurement
    if (temperature > 60) {
      digitalWrite(11, HIGH); //Lights Pin 11 Red LED if too hot
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
    } else {
      if (temperature > 25) {
        digitalWrite(10, HIGH); //Lights Pin 10 Green LED if just right
        digitalWrite(9, LOW);
        digitalWrite(11, LOW);
      } else {
        if (temperature <= 25) {
          digitalWrite(9, HIGH); //Lights Pin 9 Blue LED if too cold
          digitalWrite(10, LOW);
          digitalWrite(11, LOW);
        } else {
          Serial.println("No temperature could be detected");
        }
      }
    }
  } else {
    Serial.println("Liquid cannot be detected"); //If small humidity more liquid needs to be poured for accurate reading
  }
  delay(2000);
}
