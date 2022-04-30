String s;
void setup() {
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  Serial.begin(9600);
  //digitalWrite(3,HIGH);
  //digitalWrite(2,HIGH);
}
void Fan_switch(String s){
   if(s.equalsIgnoreCase("Jarvis Fan on")){
      Serial.println("Yes Boss, switching Fan on");
      digitalWrite(2,LOW);
  }
  else if(s.equalsIgnoreCase("Jarvis Fan off")){
      Serial.println("Yes Boss, switching Fan off");
      digitalWrite(2,HIGH);
  }
}

void Light_switch(String s){
  if(s.equalsIgnoreCase("Jarvis Light on")){
     Serial.println("Yes Boss, switching Lights on");
     digitalWrite(3,LOW);
  }
  else if(s.equalsIgnoreCase("Jarvis Light off")){
    Serial.println("Yes Boss, switching Lights off");
    digitalWrite(3,HIGH);
  }
  
}
void loop() {
  
  
  s=Serial.readString();
  Fan_switch(s);
  Light_switch(s);
  Serial.println(s);

}
