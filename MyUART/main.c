/*
Bellabaci Nazim 02/01/2018
 */

#include <avr/io.h>
#include <util/delay.h>
#include "myUART.h"

int main(void)
{

    UART_init(9600);
	UART_SendString(" DeadLine Baby \n\r");
    while(1){

        UART_SendString(" Hello World\n\r");
		_delay_ms(500);
    }

    return 0;
}
