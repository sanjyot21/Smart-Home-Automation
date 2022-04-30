#include <Servo.h>

Servo myservo;
               
int pirPin = 2;                 
int pirStat = 0;
int pos = 0;

int ultra_trig=7;
int ultra_echo=8;
int RED_passage=9;
int GREEN_passage=10;
int WHITE_passage=13;

int PIR_sense=1;
Servo myServo;
int duration;
float cm;
void setup() {
   pinMode(pirPin, INPUT);
   myservo.attach(3);  
   Serial.begin(9600);
   pinMode(ultra_echo, INPUT);
   pinMode(ultra_trig, OUTPUT);
   pinMode(RED_passage, OUTPUT);
   pinMode(GREEN_passage, OUTPUT);
   pinMode(WHITE_passage, OUTPUT);
  
Serial.begin(9600);
}
void Door(){
  pirStat = digitalRead(pirPin); 
  
 if (pirStat == HIGH) {            
   
   
   Serial.println("OPENING THE DOOR");

   
    for (pos = 90; pos >= 0; pos -= 1) { 
    myservo.write(pos);              
    delay(15);                       
   }
   delay(1000);
   for (pos = 0; pos <= 110; pos += 1) { 
    
    myservo.write(pos);              
    delay(15);                       
   } 
    
 } 
 else {
 }
}
void Passage_Light(){
   digitalWrite(ultra_trig,HIGH);
   delayMicroseconds(10);
   digitalWrite(ultra_trig,LOW);
   duration=pulseIn(ultra_echo,HIGH);
   cm=duration*0.034/2;
  Serial.println(cm);
  if(cm>35){
    digitalWrite(RED_passage,HIGH);
     digitalWrite(GREEN_passage,LOW);
    digitalWrite(WHITE_passage,LOW);
  }
  else if(cm>10){
    digitalWrite(GREEN_passage,HIGH);
    digitalWrite(RED_passage,LOW);
    digitalWrite(WHITE_passage,LOW);
    
  }
  else{
    digitalWrite(WHITE_passage,HIGH);
    digitalWrite(GREEN_passage,LOW);
    digitalWrite(RED_passage,LOW);
  }
  //lcd.print(cm);
  delay(500);
}


void loop() {
  Door();
  Passage_Light();
 
}
