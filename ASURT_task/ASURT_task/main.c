/*
 * main.c
 *
 * Created: 10/9/2021 8:01:13 PM
 *  Author: Rawan Waleed Ahmed
 */ 

#include "MDIO_interface.h"
#include "MUART_Interface.h"
#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"

#define F_CPU 16000000UL

int main(void)
{
	
	mdio_pinStatus(PORTA,PIN0,INPUT_PULLUP);
	mdio_pinStatus(PORTA,PIN1,INPUT_PULLUP);
 	mdio_pinStatus(PORTA,PIN2,INPUT_PULLUP);

	mdio_pinStatus(PORTB,PIN0,OUTPUT); 

 	mdio_pinStatus(PORTB,PIN1,OUTPUT);
 	mdio_pinStatus(PORTB,PIN2,OUTPUT);
 	
 	muart_init(MUART_9600BPS);
	
    while(1)
    {
		
		if(mdio_getPinValue(PORTA,PIN0) == LOW)
		{
			
			muart_sendByte('a');
		}
		if(mdio_getPinValue(PORTA,PIN1) == LOW)
		{
			muart_sendByte('b');
		}
		if(mdio_getPinValue(PORTA,PIN2) == LOW)
		{
			muart_sendByte('c');
		}

	}

}