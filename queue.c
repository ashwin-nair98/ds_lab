#include <stdio.h>

int que[10];
int rear=-1;

int isEmpty()
{
	if (rear<0)
		return 1;
	else
		return 0;
}

int isFull()
{
	if(rear>=9)
		return 1;
	else
		return 0;

}
void add(int data)
{
	if(!isFull())
	{
		if(isEmpty())
			que[++rear] = data;
		else
			que[++rear] = data;
	}	
	else
	printf("Error. Stack Full");
}

void delete()
{
	if(!isEmpty())
	{
		printf("%d is deleted from queue.\n", que[0]);
		for (int i = 0; i < rear; ++i)
			que[i] = que[i+1];
		rear--;
	}
	else
	printf("Queue is empty!");
}

void display()
{	int i;
	if(!isEmpty())
	{
		for(i=0;i<=rear;i++)
			printf("%d\t", que[i]);
		printf("\n");
	}
}

int main()
{
	int ch, data;
	do{
	printf("1.Add\n2.Delete\n3.Display\n4.Exit\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:	printf("Enter element: ");
				scanf("%d", &data);
				add(data);
				break;
		case 2:	delete();
				break;
		case 3:	display();
				break;
		case 4:	printf("Exiting..\n");
				break;
		default:printf("Invalid option");
				break;
	}
	}while(ch!=4);
	return 0;
}