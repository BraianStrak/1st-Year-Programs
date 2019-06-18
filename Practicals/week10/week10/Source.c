#include <stdio.h>

int main(void)
{
	char userInput;
	int recordCount = 0, i = 0;
	char fileNames[300][100];
	char string[1000];
	char State = 'A'; 
	int a = 0;
	struct AccessRecord
	{
		int customerID;
		char domain[255];
		char timestamp[20];
	};

	struct AccessRecord log[150];
	

	while (1) /* forever*/
	{
		i = 0;
		/* Print the main menu*/
		printf("\na) ask user for values then print\nb) add new record to local list\nc) display all records\nd) load record\ne) write to file\nf) look up user\nq) Quit\n\n>");

		/* Grab the option from the user */
		scanf(" %c", &userInput);

		if (userInput == 'a')
		{
			/*does question 1*/
			printf("Please enter the customer ID, the domain and then the timestamp\n"); /*asks user for values*/
			scanf("%d", &log[0].customerID);
			scanf("%s", &log[0].domain);
			scanf("%s", &log[0].timestamp);

			printf("%s: User %d visited %s\n", log[0].timestamp, log[0].customerID, log[0].domain); /*prints given values*/
			
		}

		if (userInput == 'b')
		{
			printf("Please enter the customer ID, the domain and the timestamp\n"); /*asks user for information and adds it to the array*/
			scanf("%d", &log[recordCount].customerID);
			scanf("%s", &log[recordCount].domain);
			scanf("%s", &log[recordCount].timestamp);
			recordCount++;
		}

		if (userInput == 'c') /*prints all things currectly in the struct*/
		{
			i = 0;
			for (i = 0; i <= recordCount-1; i++)
			{
				printf("%s: User %d visited %s\n", log[i].timestamp, log[i].customerID, log[i].domain);
			}
			
		}

		if (userInput == 'd')
		{
			/*loads the record from a file*/

			FILE* exampleText;
			exampleText = fopen("C:/Users/Braian/source/repos/Practicals/week10/example_data.txt", "r");
			
			

			while (!feof(exampleText)) /*until end of the file*/
			{
				fscanf(exampleText, "%99[^|^\n] |s", string); /*excluding the pipe character and newline, copy data into the string variable*/

				switch (State)
				{
				case 'A': {log[a].customerID = atoi(string); State = 'B'; break; } 
				case 'B': {strcpy(log[a].domain, string); State = 'C'; break; }
				case 'C': {strcpy(log[a].timestamp, string); a++; recordCount++; State = 'A'; break; }
				}

			}
			printf("record count is %d", recordCount);
		}

		if (userInput == 'e')
		{
			FILE* exampleText; /*opens file for appending*/
			exampleText = fopen("C:/Users/Braian/source/repos/Practicals/week10/example_data.txt", "a"); 

			char stringToAdd[500];

			printf("Please enter the string to add to the file, in the correct syntax (ID|domain|timestamp)\n"); /*takes info to add to file*/
			scanf("%s", stringToAdd);

			char *textPtr = {stringToAdd};

			if (exampleText != NULL)
			{
				fputs(textPtr,exampleText); /*adds the string to the end of the file*/
				fclose(exampleText);
			}


		}

		if (userInput == 'f')
		{
			int searchUser = 0;
			
			printf("Please enter the User ID you would like to look up\n");
			scanf("%d", &searchUser); 

		
			
			i = 0;
			for (i = 0; i <= recordCount - 1; i++) /*filters results by user*/
			{
				if (log[i].customerID == searchUser)
				{
					printf("%s: User %d visited %s\n", log[i].timestamp, log[i].customerID, log[i].domain);
				}
			}

			
		}

		if (userInput == 'q') /*quits the loop and thus the program*/
		{
			break;
		}


	}

	return 0;

}




