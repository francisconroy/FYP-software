#define D2INA 3
#define D2INB 4
#define D2PWM 5

#define D1INA 8
#define D1INB 10
#define D1PWM 9

#define SHDN 12
#define SHUP 11

#define LED 13

#define TIMEON 60
#define NEUTRALTIMEON 20

int shdn = 1; //not shifting
unsigned long time1 = 0;
unsigned long currtime = 0;
int shup = 1; //not shifting
int currentGear = 0;

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

  pinMode(LED, OUTPUT);
  //set mode
  digitalWrite(D2INA, LOW);
  digitalWrite(D2INB, LOW); //brake to GND
  analogWriteFrequency(D2PWM, 5000);
  analogWriteFrequency(D1PWM, 5000);


  Serial.begin(9600);
}

void loop() {
  //SHIFT DOWN
  shdn = digitalRead(SHDN);
  if (shdn == 0 && shup == 1)
  {
    Serial.print("Shift down received");
    if (currentGear == 1)
    {
      shift1toN();
    }
    else
    {
      shiftDown();
    }
  }


  //SHIFT UP
  shup = digitalRead(SHUP);
  if (shup == 0 && shdn == 1)
  {
    Serial.print("Shift up received");
    if (currentGear == 0)
    {
      shiftNto1();
    }
    else
    {
      shiftUp();
    }
  }
}

void shiftDown()
{
  if (currentGear > 1 && currentGear <= 6)
  {
    digitalWrite(LED, HIGH);
    digitalWrite(D2INA, HIGH);
    digitalWrite(D2INB, LOW); //brake to GND
    time1 = millis();
    currtime = time1;
    while ((currtime - time1) < TIMEON)
    {
      currtime = millis();
      analogWrite(D2PWM, 255);
    }
    digitalWrite(D2INA, LOW);
    digitalWrite(D2INB, LOW); //brake to GND
    analogWrite(D2PWM, 0);
    delay(1000);
    digitalWrite(LED, LOW);
    currentGear--;
  }
}

void shiftUp()
{
  if (currentGear >= 1 && currentGear < 6)
  {
    digitalWrite(LED, HIGH);
    digitalWrite(D1INA, HIGH);
    digitalWrite(D1INB, LOW); //brake to GND
    time1 = millis();
    currtime = time1;
    while ((currtime - time1) < TIMEON)
    {
      currtime = millis();
      analogWrite(D1PWM, 255);
    }
    digitalWrite(D1INA, LOW);
    digitalWrite(D1INB, LOW); //brake to GND
    analogWrite(D1PWM, 0);
    delay(1000);
    digitalWrite(LED, LOW);
    currentGear++;
  }
}

void shift1toN()
{
  if (currentGear == 1)
  {
    digitalWrite(LED, HIGH);
    digitalWrite(D1INA, HIGH);
    digitalWrite(D1INB, LOW); //brake to GND
    time1 = millis();
    currtime = time1;
    while ((currtime - time1) < NEUTRALTIMEON)
    {
      currtime = millis();
      analogWrite(D1PWM, 255);
    }
    digitalWrite(D1INA, LOW);
    digitalWrite(D1INB, LOW); //brake to GND
    analogWrite(D1PWM, 0);
    delay(1000);
    digitalWrite(LED, LOW);
    currentGear--;
  }
}

void shiftNto1()
{
  if (currentGear == 0)
  {
    digitalWrite(LED, HIGH);
    digitalWrite(D2INA, HIGH);
    digitalWrite(D2INB, LOW); //brake to GND
    time1 = millis();
    currtime = time1;
    while ((currtime - time1) < TIMEON)
    {
      currtime = millis();
      analogWrite(D2PWM, 255);
    }
    digitalWrite(D2INA, LOW);
    digitalWrite(D2INB, LOW); //brake to GND
    analogWrite(D2PWM, 0);
    delay(1000);
    digitalWrite(LED, LOW);
    currentGear++;
  }
}
