#define D2INA 3 // pink
#define D2INB 4 // green
#define D2PWM 5 // blue

#define D1INA 8 // black
#define D1INB 10 // grey
#define D1PWM 9 // white

#define SHDN 12
#define SHUP 11

#define LED 13

#define NEUTRALBUTTON 18

#define UPTIMEON 220
#define DOWNTIMEON 220
#define HALFTIMEON 30
#define DELAYTIME 250

int shdn = 1; //not shifting
unsigned long time1 = 0;
unsigned long currtime = 0;
int shup = 1; //not shifting
//int currentGear = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(D2INA, OUTPUT);
  pinMode(D2INB, OUTPUT);
  pinMode(D2PWM, OUTPUT);
  pinMode(D1INA, OUTPUT);
  pinMode(D1INB, OUTPUT);
  pinMode(D1PWM, OUTPUT);

  pinMode(SHUP, INPUT);
  pinMode(SHDN, INPUT);

  pinMode(LED, INPUT);

  pinMode(NEUTRALBUTTON, INPUT);
  //set mode
  digitalWrite(D2INA, LOW);
  digitalWrite(D2INB, LOW); //brake to GND
  analogWriteFrequency(D2PWM, 5000);
  analogWriteFrequency(D1PWM, 5000);

  Serial.begin(9600);
  delay(2000);
  Serial.println("Starting shifter");
}

void loop() {
  shdn = digitalRead(SHDN);
  shup = digitalRead(SHUP);
  //SHIFT DOWN
  if (shdn == 0 && shup == 1)
  {
    delayMicroseconds(100);
    if (shdn == 0 && shup == 1)
    {
      Serial.println("Shift down received");
      shiftDown();
    }
  }
  //SHIFT UP
  else if (shup == 0 && shdn == 1)
  {
    delayMicroseconds(100);
    if (shup == 0 && shdn == 1)
    {
      Serial.println("Shift up received");
      shiftUp();
    }
  }
}

void shiftDown()
{
  //digitalWrite(LED, HIGH);
  digitalWrite(D2INA, HIGH);
  digitalWrite(D2INB, LOW); //brake to GND
  time1 = millis();
  currtime = time1;
  int isNeut = digitalRead(NEUTRALBUTTON);
  if (isNeut == LOW)
  {
    while ((currtime - time1) < HALFTIMEON)
    {
      currtime = millis();
      analogWrite(D2PWM, 255);
    }
  }
  else
  {
    while ((currtime - time1) < DOWNTIMEON)
    {
      currtime = millis();
      analogWrite(D2PWM, 255);
    }
  }
  digitalWrite(D2INA, LOW);
  digitalWrite(D2INB, LOW); //brake to GND
  analogWrite(D2PWM, 0);
  delay(DELAYTIME);
  //digitalWrite(LED, LOW);

}

void shiftUp()
{
  //digitalWrite(LED, HIGH);
  digitalWrite(D1INA, HIGH);
  digitalWrite(D1INB, LOW); //brake to GND
  time1 = millis();
  currtime = time1;
  int isNeut = digitalRead(NEUTRALBUTTON);
  if (isNeut == LOW)
  {
    while ((currtime - time1) < HALFTIMEON)
    {
      currtime = millis();
      analogWrite(D1PWM, 255);
    }
  }
  else
  {
    while ((currtime - time1) < UPTIMEON)
    {
      currtime = millis();
      analogWrite(D2PWM, 255);
    }
  }
  digitalWrite(D1INA, LOW);
  digitalWrite(D1INB, LOW); //brake to GND
  analogWrite(D1PWM, 0);
  delay(DELAYTIME);
  //digitalWrite(LED, LOW);

}
