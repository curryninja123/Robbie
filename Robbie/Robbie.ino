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
#define space "_"

#define circ        // circumference of wheel in cm
#define spd 60      // speed of continuous servos in degrees per second

Servo left;						// Servo to control left wheel
Servo right;					// Servo to control right wheel
Servo arm;						// Servo to control arm

void setup() {
  Serial1.begin(9600);		// begin bluetooth reading
  Serial2.begin(9600);		// begin voice command reading
  left.attach(leftPin);		// initiate left continuous servo
  right.attach(rightPin);		// initiate right continuous servo
  arm.attach(armPin);		// initiate arm servo
  pinMode(redPin, out);		// initiate red LED light
  pinMode(greenPin, out);		// initiate green LED light
  pinMode(bluePin, out);		// initiate blue LED light
}

/**************************      PUT YOUR CODE HERE      **************************/

void loop() {
  color(0,0,0);
  delay(100);
  color(0,0,1);
  delay(100);
  color(0,1,0);
  delay(100);
  color(0,1,1);
  delay(100);
  color(1,0,0);
  delay(100);
  color(1,0,1);
  delay(100);
  color(1,1,0);
  delay(100);
  color(1,1,1);
  delay(100);
}

/**************************      PUT YOUR CODE HERE      **************************/
/****** These are files that control the RobCode reading and execution. Do not modify without knowledge of the API ******/

void color (byte r, byte g, byte b) {		// powers the RGB LED
  digitalWrite(redPin, 1);
  digitalWrite(greenPin, 1);
  digitalWrite(bluePin, 1);
}

void command(String str) {				// command to return RobCode command line
  int k = 0;
  while (k < str.length())
  {
    String temp = "";
    if (!(str.substring(k,k+1) + "").equals(nextLineConstant))		// compares current character to next line constant
    {
      temp += str.charAt(k);								// adds character at current index
    }
    else
    {
      parseCommand(temp);									// parses given command
      break;											// resets value of str
    }
    k++;
  }
}

void parseCommand (String str) {								// converts command into action call
  int k = 0;
  while (k < str.length())
  {
    String temp = "";
    int i = 0;
    if (!(str.substring(k,k+1) + "").equals(space))
    {
      temp += str.charAt(k);
    }
    else
    {
      i = str.substring(k + 1, str.length()).toInt();
      execute(temp, i);
      break;
    }
    k++;
  }
}

void execute (String str, int val) {							// performs action with a descriptor and magnitude
  if (str.equals("f"))
  {
    drive(1);
    delay(calculator(1,val));
  }
  else if (str.equals("b"))
  {
    drive(2);
    delay(calculator(1,val));
  }
  else if (str.equals("l"))
  {
    drive(3);
    delay(300);
  }
  else if (str.equals("r"))
  {
    drive(4);
    delay(300);
  }
  else if (str.equals("c"))
  {
    int a = val / 4;
    int temp = val % 4;
    int b = temp / 2;
    int c = temp % 2;
    color(a, b, c);
  }
  else if (str.equals("d"))
  {
    arm.write(75);
  }
  else if (str.equals("m"))
  {
    arm.write(105);
  }
  else if (str.equals("u"))
  {
    arm.write(135);
  }
  else
  {
    drive(0);
    color(0,0,0);
  }
}

int calculator (int type, int num) {
  if (type = 1)
  {
    double k = (double) num;
    //double d = (k / circ / (spd / 360)) * 1000;
    int i = (int)k;
    return i;
  }
  return 0;
}

void drive(int i)
{
  switch (i)
  {
    case 1:
      left.write(180);
      right.write(180);
      break;
    case 2:
      left.write(180);
      right.write(0);
      break;
    case 3:
      left.write(0);
      right.write(180);
    case 4:
      left.write(-180);
      right.write(-180);
    default:
      left.write(0);
      right.write(0);
  }
}

