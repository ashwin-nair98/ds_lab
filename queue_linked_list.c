#include<stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

struct node *head;

void add(int data)
{
	struct node *temp = (struct node *) malloc (sizeof(struct node));
	struct node *link = (struct node *) malloc (sizeof(struct node));
	link->next = NULL;
	link->data = data;
	temp = head;
	while(temp->next)
		temp = temp->next;
	temp->next = link;
}

void delete()
{
	if(head->next)
	{printf("%d popped.\n", head->next->data);
		head->next = head->next->next;
	}
	else
		printf("Queue empty.\n");
}

void display()
{
	struct node *temp = (struct node *) malloc (sizeof(struct node));
	temp = head->next;
	while(temp)
	{
		printf("Data: %d \n", temp->data);
		temp = temp->next;
	} 
}

int main(int argc, char const *argv[])
{
	head = (struct node*) malloc(sizeof(struct node));
	head->next = NULL;
	int ch, data;
	do{
		printf("1.Add\n2.Delete\n3.Display\n4.Exit\nEnter choice: ");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:	printf("Enter data: ");
					scanf("%d", &data);
					add(data);
					break;
			case 2:	delete();
					break;
			case 3:	display();
					break;
			case 4:	printf("Exiting..\n");
					break;
			default:printf("Invalid choice..\n");	
		}
	}while(ch!=4);
	return 0;
}