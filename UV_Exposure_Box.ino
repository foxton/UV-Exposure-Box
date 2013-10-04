
//Program for running a mototech unipolar 5-wire stepper motor
//With a ULN2003 transistor array.

int motorPin1 = 8; //Brown
int motorPin2 = 9; //Yellow
int motorPin3 = 10;//Black
int motorPin4 = 11;//Orange
int switchpin1 = 2;
int pinstate1 = 0;
int delayTime = 10; // This delay will adjust the motor speed (Lower = faster)
int ledPin =  13;  //Onboard LED for indicating the state of switchpin1
void setup() 
{
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  pinMode(switchpin1, INPUT);
  pinMode(ledPin, OUTPUT);   
}

void loop() 
{
 pinstate1 = digitalRead(switchpin1); //Reads the state of the switch
 if(pinstate1 == LOW)
 {
  CRotation();						  //Clockwise rotation
   digitalWrite(ledPin, LOW);
 }
 else
 {
 CCRotation();						  //Counter clockwise rotation
 digitalWrite(ledPin, HIGH);

 }
}

void CRotation()
{
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
  delay(delayTime);
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
  delay(delayTime);
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, LOW);
  delay(delayTime);
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
  delay(delayTime);
}
void CCRotation()
{
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
  delay(delayTime);
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, LOW);
  delay(delayTime);
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
  delay(delayTime);
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
  delay(delayTime);
}