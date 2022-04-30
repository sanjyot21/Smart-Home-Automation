#include <DHT.h>
#define Type DHT11
int sensePin=2;
DHT HT(sensePin,Type);
float humidty;
float tempC;
float tempF;

int val;
int fanPin=9;

//Gas Sensor
int gas_sensor=A3;
int INDICATOR=A4;
void setup() {
   pinMode(fanPin,OUTPUT);
  HT.begin();
  delay(500);
  
  pinMode(INDICATOR, OUTPUT);
  pinMode(gas_sensor, INPUT);
   Serial.begin(9600);
}
void Gas_sensor()
{
  val=analogRead(gas_sensor);
    if(val>105){
    digitalWrite(INDICATOR, HIGH);
  }
  else
  digitalWrite(INDICATOR, LOW);
  Serial.println(analogRead(gas_sensor));
}
void loop() {
  // put your main code here, to run repeatedly:

  humidty=HT.readHumidity();
  tempC=HT.readTemperature();
  tempF=HT.readTemperature(true);

  Serial.print("Humidty: ");
  Serial.print(humidty);
  Serial.print(" TempC: ");
  Serial.print(tempC);
  Serial.print("C TempF: ");
  Serial.print(tempF);
  Serial.println("F ");
  if(humidty>=80){
    digitalWrite(fanPin,LOW);
    delay(2000);
  }
  else{
    digitalWrite(fanPin,HIGH);
  }
  Gas_sensor();
  delay(1000);
}
