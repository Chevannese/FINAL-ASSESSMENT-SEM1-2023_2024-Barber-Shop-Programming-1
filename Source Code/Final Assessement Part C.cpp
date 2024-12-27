/*Author: Chevannese Ellis
Date: December 9, 2023
Description: A digital system to help manage daily operations at a barber shop.
*/

#include <stdio.h>
#include <string.h>

int main()
{
	char name[20];
	char service;
	int snum,minutes,cNum1,cNum2,cNum3,totC;
	double tot_station1, tot_station2, tot_station3, commission1, commission2, commission3, statEarn, rev, rent, totCommission, price;
	
	//Initializes the variables that are used within and outside of loop
	cNum1 = 0;
	cNum2 = 0;
	cNum3 = 0;
	tot_station1= 0;
	tot_station2 = 0;
	tot_station3 = 0;
	rev=0;
	
	for (minutes = 0;minutes<=720;minutes=minutes+30)	//Stimulates the operation of a barbershop
	{
		printf("Please enter name (Enter '999' to finish): "); 
		scanf("%s",&name);
		if (strcmp(name, "999") == 0) //999 is used as a terminating value in case user wants code to end
		{
			break;
		}
		while (strlen(name) <3)								//Loop that validates if name is at least three characters long
		{
			printf("Enter at least 3 letters or more\nRenter name please: ");
			scanf("%s",&name);
		}
		//Displays menu of babershop services to user and prompts she or he to enter a code which reads the service inputed
		printf("M = Men's Haircut - $1000\nS = Men's Head Shave - $1300\nC = Children's Haircut - $600\nG = Children's Head Shave - $900\nB = Beard/Mustache Lineup - $650\nE = Eyebrow Shave - $400");
		printf("\nPlease enter the service (M, S, C, G, B, E): ");
		scanf(" %c",&service);
		//Loop that validates that service inputed is based on the barbershop menu
		while (service != 'M' && service != 'S' && service != 'C' && service != 'G' && service != 'B' && service != 'E')
		{
			printf("Please reread menu\nEnter the service (M, S, C, G, B, E): ");
			scanf(" %c",&service);
		}
		//Case Structure is used to assign a value to price based on service selected
		switch (service)
		{
			case 'M':
				price = 1000.00;
				break;
			case 'S':
				price = 1300.00;
				break;
			case 'C':
				price = 600.00;
				break;
			case 'G':
				price = 900.00;
				break;
			case 'B':
				price = 650.00;
				break;
			case 'E':
				price = 400.00;
				break;
			default:
				printf("Service NOT OFFERED\n");			
		}
		printf("Please enter the station number (1,2,3): "); 	//Prompts user to enter a station number
		scanf("%d",&snum); 										//Reads the value of station number
		
		while (snum <1 || snum >3)								//Validates that station number is within the range of 1,2, or 3
		{
			printf("Invalid Station. Please enter station number: ");
			scanf("%d",&snum);
		}
		//Case Structure is used to count each station number selected and accumulate the total price of each station
		switch (snum)
		{
		 	case 1:
				tot_station1 = tot_station1 + price;
				cNum1 = cNum1 + 1;
				break;
 			case 2:
				tot_station2 = tot_station2 + price;
				cNum2 = cNum2 + 1;
				break;
			case 3:
				tot_station3 = tot_station3 + price;
				cNum3 = cNum3 + 1;
				break;
			default:
				printf ("Invalid Station. Please enter station Number (1, 2, 3): ");
		}
		//Displays Customer Receipt
		printf("\n");
		printf("Customer Receipt");
		printf("\nCustomer Name: %s",name);
		printf("\nService Selected: %c, ",service);
		//IF Statement is used to display the service selected based on code inputted by user
		if (service == 'S')
		{
			printf("Men's Head Shave\n");
		}
		else
		{
			if (service == 'C')
			{
				printf("Children's Haircut\n");
			}
			else
			{
				if (service == 'G')
				{
					printf("Children's Head Shave\n");	
				}	
				else
				{
					if (service == 'B')
					{
						printf("Beard/Mustache Lineup\n");
					}
					else
					{
						if (service == 'M')
						{
							printf("Men's Haircut\n");
						}
						else
						{
							printf("Eyebrow Shave\n");
						}
					}
				}	
			}
		}
		printf("Cost: $%.f\n",price);
		printf("Station Number: %d\n\n",snum);
	}
	//Calculations are done after the For Loop is terminated
	statEarn = tot_station1 + tot_station2 + tot_station3;
	totC = cNum1 + cNum2 + cNum3;
	commission1 = tot_station1 - (0.05 * tot_station1 + 500);
	commission2 = tot_station2 - (0.05 * tot_station2 + 500);
	commission3 = tot_station3 - (0.05 * tot_station3 + 500);
	totCommission = commission1 + commission2 + commission3;
	rent = (0.05 * statEarn) + (500 * 3);
	rev = totCommission + rent;
	//Displays the information once the system reaches 720 minutes or when system is terminated by '999'
	printf("Total sales per station for the day\nStation 1 - $%.f\nStation 2 - $%.f\nStation 3 - $%.f\n",tot_station1,tot_station2,tot_station3);
	printf("Total customers per station for the day\nStation 1: %d\nStation 2: %d\nStation 3: %d\n",cNum1,cNum2,cNum3);
	printf("Commissions for the day\nStation 1 Commission: $%.1f\nStation 2 Commission: $%.1f\nStation 3 Commission: $%.1f",commission1,commission2,commission3);
	printf("\nTotal Day's Sales: $%.f",statEarn);
	printf("\nTotal customers for the day: %d",totC);
	printf("\nRevenue for the day: $%.1f",rev);
	return 0;
}
