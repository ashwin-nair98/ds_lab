#include<stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

struct node *head;
struct node *temp;

void insertAtEnd(int data)
{
	struct node *link = (struct node*) malloc(sizeof(struct node));
	temp = head;
	while(temp->next!=head) temp = temp->next;
	link->data = data;
	link->next = head;
	temp->next = link;
}


void delete(int data)
{
	temp = head;
	while(temp->next!=head) 
	{	if(temp->next->data == data)
		{
			temp->next = temp->next->next;
			break;
		}
		temp = temp->next;
	}
}

void display()
{
	temp = head;
	while(temp->next!=head)
	{	printf("Data: %d\n", temp->next->data);
		temp = temp->next;
	}
}

int main()
{
	head = (struct node*) malloc(sizeof(struct node));
	head->next = head;
	int ch, dat;
	do{
		printf("1.Add\n2.Delete\n3.Display\n4.Exit\nEnter your choice: ");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:	printf("Enter data: ");
					scanf("%d", &dat);
					insertAtEnd(dat);
					break;
			case 2:	printf("Enter data to delete: ");
					scanf("%d", &dat);
					delete(dat);
					break;
			case 3:	display();
					break;
			case 4:	printf("Exiting..\n");
					break;
			default:printf("Invalid choice!\n");
		}
	}while(ch!=4);
	return 0;
}