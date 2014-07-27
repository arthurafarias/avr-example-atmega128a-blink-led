#include <avr/io.h>
#include <avr/delay.h>

#include "main.h"

int main() {

	bmp8 PORTA_map = (bmp8) &PORTA;
	bmp8 PINA_map = (bmp8) &PINA;

	DDRA = 0xFF;
	PORTA = 0XFF;

	while(1) {
		_delay_ms(500);
		PORTA_map->P7 = ~PINA_map->P7;
	}

	return 0;
}
