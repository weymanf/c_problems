//Weyman Fung
//sort.c

#include <stdio.h>

int binary_search(int ar[], int size, int key);
int *insertion_sort(int ar[], int x);

int main()
{
	FILE *inFile = fopen("data.txt", "r");
	int nums, i, input;
	int ar[20];
	int * vr;
	i = 0;
	
	while (!feof(inFile)) 
	{
		fscanf(inFile, "%d", &nums);
		if(feof(inFile))
			break;
		ar[i] = nums;
		i++;
	} //read array from file
	
	vr = insertion_sort(ar, i);
	do 
	{
	printf("Please enter a value (-1 = done) > ");
	scanf("%d", &input);
	if (input == -1 )
		break;
	if( binary_search(vr, i, input) == -1)
		printf("%d is not in the array.\n\n", input);
	else
	printf("%d is located at positon %d in the array.\n\n", input, binary_search(vr, i, input));
	}  //do while loop to ask user for input
	while ( input != (-1) );
	

	fclose(inFile);
	return 0;
} //main

int *insertion_sort(int ar[], int x)
{
	int i, j, b, temp;
	for (i = 1; i <= (x - 1); i++)
	{	
		temp = ar[i];
		for ((j = (i - 1)); j >= 0 && ar[j] > temp; j--)
			ar[j+1] = ar[j];
		ar[j] = temp;
	} //insertion sort loop
	printf("\n");
	return ar;
} //insertion function


int binary_search(int ar[], int size, int key)
{
	int low, high, mid; 
	low = 0; high = size - 1;
	while (low <= high) 
	{
		mid = (low + high)/ 2; 
		if (ar[mid] < key)
			low = mid + 1;
			else
		 	  if ( ar [mid] > key )	
				high = mid - 1;
				else
					return mid;
	} // loop for search
	return -1;									
} //binary search function
 
