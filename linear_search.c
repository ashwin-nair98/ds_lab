#include<stdio.h>

int main()
{
	int arr[10], i, fl=0, s, n;
	printf("Enter n: ");
	scanf("%d", &n);
	printf("Enter array: ");
	for(i=0;i<n;i++)
		scanf("%d", &arr[i]);
	printf("Enter search element: ");
	scanf("%d", &s);
	for(i=0;i<n;i++)
		if(arr[i]==s)
			fl=1;
	if(fl)
		printf("Element found\n");
	else
		printf("Element not found\n");
	return 0;
}