/* RGB Analog Example, Teensyduino Tutorial #2
   http://www.pjrc.com/teensy/tutorial2.html

   This example code is in the public domain.
*/

const int en =  12;
const int sig =  11;

void setup()   {                
  pinMode(en, OUTPUT);
  pinMode(sig, OUTPUT);
  digitalWrite(en,LOW);
}

void loop()                     
{
  digitalWrite(sig,LOW);
  delay(9);
  digitalWrite(sig,HIGH);
  delay(1);
  if (millis() > 100)
    digitalWrite(en,HIGH);
}

