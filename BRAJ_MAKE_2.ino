bool manual = true;

int pin1 = 8, pin2 = 9, pin3 = 10, pin4 = 11;
int trigF = 2, echoF = 3, trigL = 4, echoL = 5, trigR = 7, echoR = 6;
char value;




void setup() {
  ////////////////////////////////// dc motor
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
  //////////////////////////////////// ultrasonic
  pinMode(trigF, OUTPUT);
  pinMode(trigL, OUTPUT);
  pinMode(trigR, OUTPUT);
  pinMode(echoF, INPUT);
  pinMode(echoL, INPUT);
  pinMode(echoR, INPUT);
  Serial.begin(9600);
}



///////////////////////////////////////////////////////////////////////funtions start
void right()//f
{
  digitalWrite(pin1, HIGH);
  digitalWrite(pin2, LOW);
  digitalWrite(pin3, HIGH);
  digitalWrite(pin4, LOW);
}

void left()//b
{
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, HIGH);
  digitalWrite(pin3, LOW);
  digitalWrite(pin4, HIGH);
}
void forward()//f
{
  digitalWrite(pin1, HIGH);
  digitalWrite(pin2, LOW);
  digitalWrite(pin3, LOW);
  digitalWrite(pin4, HIGH);
}
void backward()//l
{
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, HIGH);
  digitalWrite(pin3, HIGH);
  digitalWrite(pin4, LOW);
}
//void forwardleft()//g
//{
//  digitalWrite(pin1, LOW);
//  digitalWrite(pin2, LOW);
//  digitalWrite(pin3, HIGH);
//  digitalWrite(pin4, LOW);
//}
//void backleft()//h
//{
//  digitalWrite(pin1, LOW);
//  digitalWrite(pin2, HIGH);
//  digitalWrite(pin3, LOW);
//  digitalWrite(pin4, LOW);
//}
//void forwardright()//i
//{
//  digitalWrite(pin1, HIGH);
//  digitalWrite(pin2, LOW);
//  digitalWrite(pin3, LOW);
//  digitalWrite(pin4, LOW);
//}
//
//
//void backright()//j
//{
//  digitalWrite(pin1, LOW);
//  digitalWrite(pin2, LOW);
//  digitalWrite(pin3, LOW);
//  digitalWrite(pin4, HIGH);
//}
void stopping()//s
{
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, LOW);
  digitalWrite(pin3, LOW);
  digitalWrite(pin4, LOW);
}
//////////////////////////////////////////////////////////////////////////////////////////ultasonic sensor
int senseF()
{
  digitalWrite(trigF, LOW);
  delay(2);
  digitalWrite(trigF, HIGH);
  delay(10);
  digitalWrite(trigF, LOW);
  int time_micro = pulseIn(echoF, HIGH);
  int dist = time_micro / 58.2;
  return dist;

}
int senseL()
{
  digitalWrite(trigL, LOW);
  delay(2);
  digitalWrite(trigL, HIGH);
  delay(10);
  digitalWrite(trigL, LOW);
  int time_micro = pulseIn(echoL, HIGH);
  int dist = time_micro / 58.2;
  return dist;
}
int senseR()
{
  digitalWrite(trigR, LOW);
  delay(2);
  digitalWrite(trigR, HIGH);
  delay(10);
  digitalWrite(trigR, LOW);
  int time_micro = pulseIn(echoR, HIGH);
  int dist = time_micro / 58.2;
  return dist;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////funtion end




void loop() {
  ///////////////////////////////////////////////////////manual start
  if (Serial.available())
    {
      value = Serial.read();
      Serial.println(value);

        if (manual == true)
  {
    

    if (value == 'F') // forward
    {
      forward();

    }

    if (value == 'B')
    {
      backward();
    }


    if (value == 'R')
    {
      right();
    }

    if (value == 'L')
    {
      left();
    }
//    if (value == 'I')
//    {
//      forwardright();
//    }
//    if (value == 'G')
//    {
//      forwardleft();
//    }
//    if (value == 'H')
//    {
//      backleft();
//    }
//    if (value == 'J')
//    {
//      backright();
 //   }
    if (value == 'v')
      manual = false;
    if (value == 'S')
    {
      stopping();
    }
  }
  //////////////////////////////////////////////////////////////////////////////////manual end
  ////////////////////////////////////////////////////////////////////////////////////////auto start
  else
  {
    int distF = abs(senseF());
    int distL = abs(senseL());
    int distR = abs(senseR());
   
   if (distF > distR && distF > distL && distF > 3 )
      forward();
    else if (distL > distF && distL > distR && distL > 3)
     left();
    else if (distF < distR && distR > distL && distR > 3)
     right();
//     
//      if (value == 'W')
//      manual = true;
//      if (value == 'w')
//      manual = true;
   Serial.println(manual);
   delay(50);

  }
}}
