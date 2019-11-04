#ifndef MYUART_H_INCLUDED
#define MYUART_H_INCLUDED

#define F_CPU 8000000UL		/* Define frequency here its 8MHz */


void UART_init(long USART_BAUDRATE)
{

	int BAUD_PRESCALE=(((F_CPU/(USART_BAUDRATE * 16))) -1);


	UCSRB |= (1 << RXEN) | (1 << TXEN);/* Turn on transmission and reception */
	UCSRC |= (1 << URSEL) | (1 << UCSZ0) | (1 << UCSZ1);/* Use 8-bit character sizes */
	UBRRL = BAUD_PRESCALE;		/* Load lower 8-bits of the baud rate value */
	UBRRH = (BAUD_PRESCALE >> 8);	/* Load upper 8-bits*/
}

unsigned char UART_ReadChar()
{
	while ((UCSRA & (1 << RXC)) == 0);/* Wait till data is received */
	return(UDR);		/* Return the byte */
}

void UART_SendChar(char ch)
{
	while (! (UCSRA & (1<<UDRE)));  /* Wait for empty transmit buffer */
	UDR = ch ;
}

void UART_SendString(char *str)
{
	unsigned char j=0;

	while (str[j]!=0)		/* Send string till null */
	{
		UART_SendChar(str[j]);
		j++;
	}
}

#endif // MYUART_H_INCLUDED
