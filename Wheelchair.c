#include<avr/io.h>

#define F_CPU 1000000UL
#include<util/delay.h>
#include<stdint.h>
#include<stdio.h>

unsigned char i,X;

void init()
{	
	DDRA=0xF0;
	DDRB=0x00;
	DDRC=0x00;
	DDRD=0xFF;
	PORTA=0x00;
	PORTB=0x00;
	PORTD=0x00;	
}

void forward()
{
	PORTD=(1<<PD2)|(0<<PD3)|(1<<PD4)|(0<<PD5);
	// _delay_ms(5);
}

void right()
{
	PORTD=(1<<PD2)|(0<<PD3)|(0<<PD4)|(0<<PD5);
	// _delay_ms(500);
}

void left()
{
	
	PORTD=(0<<PD2)|(0<<PD3)|(1<<PD4)|(0<<PD5);
	// _delay_ms(500);
}

void stop()
{
	PORTD=(0<<PD2)|(0<<PD3)|(0<<PD4)|(0<<PD5);
	//_delay_ms(500);
}

void reverse()
{
	PORTD=(0<<PD2)|(0<<PD3)|(0<<PD4)|(0<<PD5);
	PORTA=0x00;
	_delay_us(5);
	PORTA=0xF0;
	_delay_us(10);
	PORTA=0x00;
	_delay_us(5);
	
	for(i=0;i<600000;i++)
	{
		if(bit_is_set(PINC,2))
		continue;	//Line is still low, so wait
		else
		break;		//High edge detected, so break.
	}
                
	PORTD=(0<<PD2)|(1<<PD3)|(0<<PD4)|(1<<PD5);
	// _delay_us(100);
}

void tlong()
{
	PORTD=(0<<PD2)|(0<<PD3)|(0<<PD4)|(0<<PD5);
	// _delay_ms(500);
}

void tshort()
{
	PORTD=(0<<PD2)|(0<<PD3)|(0<<PD4)|(0<<PD5);
	// _delay_ms(500);
}

void unmatch()
{
	PORTD=(0<<PD2)|(0<<PD3)|(0<<PD4)|(0<<PD5);
	// _delay_ms(500);
}

void obstacle()
{
	PORTD=(0<<PD2)|(0<<PD3)|(0<<PD4)|(0<<PD5);
	// _delay_ms(500);
}

int main()
{  
  init();
	while(1)
	{		
		i=PINB&0b11111111;
		switch(i)
		{
			case 0b000000001:forward();
			break;
			
			case 0b00000011:right();
			break;
			
			case 0b000000101:left();
			break;
			
			case 0b000000111:stop();
			break;
			
			case 0b000001001:reverse();
			break;
			
			case 0b001010101:tlong();
			break;
			
			case 0b001100110:tshort();
			break;

			case 0b001110111:unmatch();
			break;
		}
	}
}
