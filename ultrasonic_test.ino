int trigF=2,echoF=3,trigL=4,echoL=5,trigR=7,echoR=6;
void setup() {
  // put your setup code here, to run once:
pinMode(trigF,OUTPUT);
pinMode(trigL,OUTPUT);
pinMode(trigR,OUTPUT);
pinMode(echoF,INPUT);
pinMode(echoL,INPUT);
pinMode(echoR,INPUT);
Serial.begin(9600);
}
int senseF()
{
  digitalWrite(trigF,LOW);
  delay(2);
  digitalWrite(trigF,HIGH);
  delay(10);
  digitalWrite(trigF,LOW);
  int time_micro = pulseIn(echoF,HIGH);
  int dist = time_micro/14.5;
  return dist;
  
}
int senseL()
{
  digitalWrite(trigL,LOW);
  delay(2);
  digitalWrite(trigL,HIGH);
  delay(10);
  digitalWrite(trigL,LOW);
  int time_micro = pulseIn(echoL,HIGH);
  int dist = time_micro/14.5;
  return dist;
}
int senseR()
{
  digitalWrite(trigR,LOW);
  delay(2);
  digitalWrite(trigR,HIGH);
  delay(10);
  digitalWrite(trigR,LOW);
  int time_micro = pulseIn(echoR,HIGH);
  int dist = time_micro/14.5;
  return dist;
}
void loop() {
  // put your main code here, to run repeatedly:
 int distF = senseF();
  int distL = senseL();
  int distR = senseR();
  Serial.print(distF);
   Serial.print("  ");
   Serial.print(distL);
   Serial.print("  ");
    Serial.print(distR);
    Serial.println("  ");
}
