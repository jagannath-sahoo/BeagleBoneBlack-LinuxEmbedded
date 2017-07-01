/*
 ============================================================================
 Name        : 7segcnt.c
 Author      : Kiran
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 DIY: IMPLEMENT UPDOWN COUNTING
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include<stdint.h>
#include <string.h>
#include <unistd.h>

uint8_t numbers[10]={0x77,0x06,0xB3,0x97,0xc6,0xD5,0xf5,0x07,0xf7,0XD7};

/*
P8.7 ( GPIO_66); a
P8.8 ( GPIO_67); b
P8.9 ( GPIO_69); c
P8.10 ( GPIO_68);dp (h)
P8.11 ( GPIO_45);d
P8.12 ( GPIO_44);e
P8.14 ( GPIO_26);f
P8.16 ( GPIO_46);g */

#define SYS_GPIO_PATH "/sys/class/gpio"

/* This is the array of file descriptors for each segment of the display */
FILE *sysgpio[8];


int initialize_all_gpios(void)
{
	char *str="out";
	/* first init the direction as out */
	/* open the file in both read and write mode */
	sysgpio[0] = fopen("/sys/class/gpio/gpio66/direction", "w+" );
	/* fopen returns 0, the NULL pointer, on failure */
	if(sysgpio[0] != 0)
	{

		fprintf(sysgpio[0],"%s",str);
		fclose(sysgpio[0]);
		sysgpio[0] = fopen("/sys/class/gpio/gpio66/value", "w+" );
		fprintf(sysgpio[0],"%d",0);
		fflush(sysgpio[0]);
	}
	else
	{
		return -1;
	}


/* first init the direction as out */
	/* open the file in both read and write mode */
	sysgpio[1] = fopen("/sys/class/gpio/gpio67/direction", "w+" );
	/* fopen returns 0, the NULL pointer, on failure */
	if(sysgpio[1] != 0)
	{
		fprintf(sysgpio[1],"%s","out");
		fclose(sysgpio[1]);
		sysgpio[1] = fopen("/sys/class/gpio/gpio67/value", "w+" );
		fprintf(sysgpio[1],"%d",0);
		fflush(sysgpio[1]);
	}
	else
	{
		return -1;
	}

/* first init the direction as out */
	/* open the file in both read and write mode */
	sysgpio[2] = fopen("/sys/class/gpio/gpio69/direction", "w+" );
	/* fopen returns 0, the NULL pointer, on failure */
	if(sysgpio[2] != 0)
	{
		fprintf(sysgpio[2],"%s","out");
		fclose(sysgpio[2]);
		sysgpio[2] = fopen("/sys/class/gpio/gpio69/value", "w+" );
		fprintf(sysgpio[2],"%d",0);
		fflush(sysgpio[2]);
	}
	else
	{
		return -1;
	}



/* first init the direction as out */
	/* open the file in both read and write mode */
	sysgpio[3] = fopen("/sys/class/gpio/gpio68/direction", "w+" );
	/* fopen returns 0, the NULL pointer, on failure */
	if(sysgpio[3] != 0)
	{
		fprintf(sysgpio[3],"%s","out");
		fclose(sysgpio[3]);
		sysgpio[3] = fopen("/sys/class/gpio/gpio68/value", "w+" );
		fprintf(sysgpio[3],"%d",0);
		fflush(sysgpio[3]);
	}
	else
	{
		return -1;
	}

/* first init the direction as out */
	/* open the file in both read and write mode */
	sysgpio[4] = fopen("/sys/class/gpio/gpio45/direction", "w+" );
	/* fopen returns 0, the NULL pointer, on failure */
	if(sysgpio[4] != 0)
	{
		fprintf(sysgpio[4],"%s","out");
		fclose(sysgpio[4]);
		sysgpio[4] = fopen("/sys/class/gpio/gpio45/value", "w+" );
		fprintf(sysgpio[4],"%d",0);
		fflush(sysgpio[4]);
	}
	else
	{
		return -1;
	}


/* first init the direction as out */
	/* open the file in both read and write mode */
	sysgpio[5] = fopen("/sys/class/gpio/gpio44/direction", "w+" );
	/* fopen returns 0, the NULL pointer, on failure */
	if(sysgpio[5] != 0)
	{
		fprintf(sysgpio[5],"%s","out");
		fclose(sysgpio[5]);
		sysgpio[5] = fopen("/sys/class/gpio/gpio44/value", "w+" );
		fprintf(sysgpio[5],"%d",0);
		fflush(sysgpio[5]);
	}
	else
	{
		return -1;
	}


/* first init the direction as out */
	/* open the file in both read and write mode */
	sysgpio[6] = fopen("/sys/class/gpio/gpio26/direction", "w+" );
	/* fopen returns 0, the NULL pointer, on failure */
	if(sysgpio[6] != 0)
	{
		fprintf(sysgpio[6],"%s","out");
		fclose(sysgpio[6]);
		sysgpio[6] = fopen("/sys/class/gpio/gpio26/value", "w+" );
		fprintf(sysgpio[6],"%d",0);
		fflush(sysgpio[6]);
	}
	else
	{
		return -1;
	}


/* first init the direction as out */
	/* open the file in both read and write mode */
	sysgpio[7] = fopen("/sys/class/gpio/gpio46/direction", "w+" );
	/* fopen returns 0, the NULL pointer, on failure */
	if(sysgpio[7] != 0)
	{
		fprintf(sysgpio[7],"%s","out");
		fclose(sysgpio[7]);
		sysgpio[7] = fopen("/sys/class/gpio/gpio46/value", "w+" );
		fprintf(sysgpio[7],"%d",0);
		fflush(sysgpio[7]);
	}
	else
	{
		return -1;
	}




return 0;

}

