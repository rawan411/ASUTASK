/*
 * main.c
 *
 * Created: 10/10/2021 12:11:57 AM
 *  Author: Rawan Waleed Ahmed
 */ 

#include "MDIO_interface.h"
#include "MUART_Interface.h"
#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"

#define F_CPU 16000000UL

int main(void)
{
	mdio_pinStatus(PORTA,PIN0,OUTPUT);
	mdio_pinStatus(PORTA,PIN1,OUTPUT);
	mdio_pinStatus(PORTA,PIN2,OUTPUT);
	
	muart_init(MUART_9600BPS);
	u8_t recieve_var;
    while(1)
    {
		
		muart_reciveByte(&recieve_var);
		if(recieve_var == 'a')
		{
			mdio_setPinValue(PORTA,PIN0,HIGH);
			mdio_setPinValue(PORTA,PIN1,LOW);
			mdio_setPinValue(PORTA,PIN2,HIGH);
		}
		else if(recieve_var == 'b')
		{
			mdio_setPinValue(PORTA,PIN0,LOW);
			mdio_setPinValue(PORTA,PIN1,HIGH);
			mdio_setPinValue(PORTA,PIN2,HIGH);
			
		}
		else
		{
			mdio_setPinValue(PORTA,PIN0,LOW);
			mdio_setPinValue(PORTA,PIN1,LOW);
			mdio_setPinValue(PORTA,PIN2,LOW);
		}
    }
}