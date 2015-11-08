#define FLTSDA 2
#define HINA 3
#define LINA 4
#define FLTCLRA 5

#define FLTSDB 7
#define HINB 8
#define LINB 9
#define FLTCLRB 10

int direction = 0;


void setup() {
  // put your setup code here, to run once:
  pinMode(FLTCLRA,OUTPUT);
  pinMode(HINA,OUTPUT);
  pinMode(LINA,OUTPUT);
  pinMode(FLTSDA,OUTPUT);
  
  pinMode(FLTCLRB,OUTPUT);
  pinMode(HINB,OUTPUT);
  pinMode(LINB,OUTPUT);
  pinMode(FLTSDB,OUTPUT);

digitalWrite(FLTSDB,HIGH);
digitalWrite(FLTSDA,HIGH);
  
  digitalWrite(FLTCLRA,HIGH);
  digitalWrite(FLTCLRB,HIGH);

  // directional code
  digitalWrite(HINB,LOW);
  digitalWrite(LINB,LOW);
  delay(500);
  digitalWrite(FLTCLRB,LOW);
  delay(10);
  digitalWrite(LINB,HIGH);
  delay(10);
  digitalWrite(LINB,LOW);
  delay(20);
}

void loop() {
  
  
  digitalWrite(LINB,LOW);
  digitalWrite(HINB,HIGH);
  delay(4);
  digitalWrite(HINB,LOW);
  digitalWrite(LINB,HIGH);
  delay(1);
  while(millis()>800)
  {
    delay(1);
  }
  // put your main code here, to run repeatedly:

}
