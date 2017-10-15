#include <stdio.h>
#include <string.h>

int hashIndex(int key)
{
	return (key%29);
}


int main(int argc, char const *argv[])
{
	int i, j, n, k, ch, spaceFlagL, spaceFlagQ, inp[100], hashTableL[30], hashTableQ[30], index, counterL=1, counterQ=1;	//L for linear and Q for quadratic
	//Input
	printf("Enter no. of elements: ");
	scanf("%d", &n);
	printf("Enter elements: ");
	for (i = 0; i < n; i++)
		scanf("%d", &inp[i]);

	//HashTable prep
	for(i=0;i<30;i++)
	{	hashTableL[i]=0;
		hashTableQ[i]=0;
	}

	//Spaceflag prep
	if(n>=30) 
	{
		spaceFlagL = 0;
		spaceFlagQ = 0;
		printf("Error n > size of table.");
	}
	else
	{
		spaceFlagL = 1;
		spaceFlagQ = 1;
	}

	//Linear hasing
	for(i=0;i<n && spaceFlagL;i++)
	{
		index = hashIndex(inp[i]);
		while(hashTableL[index])
		{
			index = (index + 1)%30;
		}
		hashTableL[index] = inp[i];
		spaceFlagL = 0;
		for(j=0;j<30;j++)
			if(!hashTableL[j])
				spaceFlagL = 1;
		
	}

	//Quadratic hashing
	for(i=0;i<n;i++)
	{
		int k = hashIndex(inp[i]), h = 1;
		index = k;
		while(hashTableQ[index])
		{
			index = (k + (h*h))%30;
			h++;
		}
		hashTableQ[index] = inp[i];
		spaceFlagQ = 0;
		for(j=0;j<30;j++)
			if(!hashTableQ[j])
				spaceFlagQ = 1;
	}


	//Printing
	printf("Linear Hashing: \nIndex\t\tValue\n");
	for (i = 0; i < 29; ++i)
		printf("%d\t\t%d\n",i,hashTableL[i]);
	printf("Quadratic Hashing:\nIndex\t\tValue\n");
	for(i=0;i<29;i++)
		printf("%d\t\t%d\n",i,hashTableQ[i]);

	//Comparison

	printf("Choose an element for comparison: \n");
	for(i=0;i<n;i++)
		printf("%d. %d\n", i+1, inp[i]);
	scanf("%d", &ch);
	ch--;
	i=hashIndex(inp[ch]);
	while(hashTableL[i]!=inp[ch])
	{	i = (i+1)%29;
		counterL++;
	}
	i=hashIndex(inp[ch]);
	j=1;
	while(hashTableQ[i]!=inp[ch])
	{
		i = (i + (j*j))%29;
		counterQ++;
		j++;
	}
	printf("Linear Hashing found element after %d comparisons.\nQuadratic hashing found element after %d comparisons\n", counterL, counterQ);
	return 0;
}