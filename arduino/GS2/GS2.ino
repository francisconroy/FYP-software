/*
   Paddle operation regarding NUR15
   Gear shifter controller

   Written By Francis Conroy and Josh Chadwick
   4/12/2015
*/

// Pins
#define D2_IN_A           3
#define D2_IN_B           4
#define D2_PWM            5

#define D1_IN_A           8
#define D1_PWM            9
#define D1_IN_B           10

#define UP_PADDLE         11
#define DOWN_PADDLE       12

#define NEUTRAL_LIGHT     13

#define SHIFT_LEVER_ANGLE 14

#define NEUTRAL_BUTTON    18

//Constants
#define TIMEON 60
#define HALFTIMEON 30


//Variables
int state; // state machine current state

int shiftUp; // status of up paddle
int shiftDown; // status of down paddle/button
int neutralPush; // status of neutral button
int neutralLight; // status of neutral light

int currentGear; // current gear as assumed by controller

unsigned long startTime;
unsigned long currentTime;

void setup() {
  pinMode(D2_IN_A, OUTPUT);
  pinMode(D2_IN_B, OUTPUT);
  pinMode(D2_PWM, OUTPUT);
  pinMode(D1_IN_A, OUTPUT);
  pinMode(D1_PWM, OUTPUT);
  pinMode(D1_IN_B, OUTPUT);

  pinMode(UP_PADDLE, INPUT);
  pinMode(DOWN_PADDLE, INPUT);

  pinMode(NEUTRAL_LIGHT, INPUT);

  pinMode(NEUTRAL_BUTTON, INPUT);

  // set mode
  digitalWrite(D2_IN_A, LOW);
  digitalWrite(D2_IN_B, LOW); // brake to GND
  analogWriteFrequency(D2_PWM, 5000);
  analogWriteFrequency(D1_PWM, 5000);

  // delay to remove transients
  delay(2000);

  state = -1; // state machine current state

  shiftUp = 1; // not shifting
  shiftDown = 1; // not shifting
  neutralPush = 1; // not pushing
  neutralLight = 1; // not showing

  currentGear = 0; // neutral

  startTime = 0;
  currentTime = 0;
}

void loop() {
  switch (state)
  {
    case -1:
      {
        writeToScreen("go n");
        shiftUp = digitalRead(UP_PADDLE);
        shiftDown = digitalRead(DOWN_PADDLE);
        neutralPush = digitalRead(NEUTRAL_BUTTON);
        neutralLight = digitalRead(NEUTRAL_LIGHT);

        // SHIFT UP
        if (shiftUp == 0 && shiftDown == 1 && neutralPush == 1)
        {
          doShiftUp();
          break;
        }
        // SHIFT DOWN
        if (shiftUp == 1 && shiftDown == 0 && neutralPush == 1)
        {
          doShiftDown();
          break;
        }
        // SHIFT UP TO NEUTRAL
        if (shiftUp == 0 && shiftDown == 1 && neutralPush == 0)
        {
          doShiftNeutralUp();
          break;
        }
        // SHIFT DOWN TO NEUTRAL
        if (shiftUp == 1 && shiftDown == 0 && neutralPush == 0)
        {
          doShiftNeutralDown();
          break;
        }
        delay(1000);
        if ((neutralLight = digitalRead(NEUTRAL_LIGHT)) == LOW) // now in neutral
        {
          state = 0;
          writeToScreen("    ");
          break;
        }
      }
      break;
    case 0:
      {
        shiftUp = digitalRead(UP_PADDLE);
        shiftDown = digitalRead(DOWN_PADDLE);
        neutralPush = digitalRead(NEUTRAL_BUTTON);
        neutralLight = digitalRead(NEUTRAL_LIGHT);

        // SHIFT UP
        if (shiftUp == 0 && shiftDown == 1 && neutralPush == 1)
        {
          if (doShiftUp())
          {
            currentGear++;
            delay(500);
            if ((shiftUp = digitalRead(UP_PADDLE)) == LOW)
            {
              state = 3;
              break;
            }
          }
          else
          {
            break;
          }
        }
        // SHIFT DOWN
        if (shiftUp == 1 && shiftDown == 0 && neutralPush == 1)
        {
          if (doShiftDown())
          {
            currentGear--;
            delay(500);
            if ((shiftDown = digitalRead(DOWN_PADDLE)) == LOW)
            {
              state = 3;
              break;
            }
          }
          else
          {
            break;
          }
        }
        // GO NEUTRAL
        if (shiftUp == 1 && shiftDown == 1 && neutralPush == 0)
        {
          if (currentGear == 1 || currentGear == 2)
          {
            if (doShiftNeutral())
            {
              currentGear = 0;
              delay(500);
              if ((neutralPush = digitalRead(NEUTRAL_BUTTON)) == LOW)
              {
                state = 3;
                break;
              }
            }
            else
            {
              break;
            }
          }
        }
      }
      break;
    case 1: // TPS signal out of physical range
      {
        writeToScreen("Err1");
      }
      break;
    case 2: // TPS doesn't move when triggered
      {
        writeToScreen("Err2");
      }
      break;
    case 3: // Button held
      {
        writeToScreen("held");
        shiftUp = digitalRead(UP_PADDLE);
        shiftDown = digitalRead(DOWN_PADDLE);
        neutralPush = digitalRead(NEUTRAL_BUTTON);
        if (shiftUp && shiftDown && !neutralPush) // all buttons released
        {
          state = 0;
          writeToScreen("    ");
        }
      }
      break;
    default:
      {
        writeToScreen("Err9");
      }
      break;
  }
}

int verifyGear(int assumedGear)
{
  if (state == -1)
  {
    return 0;
  }
  else
  {
    return 0;
  }
}

