#include <OneWire.h>
#include <DallasTemperature.h>

static int ONE_WIRE_BUS = 2;



// Setup a oneWire instance to communicate with any OneWire devices 
// (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature.
DallasTemperature TemperatureSensors(&oneWire);

void setup()
{
	Serial.begin(9600);
	TemperatureSensors.begin();
}


void loop()
{
	// Leser tempratur fra sensor
	TemperatureSensors.requestTemperatures();
	float Temperature = TemperatureSensors.getTempCByIndex(0);
	// Skriver temp ut
	Serial.println(Temperature);

}
