
//Program for running a mototech unipolar 5-wire stepper motor
//With a ULN2003 transistor array.

int motorPin1 = 8; //Brown
int motorPin2 = 9; //Yellow
int motorPin3 = 10;//Black
int motorPin4 = 11;//Orange
int ledPin =  13;  //Onboard LED for indicating the state of switchpin1
int switchpin1 = 2;
int pinstate1 = 0;    // Stores the state of switch 1
int lastpinstate1 = 0; //Previous state of switch 1
int switch1PushCounter = 0; //Counter for the number of switch1 presses
int delayTime = 10; // This delay will adjust the motor speed (Lower = faster)

void setup() 
{
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  pinMode(switchpin1, INPUT);
  pinMode(ledPin, OUTPUT);

  //Add startup check here

}

void loop() 
{
	
 pinstate1 = digitalRead(switchpin1); //Reads the state of the switch


	if(pinstate1 == HIGH && switch1PushCounter == 0) // if the current state is LOW and Counter = 0, then											   												// the moving LED arm is in start position
	{
		
		CCRotation();  //Counter Clockwise rotation	
		switch1PushCounter++;
	}
	if(pinstate1 == HIGH && switch1PushCounter == 1)
	{
	CRotation();
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
void Stop()
{
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
}