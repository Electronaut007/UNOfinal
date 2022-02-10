#include <Arduino.h>
#include<SoftwareSerial.h>
#include<Adafruit_Sensor.h>
#include<DHT.h>
#include <Adafruit_BusIO_Register.h>

SoftwareSerial nodemcu(2,3);

#define DHT1 8
#define DHT2 9
#define DHT3 4
#define DHT4 12
#define DHTTYPE DHT11
DHT dht1(DHT1, DHTTYPE);
DHT dht2(DHT2, DHTTYPE);
DHT dht3(DHT3, DHTTYPE);
DHT dht4(DHT4, DHTTYPE);

int LM35= A0;
int Soil_Sensor= A1;

float d1= 0;
float d2= 0;
float d3= 0;
float d4= 0;
int L5= 0;
int S6= 0;

String cdata;

void setup()
{
  Serial.begin(9600);
  nodemcu.begin(9600);
  dht1.begin();
  dht2.begin();
  dht3.begin();
  dht4.begin();
  pinMode(LM35, INPUT);
  pinMode(Soil_Sensor, INPUT);
  
}

void loop()
{
  d1= dht1.readTemperature();
  d2= dht2.readTemperature();
  d3= dht3.readTemperature();
  d4= dht4.readTemperature();
 int val= analogRead(LM35);
 int mv= (val/1024)*5000;
 int cel= mv/10;
 L5= cel;
 S6= analogRead(Soil_Sensor);
 cdata= cdata+ d1 +","+d2+ "," +d3+ "," +d4+ "," +L5+ "," +S6;
 Serial.println(cdata);
 nodemcu.println(cdata);
 delay(2000);
cdata="";
delay(5000);
}