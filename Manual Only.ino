

int pin1 = 2, pin2 = 3, pin3 = 4, pin4 = 5;

char value;




void setup() {
  ////////////////////////////////// dc motor
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
  //////////////////////////////////// ultrasonic
 
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

void stopping()//s
{
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, LOW);
  digitalWrite(pin3, LOW);
  digitalWrite(pin4, LOW);
}
//////////////////////////////////////////////////////////////////////////////////////////ultasonic sensor

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////funtion end




void loop() {
  ///////////////////////////////////////////////////////manual start
  if (Serial.available())
    {
      value = Serial.read();
      //Serial.println(value);

  
    

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

   
    if (value == 'S')
    {
      stopping();
    }
  
  //////////////////////////////////////////////////////////////////////////////////manual end
  ////////////////////////////////////////////////////////////////////////////////////////auto start
 
}}
