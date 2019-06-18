 #include <stdio.h>
char GradeFromPercentage(float percentage);
char GradeFromRawMarks(float marksAwarded, float marksAvailable);
char GradeFromTotalRawMarks(float marksAwarded[], float marksAvailable[], int maxAssignments);
int CaseCheck(char a, char b);
void DisplayAllRawMarks(float marksAwarded[], float marksAvailable[], int maxAssignments);
void EditAssignment(float marksAwarded[], float marksAvailable[], int position);
void AddAssignment(float marksAwarded[], float marksAvailable[], int *max);
void RemoveAssignment(float marksAwarded[], float marksAvailable[], int position, int max);

int main()
{
	char userInput = '?'; /* some place to store input from the user*/
	int max = 0;          /* the maximum assignment count (i.e. how many assignements we have*/
	float marksAwarded[100];     /* place to store the marks*/
	float marksAvailable[100]; /* place to store the available marks*/
	int position; /* stores position of assignment to be edited*/

	/* Since we've not got any code to add new assignments yet,
	 here's some test assignments manually assigned. */

	/* Testing code: default assignment scores */
	{
		marksAwarded[0] = 10; marksAvailable[0] = 10;
		marksAwarded[1] = 7;  marksAvailable[1] = 11;
		marksAwarded[2] = 5;  marksAvailable[2] = 11;
		marksAwarded[3] = 3;  marksAvailable[3] = 11;
		marksAwarded[4] = 0;  marksAvailable[4] = 100;
		max = 5; /* update how many items we have*/
	}
	/* End of testing code */

	while (1) /* forever*/
	{
		/* Print the main menu*/
		printf("\nA) Display Marks\nB) Edit Assignment\nC) Add Assignment\nD) Remove Assignment\nQ) Quit\n\n>");

		/* Grab the option from the user */
		scanf(" %c", &userInput);

		if (CaseCheck(userInput, 'A'))
		{
			/* Display all the marks we have*/
			DisplayAllRawMarks(marksAwarded, marksAvailable, max);
		}

		if (CaseCheck(userInput, 'B'))
		{
			/* asks for assignment and edits it */
			printf("Please enter the number of the assignment you wish to edit\n");
			scanf("%d", &position);
			EditAssignment(marksAwarded, marksAvailable, position);
		}

		if (CaseCheck(userInput, 'C'))
		{
			/* adds assignment */
			AddAssignment(marksAwarded, marksAvailable, &max);
		}

		if (CaseCheck(userInput, 'D'))
		{
			/* removes assignment */
			printf("Please enter the number of the assignment you wish to remove\n");
			scanf("%d", &position);
			RemoveAssignment(marksAwarded, marksAvailable, position-1, max);
			max = max - 1; /*changes amount of assignments*/
		}

		if (CaseCheck(userInput, 'Q'))
		{
			/* If 'Q' or 'q' entered, break out of the while loop */
			break;
		}

		/* Keep going around the while loop if the user didn't quit */
	}

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
	} else {
		return 0;
	}
} 

void DisplayAllRawMarks(float marksAwarded[], float marksAvailable[], int maxAssignments)
{
	int i = 0;

	for (i = 0; i <= maxAssignments-1; i++) /*for all assignments*/
	{
		printf("%d: %1f/%1f   -> %c\n", i + 1, marksAwarded[i], marksAvailable[i], GradeFromRawMarks(marksAwarded[i], marksAvailable[i], maxAssignments)); /*print marks as a fraction followed by grade achieved*/
	}
	printf("Final Grade: %c\n", GradeFromTotalRawMarks(marksAwarded, marksAvailable, maxAssignments)); /*prints final grade*/
	return 0;
}
	
void EditAssignment(float marksAwarded[], float marksAvailable[], int position)
{
	float newMarkAwarded = 0, newMarkAvailable = 0;
	printf("Please enter the new total mark followed by the mark achieved\n"); /*user inputs fresh marks they wish to be edited into the position*/
	scanf("%f", &newMarkAvailable);
	scanf("%f", &newMarkAwarded);
	marksAvailable[position - 1] = newMarkAvailable; /*new marks get put in*/
	marksAwarded[position - 1] = newMarkAwarded;
}

void AddAssignment(float marksAwarded[], float marksAvailable[], int *max)
{
	*max = *max + 1; /*creates new space in table by incrementing the max pointer*/
	EditAssignment(marksAwarded, marksAvailable, *max);
}

void RemoveAssignment(float marksAwarded[], float marksAvailable[], int position, int max)
{
	int i = 0; /*initialises i for the loop*/
	for (i = position; i <= max; i++)
	{
		marksAwarded[i] = marksAwarded[i+1]; /*moves all spaces up by one*/
		marksAvailable[i] = marksAvailable[i+1];
	}
	
}