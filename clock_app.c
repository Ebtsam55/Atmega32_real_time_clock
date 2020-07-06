/*
 * clock_app.c
 *
 * Created: 4/27/2020 5:45:02 PM
 *  Author: Ebtsam
 */ 


#include "lcd.h"
#include "timer.h"
#include "EEPROM.h"

#define sec_add 0
#define min_add 1
#define hour_add 2
uint8_t min, sec, hour ,flag ; 

void clock_update();
int main(void)
{
  LCD_init();
  timer0_normal_init();
  
  sec=EEPROM_read(sec_add);
  min=EEPROM_read(min_add);
  hour=EEPROM_read(hour_add);
  clock_update();
 
    while(1)
    { 
		if(flag == 1){
			clock_update();
			clock_display();
			flag = 0;
		}
		continue;
		
    }
}

ISR(TIMER0_OVF_vect)
{
	static uint16_t count =0; 
	if (count==61) 
	{   
	    	count=0; 
			sec++;	
			flag=1;
			clock_update();
			clock_display();
	}
	count++;

}

void clock_update()
{
	
	if(sec>59)
	{ sec=0;
	  min++;
	}	 
	if(min>59)
	 {   min=0;
		 hour++;
	 }
	if(sec>=59 && min>=59 && hour>=23)
	{
		sec=0; 
		min=0;
		hour=0;
	}

    EEPROM_write(sec_add,sec);
	EEPROM_write(min_add,min);
	EEPROM_write(hour_add,hour);
				
}

void clock_display()
{ 
	uint8_t sec_1=sec, sec_2=0 , min_1=min , min_2=0 , hour_1=hour, hour_2=0;
	
	if(sec>9)
	{
		sec_1=sec%10;
		sec_2=sec/10;
	}
	if(min>9)
	{
		min_1=min%10;
		min_2=min/10;
	}
	if(hour>9)
	{
		hour_1=hour%10;
		hour_2=hour/10;
	}
	    
	    LCD_clear();
		
		LCD_goToRowColumn(0,0);
		LCD_write_num(hour_2);
		LCD_goToRowColumn(0,1);
		LCD_write_num(hour_1);
		
		LCD_goToRowColumn(0,2);
		LCD_write_char(':');
		
		LCD_goToRowColumn(0,3);
		LCD_write_num(min_2);
		LCD_goToRowColumn(0,4);
		LCD_write_num(min_1);
		
		LCD_goToRowColumn(0,5);
		LCD_write_char(':');
		
		LCD_goToRowColumn(0,6);
		LCD_write_num(sec_2);
		LCD_goToRowColumn(0,7);
		LCD_write_num(sec_1);
}