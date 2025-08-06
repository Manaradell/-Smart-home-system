#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "CLCD_interface.h"
#include "Kypd.h"
#include <util/delay.h>
#include <avr/io.h>

int main(void)
{
	U8 s1,s2,id11,flag=0,i=0;
		U8 id1, pass1;
		U8 count=0;
		U8 *str3 = "Enter your pass:";
		U8 *str6 = "System Closed";
	DIO_enumSetPinDirection(DIO_PIN3,DIO_PORTA,DIO_OUTPUT);
	DIO_enumSetPinDirection(DIO_PIN4,DIO_PORTA,DIO_OUTPUT);
	
	CLCD_init();
	Kypad_init();

	while (1)
	{
		
		
		CLCD_CLR();     
		CLCD_WriteChar(" ");    
		U8 *str1 = "Welcome";  
		CLCD_GoTo(0, 0);       
		CLCD_SendString(str1); 
		_delay_ms(5000);       

		
		CLCD_CLR();         
		U8 *str2 = "Enter Your ID:";  
		CLCD_GoTo(0, 0);    
		CLCD_WriteChar(" ");    
		CLCD_SendString(str2); 
	
		
		while (1)
		{
		
            id1 = Kypad_GetKey();
			if (id1 != 'f') 
			{
				
				CLCD_GoTo(1, 0);      
				
				CLCD_WriteChar(id1); 
				CLCD_CLR();  
				_delay_ms(5000);

				
				if (id1 == '5' || id1 == '7')
				{
					id11=id1,
					CLCD_CLR(); 
					CLCD_WriteChar(" ");
					CLCD_SendString(str3);
					_delay_ms(2000);
					
					break;
				}
					else
					{
						CLCD_CLR();
						CLCD_WriteChar(" ");
						CLCD_SendString(str6);  
						_delay_ms(5000);  
						}
						
					}
				
			}
			
			
		
	U8 count = 0;  
	while (count < 3) 
	{
		pass1 = Kypad_GetKey();
		if (pass1 != 'f')  
		{
			CLCD_GoTo(1, 0);      
			CLCD_CLR();
			CLCD_WriteChar(pass1);   
			_delay_ms(5000);

			
			if ((pass1 == '6' && id11 == '5') || (pass1 == '8' && id11 == '7'))
			{
				CLCD_CLR();
				CLCD_GoTo(0, 0);
				CLCD_WriteChar(" ");
				U8 *str4 = "1-Room1";
				U8 *str5 = "2-Room2";
				CLCD_SendString(str4);
				CLCD_GoTo(2, 0);
				CLCD_WriteChar(',');
				CLCD_SendString(str5);
				_delay_ms(2000);
				break;
			}
			else
			{
				count++;  
				if (count < 3)  
				{
					CLCD_CLR();
					CLCD_WriteChar(" ");
					
					CLCD_SendString(str3);
					_delay_ms(2000);
				}
				else  
				{
					CLCD_CLR();
					CLCD_WriteChar(" ");
					CLCD_SendString(str6); 
					_delay_ms(5000);
					return 0;
				}
			}
		}
	}

	
		
			while(1)
			{
				U8 ch=Kypad_GetKey();
				U8 *str7 = "1-Led";
				U8 *str8 = "2-Fan";
				U8 x=',';
				if (ch!='f')
				{
					if(ch=='1'||ch=='2')
					{
						
						
						CLCD_WriteChar(ch);
						CLCD_CLR();
						CLCD_GoTo(0,0);
						CLCD_WriteChar(" ");
						CLCD_SendString(str7);
						CLCD_GoTo(2,0);
						CLCD_WriteChar(x);
						CLCD_SendString(str8);
						_delay_ms(2000);
						
						break;
					}
				}
				
			}
			while(1)
			{
				U8 ch1=Kypad_GetKey();
				U8 *str7 = "1-ON";
				U8 *str8 = "2-OFF";
				U8 x=',';
				if (ch1!='f')
				{
					if(ch1=='1'||ch1=='2')
					{
						
						
						CLCD_WriteChar(ch1);
						CLCD_CLR();
						CLCD_GoTo(0,0);
						CLCD_WriteChar(" ");
						CLCD_SendString(str7);
						CLCD_GoTo(4,0);
						CLCD_WriteChar(x);
						CLCD_SendString(str8);
						_delay_ms(2000);
						s1=ch1;
						break;
					}
				}
				
			}
				while(1)
				{
					U8 ch1=Kypad_GetKey();
					U8 *str11="Led ON";
					U8 *str12="Led OFF";
					U8 *str13="Fan ON";
					U8 *str14="Fan OFF";
					U8 x=',';
					if (ch1!='f')
					{
						CLCD_CLR();
						if(s1=='1'&&ch1=='1')
						{
							CLCD_GoTo(0,0);
							CLCD_WriteChar(" ");
							CLCD_SendString(str11);
							DIO_enumSetPinValue(DIO_PIN3,DIO_PORTA,DIO_HIGH);
						}
						else if(s1=='1'&&ch1=='2')
						{
							CLCD_GoTo(0,0);
							CLCD_WriteChar(" ");
							CLCD_SendString(str12);
							DIO_enumSetPinValue(DIO_PIN3,DIO_PORTA,DIO_LOW);
						}
						else if(s1=='2'&&ch1=='1')
						{
							CLCD_GoTo(0,0);
							CLCD_WriteChar(" ");
							CLCD_SendString(str13);
							DIO_enumSetPinValue(DIO_PIN4,DIO_PORTA,DIO_HIGH);
						}
						else
						{
							CLCD_GoTo(0,0);
							CLCD_WriteChar(" ");
							CLCD_SendString(str14);
								DIO_enumSetPinValue(DIO_PIN4,DIO_PORTA,DIO_LOW);
							
						}
					}
				}
			break;
		}
	}



			
		

					
		
	
	

