	//includes the 'LiquidCrystal tab' (which allows the LCD display to work
#include <LiquidCrystal.h>
	//create a integer variable (that cannot be changed) called 'buzzer' with the stored value of 9.
const int buzzer = 9;
	//tells the system that the LCD pins are pluged into ports 12, 11, 5, 4, 3, 2.
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
	//create a integer variable called 'sensorPin' with the stored value of 0.
int sensorPin = 0;
	//create a integer variable called 'redLedPin' with the stored value of 4.
int redLedPin = 4;
	//create a integer variable called 'light' with the stored value of 0.
int light = 0;

	//anything inside of void loop will run once, as soon as the code starts.
void setup() { 
	//tells the Arduino to get ready to exchange messages with the Serial Monitor at a rate of 9600 bits per second.
  Serial.begin(9600);
	//specifies the dimensions (16 = width and 2 = height) of the LCD display.
  lcd.begin(16, 2);
	//displays the text "Amount of Rain:" on the first line of the LCD display.
  lcd.print("Amount of Rain:");
	//tells the system that pin 9 is an output for a digital input, and not an analog input.
  pinMode(buzzer, OUTPUT);
    //tells the system that pin 1 is an output for a digital input. (Same as previous statement (22)).
  pinMode(1, OUTPUT); }

	//anything in void loop will run constantly when the code starts (After everything above runs).
void loop() {
	//creates a variable called 'temp' sets the value of it to whatever the output of analogRead(A5) is.
  int temp = analogRead(A5);
    //creates a variable called 'volume' sets the value of it to whatever the output of analogRead(A0) is.
  int volume = analogRead(A0);
	//sets the value of variable 'light' to whatever the output of analogread(A4) is.
  light = analogRead(A4);
	//sets the value of variable 'volume' to 'volume' divided by 26.5.
  volume = volume / 26.5;
	//sets the cursor (where future lcd displays will be displayed at.) of the LCD to 0 = x, and 1 = y.
  lcd.setCursor(0, 1);
	//prints "volume" on the LCD at 0x, 1y because of previous statement.
  lcd.print(volume);
	//prints the value of 'temp' into the Serial monitor
  Serial.println(temp);
    //if 'volume' equals more than 5,
  if  (volume > 5)
	//then print "cm - Check Now!" on the LCD display.
  { lcd.print("cm - Check Now!"); }
	//if 'volume' does not equal more than 5, but is more than 2,
  else if  (volume > 2)
	//then print "cm - Check?    " on the LCD display.
  { lcd.print("cm - Check?    "); }
	//if neither statements are true, 
  else 
	//then print "cm - All Good!" on the LCD display.
  { lcd.print("cm - All Good!"); }
	//if 'volume' equals more than 5,
  if (volume > 5)
	//then turn buzzer (pin 9) on for 1000 miliseconds.
  { tone(buzzer, 1000); 
	//then delay for 1000 miliseconds.
    delay(1000);  
	//turn of buzzer,
    noTone(buzzer); 
	//then delay for 1000 miliseconds.
    delay(1000); }
	//if 'light' equals more than 200, then
  if(light > 200) { 
	//turns the value of pin 1 to LOW (0V). 
    digitalWrite(1,LOW); }
	//if the 'if statement' is not true then,
    else { 
	//turns the value of pin 1 to HIGH (5V).
    digitalWrite(1,HIGH); }
}