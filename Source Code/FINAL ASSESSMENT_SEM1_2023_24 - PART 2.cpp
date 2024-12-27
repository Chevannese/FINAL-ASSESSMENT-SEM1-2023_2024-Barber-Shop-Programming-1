/*Authors: Chevannese Ellis and James Cameron
Date: December 16, 2023
Description: A digital system to help manage daily operations at a barber shop.
*/

#include <stdio.h>
#include <string.h>
#define tot_cust 15

int main()
{
	char name[tot_cust][50];
	char password[1];
	int id[tot_cust];
	int service[tot_cust];
	int snum[tot_cust],minutes,cNum1,cNum2,cNum3,totC,record;
	double tot_station1, tot_station2, tot_station3, commission1, commission2, commission3, statEarn, rev, rent, totCommission, price;
	
	//Initializes the variables that are used within and outside of loop
	cNum1 = 0;
	cNum2 = 0;
	cNum3 = 0;
	tot_station1= 0;
	tot_station2 = 0;
	tot_station3 = 0;
	rev=0;
	
	for (record = 0;record <tot_cust;record++)	//Stimulates the operation of a barbershop
	{
		printf("Enter the password: ");
		scanf("%s",&password);
		while (strcmp(password,"14309")!=0)
		{
			printf("Invalid password\nPlease enter password: ");
			scanf("%s",&password);
		}
		printf("Please enter Customer ID: ");
		scanf("%d",&id[record]);
		
		printf("Please enter name: "); 
		scanf("%s",name[record]);
		
		while (strlen(name[record]) <3)								//Loop that validates if name is at least three characters long
		{
			printf("Enter at least 3 letters or more\nRenter name please: ");
			scanf("%s",&name[record]);
		}
		
		//Displays menu of babershop services to user and prompts she or he to enter a code which reads the service inputed
		printf("1 = Men's Haircut - $1000\n2 = Men's Head Shave - $1300\n3 = Children's Haircut - $600\n4 = Children's Head Shave - $900\n5 = Beard/Mustache Lineup - $650\n6 = Eyebrow Shave - $400");
		printf("\nPlease enter the service (1, 2, 3, 4, 5, 6): ");
		scanf("%d",&service[record]);
		//Loop that validates that service inputed is based on the barbershop menu
		while (service[record] != 1 && service[record] != 2 && service[record] != 3 && service[record] != 4 && service[record] != 5 && service[record] != 6)
		{
			printf("Please reread menu\nEnter the service (1, 2, 3, 4, 5, 6): ");
			scanf("%d",&service[record]);
		}
		//Case Structure is used to assign a value to price based on service selected
		switch (service[record])
		{
			case 1:
				price = 1000.00;
				break;
			case 2:
				price = 1300.00;
				break;
			case 3:
				price = 600.00;
				break;
			case 4:
				price = 900.00;
				break;
			case 5:
				price = 650.00;
				break;
			case 6:
				price = 400.00;
				break;
			default:
				printf("Service NOT OFFERED\n");			
		}
		printf("Please enter the station number (1,2,3): "); 	//Prompts user to enter a station number
		scanf("%d",&snum[record]); 										//Reads the value of station number
		
		while (snum[record] <1 || snum[record] >3)								//Validates that station number is within the range of 1,2, or 3
		{
			printf("Invalid Station. Please enter station number: ");
			scanf("%d",&snum[record]);
		}
		//Validation #1 check to see if Station 1 is at full capacity
		if (snum[record] ==1 && cNum1 >=5)
		{
			do
			{
				printf("Station 1 is at full capacity. Please select a different station number: ");
				scanf("%d",&snum[record]);
			}while (snum[record]==1);
		}
		//Validation #1 check to see if Station 2 is at full capacity
		if (snum[record] ==2 && cNum2 >=5)
		{
			do
			{
				printf("Station 2 is at full capacity. Please select a different station number: ");
				scanf("%d",&snum[record]);
			}while (snum[record]==2);
		}
		//Validation #1 check to see if Station 3 is at full capacity
		if (snum[record] ==3 && cNum3 >=5)
		{
			do
			{
				printf("Station 3 is at full capacity. Please select a different station number: ");
				scanf("%d",&snum[record]);
			}while (snum[record]==3);
		}
		
		//Validation #2 check to see if Station 1 is at full capacity
		if (snum[record] ==1 && cNum1 >=5)
		{
			do
			{
				printf("Station 1 is at full capacity. Please select a different station number: ");
				scanf("%d",&snum[record]);
			}while (snum[record]==1);
		}
		//Validation #2 check to see if Station 2 is at full capacity
		if (snum[record] ==2 && cNum2 >=5)
		{
			do
			{
				printf("Station 2 is at full capacity. Please select a different station number: ");
				scanf("%d",&snum[record]);
			}while (snum[record]==2);
		}
		//Validation #2 check to see if Station 3 is at full capacity
		if (snum[record] ==3 && cNum3 >=5)
		{
			do
			{
				printf("Station 3 is at full capacity. Please select a different station number: ");
				scanf("%d",&snum[record]);
			}while (snum[record]==3);
		}
		//Case Structure is used to count each station number selected and accumulate the total price of each station
		switch (snum[record])
		{
		 	case 1:
				tot_station1 = tot_station1 + price;
				cNum1 = cNum1 + 1;
				commission1 = tot_station1 - (0.05 * tot_station1 + 500);
				break;
 			case 2:
				tot_station2 = tot_station2 + price;
				cNum2 = cNum2 + 1;
				commission2 = tot_station2 - (0.05 * tot_station2 + 500);
				break;
			case 3:
				tot_station3 = tot_station3 + price;
				cNum3 = cNum3 + 1;
				commission3 = tot_station3 - (0.05 * tot_station3 + 500);
				break;
			default:
				printf ("Invalid Station. Please enter station Number (1, 2, 3): ");
		}
		
		//Displays Customer Receipt
		printf("\n");
		printf("Customer Receipt");
		printf("\nCustomer Name: %s",name[record]);
		printf("\nCustomer ID: %d",id[record]);
		printf("\nService Selected: %d,",service[record]);
		//IF Statement is used to display the service selected based on code inputted by user
		if (service[record] == 2)
		{
			printf(" Men's Head Shave\n");
		}
		else
		{
			if (service[record] == 3)
			{
				printf(" Children's Haircut\n");
			}
			else
			{
				if (service[record] == 4)
				{
					printf(" Children's Head Shave\n");	
				}	
				else
				{
					if (service[record] == 5)
					{
						printf(" Beard/Mustache Lineup\n");
					}
					else
					{
						if (service[record] == 1)
						{
							printf(" Men's Haircut\n");
						}
						else
						{
							if (service[record] == 6)
							{
								printf(" Eyebrow Shave\n");
							}	
						}
					}
				}	
			}
		}
		printf("Cost: $%.f\n",price);
		printf("Station Number: %d\n\n",snum[record]);
	}
	//Calculations are done after the For Loop is terminated
	statEarn = tot_station1 + tot_station2 + tot_station3;
	totC = cNum1 + cNum2 + cNum3;
	totCommission = commission1 + commission2 + commission3;
	rent = (0.05 * statEarn) + (500 * 3);
	rev = totCommission + rent;
	
	//Displays the information once the system reaches 15 customers
	printf("Customers who selected 'Eyebrow Shave'\n");    //Displays all customers that selected Eyebrow Shave
	printf("Customer ID   Station Number   Customer Name\n");
	for (record = 0;record <tot_cust; record++)
	{
		if (service[record] == 6)
		{
			printf("    %d             %d              %s\n",id[record],snum[record],name[record]);
		}
	}
	printf("\nStation 1 Customers\n");						//Displays all the names of customers that selected station 1
	for (record = 0;record<tot_cust; record++)
	{
		if (snum[record] == 1)
		{
			printf("     %s\n",name[record]);
		}
	}
	printf("\nStation 2 Customers\n"); 						//Displays all the names of customers that selected station 2
	for (record = 0;record<tot_cust; record++)
	{
		if (snum[record] == 2)
		{
			printf("     %s\n",name[record]);
		}
	}
	printf("\nStation 3 Customers\n");						//Displays all the names of customers that selected station 3
	for (record = 0;record<tot_cust; record++)
	{
		if (snum[record] == 3)
		{
			printf("     %s\n",name[record]);
		}
	}
	
	//Displays the totals generated from the operation of the barbershop for the day
	printf("\nTotal sales per station for the day\nStation 1 - $%.f\nStation 2 - $%.f\nStation 3 - $%.f\n",tot_station1,tot_station2,tot_station3);
	printf("Total customers per station for the day\nStation 1: %d\nStation 2: %d\nStation 3: %d\n",cNum1,cNum2,cNum3);
	printf("Commissions for the day\nStation 1 Commission: $%.1f\nStation 2 Commission: $%.1f\nStation 3 Commission: $%.1f",commission1,commission2,commission3);
	printf("\nTotal Day's Sales: $%.f",statEarn);
	printf("\nTotal customers for the day: %d",totC);
	printf("\nRevenue for the day: $%.1f",rev);
	return 0;
}
