#include<stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

struct node *head;
struct node *temp;


void push(int data)
{
	struct node *link = (struct node*) malloc(sizeof(struct node));
	link->data = data;
	link->next = head->next;
	head->next = link;
}

void pop()
{
	if(head->next)
	{
		printf("%d popped.\n",head->next->data);
		head->next = head->next->next;
	}
	else
		printf("Error, stack empty.\n");
}

void display()
{
	temp = head->next;
	while(temp)
	{
		printf("Data: %d\n", temp->data);
		temp = temp->next;
	}
}

int main(int argc, char const *argv[])
{
	head = (struct node*) malloc(sizeof(struct node));
	head->next = NULL;
	int ch, data;
	do{
		printf("1.Push\n2.Pop\n3.Display\n4.Exit\nEnter choice: ");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:	printf("Enter data to be pushed: ");
					scanf("%d", &data);
					push(data);
					break;
			case 2:	pop();
					break;
			case 3:	display();
					break;
			case 4:	printf("Exiting..\n");
					break;
			default:printf("Invalid choice\n");
		}
	}while(ch!=4);
	return 0;
}