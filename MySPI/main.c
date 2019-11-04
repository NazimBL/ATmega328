#include <avr/io.h>
#include "MySpi.h"
#include <util/delay.h>

int main(void)
{

    char val=0;
    char rec;
    DDRD=0xFF;
    spi_MasterInit();

    while(1){
    //active port to slave 1
    val=val+1;
    PORTD=0xFE;
    SPI_Write(val);
    //active port to slave 2
    PORTD=0xFD;
    SPI_Write(val);
    PORTD=0xFF;
    _delay_ms(200);
    }
    return 0;
}

