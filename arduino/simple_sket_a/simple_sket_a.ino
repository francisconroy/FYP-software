#define FLTSDA 2
#define HINA 3
#define LINA 4
#define FLTCLRA 5

#define FLTSDB 7
#define HINB 8
#define LINB 9
#define FLTCLRB 10

#define SHDN 12 // pin for downshift
#define LED 13 //led pin


int direction = 0;
int buttonstate = 1; //active low


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
  
  pinMode(SHDN, INPUT);
  pinMode(LED,OUTPUT);

digitalWrite(FLTSDB,HIGH);
digitalWrite(FLTSDA,HIGH);
//delay(500);
starta();
startb();
}

void loop() {
  buttonstate = digitalRead(SHDN);
  if(buttonstate == 0)
  {
    digitalWrite(LED,HIGH);
    digitalWrite(LINA,LOW);
  digitalWrite(HINA,HIGH);
  delay(9);
  //digitalWrite(HINB,LOW);
  //digitalWrite(LINB,HIGH);
    digitalWrite(HINA,LOW);
  digitalWrite(LINA,HIGH);
  delay(1);
    }
    else
    {
      digitalWrite(LED,LOW); //test led
        //digitalWrite(HINB,LOW);
  //digitalWrite(LINB,LOW);
          digitalWrite(HINA,LOW);
  digitalWrite(LINA,LOW);
      }
  // put your main code here, to run repeatedly:

}

void starta(void)
{
  digitalWrite(FLTCLRA,HIGH);
  digitalWrite(HINA,LOW); //turn HO off
  delay(10);
  digitalWrite(LINA,HIGH); // charge bootstrap cap
  delay(20);
  digitalWrite(LINA,LOW);
  delay(10);
  digitalWrite(FLTCLRA,LOW);
  }

  void startb(void)
  {
  digitalWrite(FLTCLRB,HIGH);
  digitalWrite(HINB,LOW); //turn HO off
  delay(10);
  digitalWrite(LINB,HIGH); // charge bootstrap cap
  delay(20);
  digitalWrite(LINB,LOW);
  delay(10);
  digitalWrite(FLTCLRB,LOW);
    }
