#include <OneWire.h>
#include <DallasTemperature.h>

static int ONE_WIRE_BUS = 2;



// Setup a oneWire instance to communicate with any OneWire devices 
// (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature.
DallasTemperature TemperatureSensors(&oneWire);

// Deklarerer variabler 
float MaxTemperature;
float MinTemperature;

void setup()
{

	Serial.begin(9600);
	TemperatureSensors.begin();
	TemperatureSensors.requestTemperatures();
	// Leser tempratur fra sensor
	float Temperature = TemperatureSensors.getTempCByIndex(0);

	MaxTemperature = Temperature;
	MinTemperature = Temperature;

}


void loop()
{
	// Leser tempratur fra sensor
	TemperatureSensors.requestTemperatures();
	float Temperature = TemperatureSensors.getTempCByIndex(0);
	// Hvis temperature er st�rre en "MaxTemperature" avlest, skriv temperature til "MaxTemperature"

	if (Temperature>MaxTemperature)
	{
		MaxTemperature = Temperature;
	}
	// Hvis temperature er mindre en "MinTemperature" avlest, skriv temperature til "MinTemperature"

	else if (Temperature < MinTemperature)
	{
		MinTemperature = Temperature;
	}
	
	// Skriver temp ut
	String utString = "Tempreature: " + (String)Temperature;
	Serial.println(utString);
	// Skriver ut max temperature
	utString = "Max temperature: " + (String)MaxTemperature;
	Serial.println(utString);
	// Skriver ut min temperature
	utString = "Min temperature: " + (String)MinTemperature;
	Serial.println(utString);
}
