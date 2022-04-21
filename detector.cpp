/*
 * Title: Detector Building
 * Author: Dimitri Kolodka
 * Version: AlphaV0
*/

#include "pins.cpp"
#include "calculate.cpp"
#include "screen.cpp"

double partsReference[2][3] = {
	{0.0, 0.0} // Blue LED Concentration, x ppm to y ppm
	{0.0, 0.0} // Green LED Concentration, x ppm to y ppm
	{0.0, 0.0} // Red LED Concentration, x ppm to y ppm
};

void setup(){
	lcd.begin(16, 2);
}

void loop(){
	double sensorVoltage = AnalogRead();
	double calculatedPPM = calculatePPM(sensorVoltage);

	drawToLCD(calculatedPPM, sensorVoltage);

	if(calcualtedPPM >= partsReference[0][0] && calculatedPPM <= partsReference[0][1]){ //If concentration is within the blue range
		digitalWrite(blueLEDPin, HIGH);
	}
	else{
		digitalWrite(blueLEDPin, LOW);
	}

	if(calculatedPPM >- partsReference[1][0] && calculatedPPM <= partsReference[1][1]{ //If concentration is within the green range
		digitalWrite(greenLEDPin, HIGH);
	}
	else{
		digitalWrite(greenLEDPin, LOW);
	}

	if(calculatedPPM >= partsReference[2][0] && calculatedPPM <= partsReference[2][1]{ //If concentration is within the red range 
		digitalWrite(redLEDPin, HIGH);
	}//If concentration is within the red range
	else{
		digitalWrite(redLEDPin, LOW);
	}
}
