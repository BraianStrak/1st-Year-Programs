
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
int main(void)
{
	char snailNames[8][50];
	int snailNo;																					//Initialising Vars
	int leg1Times[8], leg2Times[8], leg3Times[8], leg4Times[8];
	int fastestLeg1, fastestLeg2, fastestLeg3, fastestLeg4;
	int fastestSnail1, fastestSnail2, fastestSnail3, fastestSnail4;
	int totalTime[8];
	int timeS, timeM;
	int bestSnailTime, bestSnailName;
	int n = 0; //name counter
	int i = 0; //input counter
	int j = 0; //addition counter
/*--------------------------------------------------------------------------------------------*/
	printf("Input the amount of snails (max 8)\n");													//Inputting Snail Amount 
	scanf("%d", &snailNo);

	printf("Please enter each snail's name in order\n");											//asking for snail names 
	for (n = 0; n <= snailNo - 1; n++)
	{
		scanf("%s", &snailNames[n]);
	}
/*--------------------------------------------------------------------------------------------*/
	for (i = 0; i <= snailNo-1; i++)																	//Inputting leg times per snail
	{
		printf("Input the 4 leg times for each snail in order, in seconds\n");
		scanf("%d", &leg1Times[i]);
		scanf("%d", &leg2Times[i]);
		scanf("%d", &leg3Times[i]);
		scanf("%d", &leg4Times[i]);

		if (i == 0)																						//base values for fastest leg times
		{
			fastestLeg1 = leg1Times[i];
			fastestLeg2 = leg2Times[i];
			fastestLeg3 = leg3Times[i];
			fastestLeg4 = leg4Times[i];
			fastestSnail1 = i;
			fastestSnail2 = i;
			fastestSnail3 = i;
			fastestSnail4 = i;
		}
			else																							//checks for faster leg times 
			{ 
				if (leg1Times[i] < fastestLeg1)
				{
					fastestLeg1 = leg1Times[i];
					fastestSnail1 = i;
				}

				if (leg2Times[i] < fastestLeg2)
				{
					fastestLeg2 = leg2Times[i];
					fastestSnail2 = i;
				}

				if (leg3Times[i] < fastestLeg3)
				{
					fastestLeg3 = leg3Times[i];
					fastestSnail3 = i;
				}

				if (leg4Times[i] < fastestLeg4)
				{
					fastestLeg4 = leg4Times[i];
					fastestSnail4 = i;
				}
			}
	} //end of loop which inputs legs, does base fastest times and checks for faster times
/*--------------------------------------------------------------------------------------------*/
	printf("\n");																							//outputs fastest leg times
	printf("fastest leg 1 snail was %s with a time of %d\n", snailNames[fastestSnail1], fastestLeg1);
	printf("fastest leg 2 snail was %s with a time of %d\n", snailNames[fastestSnail2], fastestLeg2);
	printf("fastest leg 3 snail was %s with a time of %d\n", snailNames[fastestSnail3], fastestLeg3);
	printf("fastest leg 4 snail was %s with a time of %d\n", snailNames[fastestSnail4], fastestLeg4);

/*--------------------------------------------------------------------------------------------*/

	for (j = 0; j <= snailNo - 1; j++)															//adds leg times to create total time for snails
	{
		totalTime[j] = leg1Times[j] + leg2Times[j] + leg3Times[j] + leg4Times[j];
		timeM = totalTime[j] / 60;
		timeS = totalTime[j] % 60; 

		if ((timeM == 1) && (timeS == 0))															//outputs snail times, ensuring grammar is correct
			printf("%s took 1 minute\n", snailNames[j]);
		else if ((timeM > 1) && (timeS == 0))
			printf("%s took %d minutes\n", snailNames[j], timeM);
		else if ((timeM == 0) && (timeS == 1))
			printf("%s took 1 second\n", snailNames[j]);
		else if ((timeM == 0) && (timeS > 1))
			printf("%s took %d seconds\n", snailNames[j], timeS);
		else if ((timeM == 1) && (timeS == 1))
			printf("%s took 1 minute and 1 second\n", snailNames[j]);
		else if ((timeM > 1) && (timeS == 1))
			printf("%s took %d minutes and 1 second\n", snailNames[j], timeM);
		else if ((timeM == 1) && (timeS > 1))
			printf("%s took 1 minute and %d seconds\n", snailNames[j], timeS);
		else
			printf("%s took %d minutes and %d seconds\n", snailNames[j], timeM, timeS);
		
		
		if (j == 0)																				//base fastest time
		{
			bestSnailTime = totalTime[j];
			bestSnailName = j;
		}
		else																					//checks for faster times
			if (totalTime[j] < bestSnailTime)
			{
				bestSnailTime = totalTime[j];
				bestSnailName = j;
			}
				
	}
		
/*--------------------------------------------------------------------------------------------*/
	timeM = bestSnailTime / 60;																	//calc mins+secs for fastest snail
	timeS = bestSnailTime % 60;
	
	if ((timeM == 1) && (timeS == 0))															//outputs fastest snail, ensuring grammar is correct
		printf("The fastest snail was %s with a time of 1 minute", snailNames[bestSnailName]);
	else if ((timeM > 1) && (timeS == 0))
		printf("The fastest snail was %s with a time of %d minutes", snailNames[bestSnailName], timeM);
	else if ((timeM == 0) && (timeS == 1))
		printf("The fastest snail was %s with a time of 1 second", snailNames[bestSnailName]);
	else if ((timeM == 0) && (timeS > 1))
		printf("The fastest snail was %s with a time of %d seconds", snailNames[bestSnailName], timeS);
	else if ((timeM == 1) && (timeS == 1))
		printf("The fastest snail was %s with a time of 1 minute and 1 second", snailNames[bestSnailName]);
	else if ((timeM > 1) && (timeS == 1))
		printf("The fastest snail was %s with a time of %d minutes and 1 second", snailNames[bestSnailName], timeM);
	else if ((timeM == 1) && (timeS > 1))
		printf("The fastest snail was %s with a time of 1 minute and %d seconds", snailNames[bestSnailName], timeS);
	else
		printf("The fastest snail was %s with a time of %d minutes and %d seconds", snailNames[bestSnailName], timeM, timeS);
/*--------------------------------------------------------------------------------------------*/
	return 0;
}
