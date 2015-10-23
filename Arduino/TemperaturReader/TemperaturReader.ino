#include <OneWire.h>
#include <DallasTemperature.h>
static int ONE_WIRE_BUS = 2;
static char systemDevider = '_';
static char valueDevider = ':';


// Setup a oneWire instance to communicate with any OneWire devices 
// (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature.
DallasTemperature TemperatureSensors(&oneWire);


String AllInfoString;
void setup()
{
	Serial.begin(9600);
	TemperatureSensors.begin();

}


void loop()
{
	// Getting Temperatures
	TemperatureSensors.requestTemperatures();

	float Temperature = TemperatureSensors.getTempCByIndex(0);

	Serial.println(Temperature);
}
