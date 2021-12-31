// Arduino Bluetooth-Controlled-Car
// Contact me on github for any question (github acc: OmarKhalil10).

char t;

void setup() {
pinMode(13,OUTPUT);   //left motors forward
pinMode(12,OUTPUT);   //left motors reverse
pinMode(11,OUTPUT);   //right motors forward
pinMode(10,OUTPUT);   //right motors reverse
pinMode(9,OUTPUT);    //Back Flash 
pinMode(8,OUTPUT);    //Front Flash 
pinMode(7,OUTPUT);    //Horn  
pinMode(A5, OUTPUT);  //Left Red
pinMode(A4, OUTPUT);  //Middle Red
pinMode(A3, OUTPUT);  //Right Red
pinMode(A2, OUTPUT);  //Left Blue
pinMode(A1, OUTPUT);  //Middle Blue
pinMode(A0, OUTPUT);  //Right Blue

Serial.begin(9600);
 
}
 
void loop() {
if(Serial.available()){
  t = Serial.read();
  Serial.println(t);
}
 
if(t == 'F'){            //move forward(all motors rotate in forward direction)
  digitalWrite(13,HIGH);
  digitalWrite(11,HIGH);
  digitalWrite(9,LOW);
}
 
else if(t == 'B'){      //move reverse (all motors rotate in reverse direction)
  digitalWrite(12,HIGH);
  digitalWrite(10,HIGH);
  digitalWrite(9,HIGH);
}
 
else if(t == 'R'){      //turn right (left side motors rotate in forward direction, right side motors doesn't rotate)
  digitalWrite(11,HIGH);
}
 
else if(t == 'L'){       //turn left (right side motors rotate in forward direction, left side motors doesn't rotate)
  digitalWrite(13,HIGH);
}
else if(t == 'U'){       //turn back led on or off)
  digitalWrite(9,HIGH);
}
else if(t == 'u'){
  digitalWrite(9,LOW);
}
else if(t == 'W'){       //turn Front Led on or off)
  digitalWrite(8,HIGH);
}
else if(t == 'w'){
  digitalWrite(8,LOW);
}
else if(t == 'S'){       //STOP (all motors stop)
  digitalWrite(13,LOW);
  digitalWrite(12,LOW);
  digitalWrite(11,LOW);
  digitalWrite(10,LOW);
}
else if(t == 'V'){    //turn Horn on or off)
  digitalWrite(7,HIGH);
}
else if(t == 'v'){
  digitalWrite(7,LOW);
}
else if(t == 'X'){    //turn Extra (Police light) on or off)
  for (int i=0;i<=6;i++){
  digitalWrite(A5, HIGH);   
  digitalWrite(A4, HIGH);
  digitalWrite(A2, HIGH);
  digitalWrite(A1,  HIGH);
  delay(50);
  digitalWrite(A5, LOW);
  digitalWrite(A4, LOW);
  digitalWrite(A2, LOW);
  digitalWrite(A1, LOW);
  delay(50);
    
  /////LED Alternate sides/////
  digitalWrite(A3, HIGH);   
  digitalWrite(A4, HIGH);
  digitalWrite(A0, HIGH);
  digitalWrite(A1,  HIGH);
  delay(50);
  digitalWrite(A3, LOW);
  digitalWrite(A4, LOW);
  digitalWrite(A0, LOW);
  digitalWrite(A1, LOW);
  delay(50);
}}
else if(t == 'x'){
  digitalWrite(A5, LOW);   
  digitalWrite(A4, LOW);
  digitalWrite(A3, LOW);
  digitalWrite(A2, LOW);
  digitalWrite(A1, LOW);
  digitalWrite(A0, LOW);
}
delay(100);
}
