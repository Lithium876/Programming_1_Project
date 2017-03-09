#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>

int main()
{
	
	int priority, patientnum,D,N,H,R,count;
	char refcode;
	float refcost;
	count=0;
	D=0;
	N=0;
	H=0;
	R=0;
	system("COLOR 1E");
	/*INPUTS*/
	puts(" |----------------------------------------------------------------------------|");
	puts(" |        BROCKLINE MEDICAL CENTRE EMERGENCY PATIENT MANAGEMENT SYSTEM        |");
	puts(" |----------------------------------------------------------------------------|");
	puts("");/*prints an empty line on screen*/
	printf("Enter Patient Number\n");
	scanf("%d",&patientnum);
	while(patientnum!=-9)
	{
		if(count<50)
		{
			printf("\nEnter priority level\n");
			scanf(" %d",&priority);
			if(priority==1)
				{
					refcode='D';
					refcost=1500;
					D=1500+D;
				}
			else
				{
					if(priority==2)
					{
						system("cls");
						puts(" |----------------------------------------------------------------------------|");
						puts(" |        BROCKLINE MEDICAL CENTRE EMERGENCY PATIENT MANAGEMENT SYSTEM        |");
						puts(" |----------------------------------------------------------------------------|");
						puts("");/*prints an empty line on screen*/
						puts(" |----------------------------------------------------------------------------|");
						puts(" | Referral Code |               Assignment                  |  Referral Cost |");
						puts(" |----------------------------------------------------------------------------|");
						puts(" |       N.      |  Patient referred to Nurses Treatment room|     $ 700      |");
						puts(" |----------------------------------------------------------------------------|");
						puts(" |       H.      |  Patient referred to Health Centre        |     $ 100      |");
						puts(" |----------------------------------------------------------------------------|");
						puts(" |       R.      |  Patient referred to Regional Hospital    |    $ 4 500     |");
						puts(" |----------------------------------------------------------------------------|");
						printf("\nEnter Referral Code\n");
						scanf(" %c",&refcode);
						refcode=toupper(refcode);
						switch(refcode)
						{
							case 'N':
								refcost=700;
								N=refcost+N;
								break;
							case 'H':
								refcost=100;
								H=refcost+H;
								break;
							case 'R':
								refcost=4500;
								R=refcost+R;
								break;
							default:
								printf("\a\nInvalid Input\n");
								getch();
								return 1;
								break;
						}
					}
				else
					{
						printf("\a\nInvalid Input\n");
						getch();
						return 1;
						break;
					}
				}
			count=count+1;
			printf("\nPatient Number: %d\n",patientnum);
			printf("Priority Level: %d\n",priority);
			printf("Patient's Refferal Cost: $%.2f\n\n",refcost);
			printf("Enter patient number\n");
			scanf("%d",&patientnum);
		}
		else 
		{
			printf("You've reached the limit\n");
			break;
		}
	}
	system("cls");
	printf("\nTotal Refferal Cost: D:$%d, N:$%d, H:$%d, R:$%d",D,N,H,R);
	printf("\nTotal Patients Seen: %d",count);
	getch();
	return 0;
	return 0;
}