void Write_number(uint8_t value)
{

	int i=0,value1;


	for (i=0;i< 8;i++)
	{
		value1 =  ( value & ( 1 << i) );
		value1 = value1 >> i;
		fprintf(sysgpio[i],"%d", value1 );
		fflush(sysgpio[i]);
	}

}

void start_upcounting(int delay_value)
{

	if ( initialize_all_gpios() < 0)
	{
		printf("Error: Led init failed.. program exiting..\n");
	}else
	{
     printf("UP COUNTING.......\n");
		while(1)
       {
			uint8_t i =0;

			for(i=0;i<10;i++)
			{
				Write_number(numbers[i]);
				sleep(1);
			}

       }

	}

}

void start_downcounting(int delay_value)
{

	if ( initialize_all_gpios() < 0)
	{
		printf("Error: Led init failed.. program exiting..\n");
	}else
	{
     printf("DOWN COUNTING.......\n");
		while(1)
       {
			int i = 9;

			for(i=9;i >= 0 ;i--)
			{
				Write_number(numbers[i]);
				sleep(1);
			}

       }

	}



}

void start_updowncounting(int delay_value)
{

	/* DIY : Student has to implement this */
	printf("/* DIY : Student has to implement this */\n");


}

void start_randomcounting(int delay_value)
{

}

int main(int argc, char *argv[]) {
	printf("This program controls the USER LED3\n");

	if ( argc != 3 ) /* argc should be 3 for correct execution */
	{

		printf( "usage: %s <direction> <delay>\n", argv[0] );
		printf( "valid direction : up, down, updown\n");
		printf ("recommended delay range : 0 to 1000\n");
	}
	else
	{
		int value = atoi(argv[2]);
    	/* argc is correct , lets check argv */
    	if (strcmp(argv[1], "up") == 0)
    	{
    		start_upcounting(value);
    	}
    	else if (strcmp(argv[1], "down") == 0)
    	{
    		start_downcounting(value);
    	}
    	else if (strcmp(argv[1], "updown") == 0)
    	{
    		start_updowncounting(value);
    	}
    	else if (strcmp(argv[1], "random") == 0)
    	{
    		start_randomcounting(value);
    	}
    	else /* default: */
    	{
    		printf("Invalid direction values\n");
    		printf( "valid direction values : up, down,updown,random\n");
    	}
	}
}
