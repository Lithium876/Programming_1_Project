/**
=======================================================
ID#: 140 1375
Author: Lomar Lilly
Course: Programming 1 
Individual Project Part 2
Program Purpose: Calcualte and Display Patient's Bill
========================================================
**/
//HEADER FILES
#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<stdlib.h>
#define stand_fee 1500 //declares standard fee as a constant with value 1500 

int main()
{
	//VARIABLE DECLARATIONS
	float bill;
	int idnum;
	char patient[25], refcode, response, priority; //"patient[25]" is an array declared to hold patient's name
	system("COLOR 1E"); //Add color to the program (blue and yellow)
    
	//INPUTS
	puts(" |----------------------------------------------------------------------------|");
	puts(" |        BROCKLINE MEDICAL CENTRE EMERGENCY PATIENT MANAGEMENT SYSTEM        |");
	puts(" |----------------------------------------------------------------------------|");
	puts("");//prints an empty line on screen
	printf("Please Enter Patient's ID Number: ");
	scanf("%d",&idnum);
	printf("Please Enter Patient's Name: ");
	scanf(" %[^\n]s",patient); //Accepts input and store it in variable name until the return key is pressed
	printf("Please Enter Patient's Priority Level: ");
	scanf(" %c",&priority);

	//PROCESSING
	if (priority=='1')
	{
		refcode='D';
		bill=stand_fee + 1500;
		puts("");  
		//Prints a menu on screen
		puts(" |----------------------------------------------------------------------------|");
		puts(" | Referral Code |               Assignment                  |  Referral Cost |");
		puts(" |----------------------------------------------------------------------------|");
		puts(" |       D.      |  Patient referred to Doctor on Duty       |    $ 1 500     |");
		puts(" |----------------------------------------------------------------------------|");
		puts("                         | Standard Fee: $ 1 500 |                             ");
	}
	else
	{
		if (priority=='2')
	{
		printf("\n"); ////prints an empty line on screen 
		puts(" |----------------------------------------------------------------------------|");
		puts(" | Referral Code |               Assignment                  |  Referral Cost |");
		puts(" |----------------------------------------------------------------------------|");
		puts(" |       N.      |  Patient referred to Nurses Treatment room|     $ 700      |");
		puts(" |----------------------------------------------------------------------------|");
		puts(" |       H.      |  Patient referred to Health Centre        |     $ 100      |");
		puts(" |----------------------------------------------------------------------------|");
		puts(" |               |                                           |   Ambulance:   |");
		puts(" |       R.      |  Patient referred to Regional Hospital    |    $ 4 500     |");
		puts(" |               |                                           |  No Ambulance: |");
		puts(" |               |                                           |      $ 200     |");
		puts(" |----------------------------------------------------------------------------|");
		puts(" |       A.      |  Patient abandoned ER                     |      $ 0       |");
	    puts(" |----------------------------------------------------------------------------|");
		puts("                         | Standard Fee: $ 1 500 |                             ");
		printf("\nEnter Referral Code: ");
		scanf(" %c",&refcode);
		refcode=toupper(refcode); //converts all lower case character to upper case characters
		switch (refcode)
		{
		case 'N': 
			bill=stand_fee + 700;
			break;
		case 'H': 
			bill=stand_fee + 100;
			break;
		case 'R': 
			printf("Ambulance Required? y or n: ");
			scanf(" %c",&response);
			if (response=='y')
				bill= stand_fee + 4500;
			else
			{
				if (response=='n')
					bill=stand_fee + 200;
				else
				{
					printf("Invalid Input");
					getch();//Holds error message on screen until a character is pressed
					return 1;//indicates that the program didn't run successfully
				}
			}
			break;
		case 'A': 
			bill=stand_fee;
			break;
		default:
			printf("Invaid Input");
			getch();
			return 1;
			break;
		}
	  }
		else
		{
			printf("Invaild Input");
			getch();
			return 1;
		}
	}
	//OUTPUT
	puts("");
	puts("\t\t  |=========================================|");//"\t" adds tab spaces to the screen
	printf("\t\t  |Patient's ID Number: %d \n",idnum);
	puts("\t\t  |-----------------------------------------|");
	printf("\t\t  |Patient's Name:      %s \n",patient);
	puts("\t\t  |-----------------------------------------|");
	printf("\t\t  |Referral Code:       %c \n",refcode);
	puts("\t\t  |-----------------------------------------|");
	printf("\t\t  |Patient's Bill:      $%.2f\n",bill);
	puts("\t\t  |=========================================|");
	getch(); //holds output on screen until a character is pressed
	return 0; //indicate that the program ran sucessfully 
}
