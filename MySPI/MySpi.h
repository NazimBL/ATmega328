#ifndef MYSPI_H_INCLUDED
#define MYSPI_H_INCLUDED
//    Bellabaci Nazim    29/12/2017 DeadLine

void spi_MasterInit(){

DDRB= (1<<5)|(1<<3)|(1<<2);
SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);
}

void spi_SlaveInit(){
  DDRB= (1<<4);
   SPCR = (1<<SPE)|(1<<SPIE)|(1<<CPHA);
}

void SPI_Write(char data)
{
  char flush_buffer;
  SPDR = data;
  while(!(SPSR & (1<<SPIF)));
  flush_buffer = SPDR;
}

char SPI_Read()
{
  SPDR = 0xFF;
  while(!(SPSR & (1<<SPIF)));
  return(SPDR);
}
#endif // MYSPI_H_INCLUDED
