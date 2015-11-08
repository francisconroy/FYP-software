#define FLTSDA 2
#define HINA 3
#define LINA 4
#define FLTCLRA 5

#define FLTSDB 7
#define HINB 8
#define LINB 9
#define FLTCLRB 10
  


void setup() {
  // put your setup code here, to run once:

  
  pinMode(FLTCLRA,OUTPUT);
  pinMode(HINA,OUTPUT);
  pinMode(LINA,OUTPUT);
  digitalWrite(FLTCLRA,HIGH);
  digitalWrite(HINA,LOW);
  digitalWrite(LINA,LOW);
  delay(500);
  digitalWrite(FLTCLRA,LOW);
  delay(10);
  digitalWrite(LINA,HIGH);
  delay(10);
  digitalWrite(LINA,LOW);
  delay(20);
}

void loop() {
  
  digitalWrite(LINA,LOW);
  digitalWrite(HINA,HIGH);
  delay(4);
  digitalWrite(HINA,LOW);
  digitalWrite(LINA,HIGH);
  delay(1);
  while(millis()>800)
  {
    delay(1);
  }
  // put your main code here, to run repeatedly:

}
