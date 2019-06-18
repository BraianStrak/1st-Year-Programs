#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
int main(void)
{
	int snailNo;																					//Initialising Vars
	int leg1Times[8], leg2Times[8], leg3Times[8], leg4Times[8];
	int fastestLeg1, fastestLeg2, fastestLeg3, fastestLeg4;
	int fastestSnail1, fastestSnail2, fastestSnail3, fastestSnail4;
	int totalTime[8];
	int timeS, timeM;
	int bestSnailTime, bestSnailName;
	int i = 0; //input counter
	int j = 0; //addition counter
/*--------------------------------------------------------------------------------------------*/
	printf("Input the amount of snails (max 8)\n");													//Inputting Snail Amount 
	scanf("%d", &snailNo);
	/*--------------------------------------------------------------------------------------------*/
	for (i = 0; i <= snailNo - 1; i++)																	//Inputting leg times per snail
	{
		printf("Input the 4 leg times for each snail in seconds\n");
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
			fastestSnail1 = i + 1;
			fastestSnail2 = i + 1;
			fastestSnail3 = i + 1;
			fastestSnail4 = i + 1;
		}
		else																							//checks for faster leg times 
		{
			if (leg1Times[i] < fastestLeg1)
			{
				fastestLeg1 = leg1Times[i];
				fastestSnail1 = i + 1;
			}

			if (leg2Times[i] < fastestLeg2)
			{
				fastestLeg2 = leg2Times[i];
				fastestSnail2 = i + 1;
			}

			if (leg3Times[i] < fastestLeg3)
			{
				fastestLeg3 = leg3Times[i];
				fastestSnail3 = i + 1;
			}

			if (leg4Times[i] < fastestLeg4)
			{
				fastestLeg4 = leg4Times[i];
				fastestSnail4 = i + 1;
			}
		}
	} //end of loop which inputs legs, does base fastest times and checks for faster times
/*--------------------------------------------------------------------------------------------*/
	printf("\n");																							//outputs fastest leg times
	printf("fastest leg 1 snail was snail %d with a time of %d\n", fastestSnail1, fastestLeg1);
	printf("fastest leg 2 snail was snail %d with a time of %d\n", fastestSnail2, fastestLeg2);
	printf("fastest leg 3 snail was snail %d with a time of %d\n", fastestSnail3, fastestLeg3);
	printf("fastest leg 4 snail was snail %d with a time of %d\n", fastestSnail4, fastestLeg4);

	/*--------------------------------------------------------------------------------------------*/

	for (j = 0; j <= snailNo - 1; j++)															//adds leg times to create total time for snails
	{
		totalTime[j] = leg1Times[j] + leg2Times[j] + leg3Times[j] + leg4Times[j];
		timeM = totalTime[j] / 60;
		timeS = totalTime[j] % 60;

		if ((timeM == 1) && (timeS == 0))															//outputs snail times, ensuring grammar is correct
			printf("snail %d took 1 minute\n", j + 1);
		else if ((timeM > 1) && (timeS == 0))
			printf("snail %d took %d minutes\n", j + 1, timeM);
		else if ((timeM == 0) && (timeS == 1))
			printf("snail %d took 1 second\n", j + 1);
		else if ((timeM == 0) && (timeS > 1))
			printf("snail %d took %d seconds\n", j + 1, timeS);
		else if ((timeM == 1) && (timeS == 1))
			printf("snail %d took 1 minute and 1 second\n", j + 1);
		else if ((timeM > 1) && (timeS == 1))
			printf("snail %d took %d minutes and 1 second\n", j + 1, timeM);
		else if ((timeM == 1) && (timeS > 1))
			printf("snail %d took 1 minute and %d seconds\n", j + 1, timeS);
		else
			printf("snail %d took %d minutes and %d seconds\n", j + 1, timeM, timeS);


		if (j == 0)																				//base fastest time
		{
			bestSnailTime = totalTime[j];
			bestSnailName = j + 1;
		}
		else																					//checks for faster times
			if (totalTime[j] < bestSnailTime)
			{
				bestSnailTime = totalTime[j];
				bestSnailName = j + 1;
			}

	}

	/*--------------------------------------------------------------------------------------------*/
	timeM = bestSnailTime / 60;																	//calc mins+secs for fastest snail
	timeS = bestSnailTime % 60;

	if ((timeM == 1) && (timeS == 0))															//outputs fastest snail, ensuring grammar is correct
		printf("The fastest snail was snail %d with a time of 1 minute", bestSnailName);
	else if ((timeM > 1) && (timeS == 0))
		printf("The fastest snail was snail %d with a time of %d minutes", bestSnailName, timeM);
	else if ((timeM == 0) && (timeS == 1))
		printf("The fastest snail was snail %d with a time of 1 second", bestSnailName);
	else if ((timeM == 0) && (timeS > 1))
		printf("The fastest snail was snail %d with a time of %d seconds", bestSnailName, timeS);
	else if ((timeM == 1) && (timeS == 1))
		printf("The fastest snail was snail %d with a time of 1 minute and 1 second", bestSnailName);
	else if ((timeM > 1) && (timeS == 1))
		printf("The fastest snail was snail %d with a time of %d minutes and 1 second", bestSnailName, timeM);
	else if ((timeM == 1) && (timeS > 1))
		printf("The fastest snail was snail %d with a time of 1 minute and %d seconds", bestSnailName, timeS);
	else
		printf("The fastest snail was snail %d with a time of %d minutes and %d seconds", bestSnailName, timeM, timeS);
	/*--------------------------------------------------------------------------------------------*/
	return 0;
}