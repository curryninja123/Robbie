/* Project name: Robbie
 * Author: Vishnu Iyer
 * GitHub project page: http://github.com/curryninja123/Robbie
 * Robbie is an open-sourced quasi-humanoid robot
 *
 *
 */

#include <Servo.h>

#define redPin 23
#define greenPin 25
#define bluePin 27
#define leftPin 24
#define rightPin 26
#define armPin 22
#define out OUTPUT
#define in INPUT

#define nextLineConstant "~"

#define speed 60

Servo left;						// Servo to control left wheel
Servo right;					// Servo to control right wheel
Servo arm;						// Servo to control arm

void setup() {
	Serial1.begin(9600);		// begin bluetooth reading
  	Serial2.begin(9600);		// begin voice command reading
  	left.attach(leftPin);		// initiate left continuous servo
  	right.attach(rightPin);		// initiate right continuous servo
  	head.attach(armPin);		// initiate arm servo
  	pinMode(redin, out);		// initiate red LED light
  	pinMode(greenPin,out);		// initiate green LED light
  	pinMode(bluePin,out);		// initiate blue LED light
}

void loop() {

}

void color (byte r, byte g, byte b) {		// powers the RGB LED
	digitalWrite(redPin, 1);
	digitalWrite(greenPin, 1);
	digitalWrite(bluePin, 1);
}

/****** These are files that control the RobCode reading and execution. Do not modify without knowledge of the API ******/

void getCommand(String str){				// command to return RobCode command line
	int k = 0;
	while(k < str.length())
	{
		String temp = "";
		if(!(str.charAt(k)+"").equals(nextLineConstant))		// compares current character to next line constant
		{
			temp+=str.charAt(k);
		}
		else
		{
			parseCommand(temp);
			temp = "";
		}
		k++;
	}
}

void parseCommand (String str) {
	
}

void execute (String str, int val) {

}