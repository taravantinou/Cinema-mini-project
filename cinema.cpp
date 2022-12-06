#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>
#define ROOM 10
#define STR_SIZE 256
#define MONTH 12
int main (void)
{
	char ROOMS[ROOM][STR_SIZE];
	float CASH[ROOM][MONTH],SUMEISPR[ROOM],MOEISPR[ROOM],min;
	int i,j,k;
	bool same;
		for (i=0; i<ROOM; i++)
	{
		do
		{
			printf ("Please give the name of the room number: %d: \n",i+1);
			scanf("%s", ROOMS[i]);
			same=0;
			for (j=0; j<i; j++)
			if (strcmp(ROOMS[j],ROOMS[i])==0)
				same=1;
			if (same)
			printf("This name is already given to another room, please give a different name!");
		}
		while (same);
	}
	for (i=0; i<ROOM; i++)
	{
		for (j=0; j<MONTH; j++)
		{
			do
			{
				printf("Please give the cash collexion for the %dst month for room: %s \n",j+1,ROOMS[i]);
				scanf("%f",&CASH[i][j]);
				if (CASH[i][j]<0)
				printf ("You can't give negative amount! ");
			}while (CASH[i][j]<0);
		SUMEISPR[i]+=CASH[i][j];
		
		}
		MOEISPR[i]=SUMEISPR[i]/MONTH;         
	}
	printf("The average cash collexion for every room is:\n --------------------------------------------------\n");
	for(i=0; i<ROOM; i++)
	{
	
		printf("%s %.2f \n",ROOMS[i],MOEISPR[i]);
	}
	min=MOEISPR[0];
	for (i=0; i<ROOM; i++)
	{
		if(min>MOEISPR[i])
		min=MOEISPR[i];
	}
	printf("The minimum average cash collexion is: %.2f euros and belongs to room: \n",min);
	for (i=0; i<ROOM; i++)
	{
		if(MOEISPR[i]==min)
		printf("%s\t",ROOMS[i]);
	}
	system("PAUSE");
	return 0;
}
