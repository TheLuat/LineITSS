

int x=13;
int x1=12;
int x2=4;
int x3=3;
int a,b,c,d;
int PWM_MAX_SPEED=80;
int PWM_SPEED=75;
int MOTOR_LEFT_1=11;
int MOTOR_LEFT_2=10;
// Motor 1
int MOTOR_RIGHT_1=9;
int MOTOR_RIGHT_2=6;
void setup() {
  // put your setup code here, to run once:
  pinMode(x,INPUT);
  pinMode(x1,INPUT);
  pinMode(x2,INPUT);
  pinMode(x3,INPUT);
  Serial.begin(9600);

}
void Forward()
{
  for(int i=0;i<=PWM_MAX_SPEED;i++)
  {
  analogWrite(MOTOR_LEFT_1,i);
  digitalWrite(MOTOR_LEFT_2,0);
  analogWrite(MOTOR_RIGHT_1,i);
  digitalWrite(MOTOR_RIGHT_2,0);
}
}

void Back()
{
   for(int i=0;i<=PWM_MAX_SPEED;i++)
  {
  digitalWrite(MOTOR_LEFT_1,0);
  analogWrite(MOTOR_LEFT_2,i);
  digitalWrite(MOTOR_RIGHT_1,0);
  analogWrite(MOTOR_RIGHT_2,i);
}
}
void Left()
{
  for(int i=0;i<=PWM_MAX_SPEED;i++)
  {
  analogWrite(MOTOR_LEFT_1,i);
  digitalWrite(MOTOR_LEFT_2,0);
  digitalWrite(MOTOR_RIGHT_1,0);
  analogWrite(MOTOR_RIGHT_2,PWM_SPEED);
}
}
void Right()
{ 
  for(int i=0;i<=PWM_MAX_SPEED;i++)
  {
  digitalWrite(MOTOR_LEFT_1,0);
  analogWrite(MOTOR_LEFT_2,PWM_SPEED);
  analogWrite(MOTOR_RIGHT_1,i);
  digitalWrite(MOTOR_RIGHT_2,0);
}
}

void loop() {
  // put your main code here, to run repeatedly:
  a=digitalRead(x);
  Serial.println(a);
  b=digitalRead(x1);
  Serial.println(b);
  c=digitalRead(x2);
  Serial.println(c);
  d=digitalRead(x3);
  Serial.println(d);
  if (b ==1 && c==0 && a==0 && d==0 )
  Left();
  else if (c==1 && d==0 && a==0 && b==0)
  Right();
  else
  Forward();
  
  
  
  

}
