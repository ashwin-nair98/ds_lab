#include <stdio.h>
#include<string.h>
//Simple hashing program.

int hashIndex(char key) 					//Calculates index
{
	int index = (key%19)+1;
	return index;
}
int main()
{
	int i,j, spaceFlag, index;
	char hashTable[20], inp[100];
	printf("Enter the string to hash: ");
	scanf("%s", inp);
	for(i=0;i<20;i++)
		hashTable[i] = 0;
	
	if(strlen(inp)>19)
		spaceFlag = 0;
	else
		spaceFlag = 1;
	for(i=0;i<strlen(inp) && spaceFlag;i++)
	{
		index = hashIndex(inp[i]);
		while(hashTable[index])
			index=(index+1)%19; 			//Linear probing
		hashTable[index] = inp[i];
		spaceFlag =0; 						//spaceFlag is used to find out if the hashTable is full/if the input string is larger.
		for(j=0;j<20;j++)
			if(!hashTable[j])
			{	spaceFlag = 1;
				break;
			}
	}
	if(!spaceFlag)
		printf("Error! Input string larger than hashTable size.\n");
	else
	{	printf("Index\t\tValue\n");
		for(i=0;i<20;i++)
			printf("%c\t\t%d\n",hashTable[i],i );
	}	
	return 0;
}