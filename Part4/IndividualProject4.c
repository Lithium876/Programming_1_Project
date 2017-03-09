/*
ID#: 140 1375
Name: Lomar Lilly
Course: CMP 1024 Programming 1
Assignment: Individual Project Part 4 - Group UE3
*/

#include <stdio.h> /*Allows the use of the input and output functions*/
#include <conio.h> /*Allows the use of the get character function that holds display on screen*/
#include <ctype.h> /*Allows the use of the case converter funtion*/
#include <stdlib.h> /*Allows the use of the system color function*/

int main()
{ 
	/*DECLARATION OF VARIABLES*/
	int i, j, x, n, check, patientnum[15];
	float sum, refcost[15];
	char menu;

	system("COLOR 1E"); /*Gives the program color, blue and yellow. My favourite ^_^ */
	do
	{
		system("cls"); /*Clears the screen*/
		puts("\t  ================================================================");
		puts("\t  | BROCKLINE MEDICAL CENTRE EMERGENCY PATIENT MANAGEMENT SYSTEM |");
		puts("\t  ================================================================");
		printf("\t\t| Options |                 Actions                |\n");
		puts("\t\t====================================================");
		printf("\t\t|   A.    | Enter Patient data                     |\n");
		printf("\t\t|   B.    | Display Total Cost Report              |\n");
		printf("\t\t|   C.    | Determine Patient Occurrence and Cost  |\n");
		printf("\t\t|   D.    | Exit                                   |\n");
		puts("\t\t====================================================");
		printf("\nEnter an option from menu above\n");
		scanf("%c",&menu);
		menu=toupper(menu); /*Converts all menu input to UPPERCASE*/
		switch(menu)
		{
			case 'A':
				/*Accepts user input until the patient number is -9 or 15 records have been recorded*/
				printf("\nEnter -9 for the patient number to signal end of input.\n");
				for(i=0;i<15;i++)
				{
					printf("\nPlease Enter Patient Number\n");
					scanf("%d",&patientnum[i]);
					if(patientnum[i]!=-9)
					{
						printf("\nPlease Enter Referral Cost\n");
						scanf("%f",&refcost[i]);
					}
					else
						break; /*Ends the loop*/
				}
				break;
			case 'B':
				/*Counts, Calcuates and displays number of records and the total sum of referral costs entered*/
				sum=0;
				puts("\n\t\t=========================================");
				printf("\t\t|   Patient Number   |    Refertal Cost |\n");
				puts("\t\t=========================================");
				for(j=0;j<i;j++)
		   	 	{
		        	printf("\t\t| %d.    %d              $%.2f\n",j+1, patientnum[j], refcost[j]); /*'j+1' acts as a counting variable*/
		        	sum=sum+refcost[j]; /*calculates the sum of referral costs entered*/
		    	}
		    	puts("\t\t========================================");
		    	printf("\t\t|Total Referral Cost:     $%.2f\n",sum);
		    	puts("\t\t========================================");
		    	getch();/*Holds display on screen*/
		    	break; 
			case 'C':
				/*Allows the user to check the occurance of a particular patient number
				  and calculates the total sum of referral cost for that particulat patient number.*/
		    	sum=0;
		    	x=0;
				printf("\nEnter a Patient Number: \n");
				scanf("%d",&check);
				for (n=0;n<i;n++) 
				{
        			if (patientnum[n] == check) /*Searches the array for the patient number entered*/
        			{
            			x++; /*Counts the occurance of the patient number entered*/
            			sum=sum+refcost[n]; /*Calculates the sum of referral cost*/
        			}
   				}
   				if(x==0)
   					printf("\nPatient Not found\n");
   				else
   				{
   					printf("\n\t   Patient %d visited %d times\n",check, x );
   					puts("---------------------------------------------------");
   					printf("  Patient %d's Total Referral Cost is: $%.2f\n",check, sum );
   				}
   				getch();
				break;
		}
	}while(menu!='D'); /*Program runs until the user enters the exit option 'D'*/
	return 0;
}
