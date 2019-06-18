 #include <stdio.h>
char GradeFromPercentage(float percentage);
char GradeFromRawMarks(float marksAwarded, float marksAvailable);
char GradeFromTotalRawMarks(float marksAwarded[], float marksAvailable[], int maxAssignments);
int CaseCheck(char a, char b);

int main(void)
{
	float marksAwarded[100];
	float marksAvailable[100];
	int i = 0;
	int total = 0;
	char stop;
	int result;

	for (i = 0; i <= 99; i++) /*Asks user for grades until user prompts to stop*/
	{
		total++;

		printf("Enter marks awarded followed by total available\n"); /*promts user to enter marks*/
		scanf("%f", &marksAwarded[i]);
		scanf("%f", &marksAvailable[i]);

		printf("Type y to exit and n to continue\n"); /*asks user if they wish to continue*/
		scanf(" %c", &stop);
		if ((stop == 'y') || (CaseCheck(stop, 'Y') == 1)) /*checks case and if it works*/
			break;
		else
			continue;
	}

	printf("grade achieved is %c", GradeFromTotalRawMarks(marksAwarded, marksAvailable, total));
	return 0;
}

char GradeFromPercentage(float percentage) //Gets grade from a percentage
{
	
	char grade = 'L'; //initialises grade

	if (percentage >= 90.0) //decides on grade based on the percentage
		grade = 'A';
	else
		if ((percentage < 90.0) && (percentage >= 70.0))
			grade = 'B';
		else
			if ((percentage < 70.0) && (percentage >= 50.0))
				grade = 'C';
			else
				if ((percentage < 50.0) && (percentage >= 30.0))
					grade = 'D';
				else
					if (percentage < 30.0)
						grade = 'F';

	return grade;
}

char GradeFromRawMarks(float marksAwarded, float marksAvailable) 
{
	float percentage; 
	percentage = (marksAwarded / marksAvailable) * 100; /*converts marks into a percentage*/
	return GradeFromPercentage(percentage); /*gets grade from calculated percentage*/
}

char GradeFromTotalRawMarks(float marksAwarded[], float marksAvailable[], int maxAssignments) 
{
	int i = 0;
	float totalAvailable = 0, totalAwarded = 0; 

	for (i = 0; i <= maxAssignments - 1; i++)  /*calculates total marks*/
	{
		totalAvailable += marksAvailable[i]; 
		totalAwarded += marksAwarded[i];
	}
	return GradeFromRawMarks(totalAwarded, totalAvailable); /*returns grade from total marks*/

}

int CaseCheck(char a, char b) 
{
	if ((a >= 65) && (a <= 122)) /*if a is a letter*/
	{
		if (a <= 90) { /*if a is uppercase*/
			a += 32; /*change a to lowercase*/
		}
	}


	if ((b >= 65) && (b <= 122)) /*if b is a letter*/
	{
		if (b <= 90) { /*if b is uppercase*/
			b += 32; /*change b to lowercase*/
		}
	}


	if (a == b) { /*outputs 1 if grades are the same*/
		return 1;
	}
	else {
		return 0;
	}
} 
	


