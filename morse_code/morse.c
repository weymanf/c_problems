//Weyman Fung
//morse.c

#include <stdio.h>
#include <ctype.h>
#define DONE 0
#define READ 1
#define WRITE 2

void get_choice(int * choice);
void read();
void write();
const char * codes[26] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

int main()
{
	int choice;
	do
	{
		get_choice(&choice);
		if (choice == READ)
			read(); 
		else
		  if ( choice == WRITE)
			write();	
	} //while loop to check choice
	while ( choice != DONE);
	return 0;
}  //main


void get_choice(int *choice)
{
	int ch;
	do 
	{
		printf("Morse menu \n0. Done.\n1. Read Morse Code.\n2. Write Morse code.\n\nYour choice: ");
		scanf("%d", &ch); 
		if (ch > 2 || ch < 0)
			printf("That is not between 0 and 2.\nPlease try again.\n\n");
	} //checking range
	while ( ch > 2 || ch < 0);
	*choice = ch;
	return;
} //function get_choice

void write()
{
	char ENG; int upE, i;
	printf("English message: ");
	scanf("%c", &ENG); 
	do 
	{	
		scanf("%c", &ENG);
		if (ENG == '\n')
			break;
		if (isalpha(ENG))
		{		
			upE = toupper(ENG) - 65;
			for( i = 0; i < 10; i++)
			{
				if (codes[upE][i] == '\0')
					break;
				printf("%c", codes[upE][i]); 
			} // check till sentinel
			printf(" ");
		}  //check for alpha
		else 
			if (ENG == ' ') 
				printf("  ");
				else
					printf("?");
	} //scan till end of line
		while (ENG != '\n');
	printf("\n");
	return;	
}  //write function

void read()
{
	int g, x, j, y, p, o; //variables for various counters
	char temp, letter; 
	char ar_inputs[5];  //array for inputs
	o = 0;   //variable to check spaces
	printf("Morse code: ");
	scanf("%c", &temp);
	
	do 
	{	
		g = 0;
		for (p = 0; p <= 5; p++)
			ar_inputs[p] = '\0';	
		do
		{	
				scanf("%c", &temp);
				if (temp == ' ')
				{	
					o++;
					break;
				} // counter of spaces
			
				else 
				{
				ar_inputs[g] = temp;
				g++; 
				o = 0;
				}  // building input array
		}  //do while loop to build ar_inputs array
			while ( temp != '\n');
		
		y = 0;

		if ( o == 2)	
			printf(" ");   
		
		if ( o != 2) 
		{
		for ( x = 0; x < 26; x++)
		{
			for (j = 0; j <= g; j++)
			{
					if  ( ar_inputs[j-1] != '.' && ar_inputs[j-1] != '_' )
						{
							letter = '?';
						} //makes letter = ? for unknown characters	
				if ((codes[x][j] == '\0') && (ar_inputs[j] != '.' && ar_inputs [j] != '-'))
				{
					letter = x + 'A';
					y = 1;
					break;
				}  //checks to see if code = ar_inputs
				else
				  if (codes[x][j] != ar_inputs[j])
					break;
					else 
						letter = '?';
			}  //for loop to check codes
			if (y == 1)
				break;
		}  // loop to check codes and ar_inputs
		printf("%c", letter);
		} //if statement to print out letters
	} //Do this till end of line
		while ( temp != '\n');
	printf("\n");
		return; 
}	// read function
