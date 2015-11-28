#define FLTSDA 2
#define HINA 3
#define LINA 4
#define FLTCLRA 5 

#define FLTSDB 7
#define HINB 8 
#define LINB 9 
#define FLTCLRB 10

#define SHDN 12
#define SHUP 11

void setup() {
  // put your setup code here, to run once:
  pinMode(FLDSDA, OUTPUT);
  pinMode(HINA, OUTPUT);
  pinMode(LINA, OUTPUT);
  pinMode(FLTCLRA, OUTPUT);

  pinMode(FLTSDB, OUTPUT);
  pinMode(HINB, OUTPUT);
  pinMode(LINB, OUTPUT);
  pinMode(FLTCLRB, OUTPUT);

  pinMode(SHUP, INPUT);
  pinMode(SHDN, INPUT);

 
}

void loop() {
  // put your main code here, to run repeatedly:

}

void initA() 
{
  
  }

void initB()
  {
    
    }
