  int FLTCLR = 2;
  int HIN = 4;
  int LIN = 3;


void setup() {
  // put your setup code here, to run once:

  
  pinMode(FLTCLR,OUTPUT);
  pinMode(HIN,OUTPUT);
  pinMode(LIN,OUTPUT);
  digitalWrite(FLTCLR,HIGH);
  digitalWrite(HIN,LOW);
  digitalWrite(LIN,LOW);
  delay(500);
  digitalWrite(FLTCLR,LOW);
  delay(10);
  digitalWrite(LIN,HIGH);
  delay(10);
  digitalWrite(LIN,LOW);
  delay(20);
}

void loop() {
  
  digitalWrite(LIN,LOW);
  digitalWrite(HIN,HIGH);
  delay(4);
  digitalWrite(HIN,LOW);
  digitalWrite(LIN,HIGH);
  delay(1);
  while(millis()>800)
  {
    delay(1);
  }
  // put your main code here, to run repeatedly:

}
