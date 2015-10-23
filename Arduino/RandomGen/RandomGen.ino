/*
 Name:		RandomGen.ino
 Created:	10/23/2015 8:56:00 AM
 Author:	Sindre
*/

// the setup function runs once when you press reset or power the board
void setup()
{
	Serial.begin(9600);
	randomSeed(analogRead(0));
}

void loop()
{
	int randNr = random(254);
	Serial.println(randNr);
	delay(1000);
}