bool doShiftUp()
{
  digitalWrite(D1_IN_A, HIGH);
  digitalWrite(D1_IN_B, LOW); // brake to GND
  currentTime = startTime = millis();
  while ((currentTime - startTime) < TIMEON)
  {
    currentTime = millis();
    analogWrite(D2_PWM, 255);
  }
  switch (verifyGear(currentGear + 1))
  {
    case 0:
      {
        digitalWrite(D1_IN_A, LOW);
        digitalWrite(D1_IN_B, LOW); // brake to GND
        analogWrite(D1_PWM, 0);
        delay(250);
        return true;
      }
    case 1:
      {
        digitalWrite(D1_IN_A, LOW);
        digitalWrite(D1_IN_B, LOW); // brake to GND
        analogWrite(D1_PWM, 0);
        state = 1;
        return false;
      }
    case 2:
      {
        digitalWrite(D1_IN_A, LOW);
        digitalWrite(D1_IN_B, LOW); // brake to GND
        analogWrite(D1_PWM, 0);
        state = 2;
        return false;
      }
  }
  return false;
}

bool doShiftDown()
{
  digitalWrite(D2_IN_A, HIGH);
  digitalWrite(D2_IN_B, LOW); // brake to GND
  currentTime = startTime = millis();
  while ((currentTime - startTime) < TIMEON)
  {
    currentTime = millis();
    analogWrite(D2_PWM, 255);
  }
  switch (verifyGear(currentGear - 1))
  {
    case 0:
      {
        digitalWrite(D2_IN_A, LOW);
        digitalWrite(D2_IN_B, LOW); // brake to GND
        analogWrite(D2_PWM, 0);
        delay(250);
        return true;
      }
    case 1:
      {
        digitalWrite(D2_IN_A, LOW);
        digitalWrite(D2_IN_B, LOW); // brake to GND
        analogWrite(D2_PWM, 0);
        state = 1;
        return false;
      }
    case 2:
      {
        digitalWrite(D2_IN_A, LOW);
        digitalWrite(D2_IN_B, LOW); // brake to GND
        analogWrite(D2_PWM, 0);
        state = 2;
        return false;
      }
  }
  return false;
}

bool doShiftNeutralUp()
{
  digitalWrite(D1_IN_A, HIGH);
  digitalWrite(D1_IN_B, LOW); // brake to GND
  currentTime = startTime = millis();
  while ((currentTime - startTime) < HALFTIMEON)
  {
    currentTime = millis();
    analogWrite(D2_PWM, 255);
  }
  switch (verifyGear(0))
  {
    case 0:
      {
        digitalWrite(D1_IN_A, LOW);
        digitalWrite(D1_IN_B, LOW); // brake to GND
        analogWrite(D1_PWM, 0);
        delay(250);
        return true;
      }
    case 1:
      {
        digitalWrite(D1_IN_A, LOW);
        digitalWrite(D1_IN_B, LOW); // brake to GND
        analogWrite(D1_PWM, 0);
        state = 1;
        return false;
      }
    case 2:
      {
        digitalWrite(D1_IN_A, LOW);
        digitalWrite(D1_IN_B, LOW); // brake to GND
        analogWrite(D1_PWM, 0);
        state = 2;
        return false;
      }
  }
  return false;
}

bool doShiftNeutralDown()
{
  digitalWrite(D2_IN_A, HIGH);
  digitalWrite(D2_IN_B, LOW); // brake to GND
  currentTime = startTime = millis();
  while ((currentTime - startTime) < HALFTIMEON)
  {
    currentTime = millis();
    analogWrite(D2_PWM, 255);
  }
  switch (verifyGear(0))
  {
    case 0:
      {
        digitalWrite(D2_IN_A, LOW);
        digitalWrite(D2_IN_B, LOW); // brake to GND
        analogWrite(D2_PWM, 0);
        delay(250);
        return true;
      }
    case 1:
      {
        digitalWrite(D2_IN_A, LOW);
        digitalWrite(D2_IN_B, LOW); // brake to GND
        analogWrite(D2_PWM, 0);
        state = 1;
        return false;
      }
    case 2:
      {
        digitalWrite(D2_IN_A, LOW);
        digitalWrite(D2_IN_B, LOW); // brake to GND
        analogWrite(D2_PWM, 0);
        state = 2;
        return false;
      }
  }
  return false;
}

bool doShiftNeutral()
{
  if (currentGear == 1)
  {
    return doShiftNeutralUp();
  }
  else if (currentGear == 2)
  {
    return doShiftNeutralDown();
  }
  else
  {
    return false;
  }
}

void writeToScreen(String str)
{
  for (int i = 0; i < 4; i++)
  {
    switch (str[i])
    {
      case ' ':
        //matrix.writeDigitRaw(0, B00000000);
        break;

      case '1':
        //matrix.writeDigitRaw(0, B00110000);
        break;
      case '2':
        //matrix.writeDigitRaw(0, B01011011);
        break;
      case '9':
        //matrix.writeDigitRaw(0, B01111100);
        break;

      case 'd':
        //matrix.writeDigitRaw(0, B01110011);
        break;
      case 'E':
        //matrix.writeDigitRaw(0, B01001111);
        break;
      case 'g':
        //matrix.writeDigitRaw(0, B01111101);
        break;
      case 'h':
        //matrix.writeDigitRaw(0, B01100110);
        break;
      case 'l':
        //matrix.writeDigitRaw(0, B00110000);
        break;
      case 'n':
        //matrix.writeDigitRaw(0, B01100010);
        break;
      case 'o':
        //matrix.writeDigitRaw(0, B01100011);
        break;
      case 'r':
        //matrix.writeDigitRaw(0, B01000010);
        break;
    }
  }
}

