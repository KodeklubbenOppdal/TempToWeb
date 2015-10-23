/*
 Name:		RandomGen.ino
 Created:	10/23/2015 8:56:00 AM
 Author:	Sindre
*/

// the setup function runs once when you press reset or power the board

// Globale variabler
int teller = 0;
int randArray[60];
void setup()
{
	Serial.begin(9600);
	randomSeed(analogRead(0));
	
}

void loop()
{
	int randNr = random(254);
	randArray[teller] = randNr;

	
	if (teller >= 60)
	{
		Serial.println(snitt(randArray));
		teller = 0;

	}
	delay(100);
	teller++;
}

double snitt(int dataSet[60])
{
	int sum = 0;
	for (int i = 0; i < 60; i++)
	{
		sum = sum + dataSet[i];
	}
	double ret = sum / 60;
	return ret;
}
