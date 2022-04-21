#include <LiquidCrystal.h>

LiquidCrystal lcd(4, 6, 10, 11, 12, 13);

void initialiseLCD(){
	lcd.setCursor(0, 0);
	lcd.print("CONC");

	lcd.setCursor(0, 1);
	lcd.print("VOLT");
}

void drawToLCD(double partsPerMillion, double voltage){
	lcd.setCursor(5, 0);
	lcd.print((int) partsPerMillion);

	lcd.setCursor(5, 1);
	lcd.print(voltage)
}
