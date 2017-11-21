#include<stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *prev;
  struct node *next;
};

struct node *head;
struct node *temp;

void insertFirst(int data) {
  struct node *link = (struct node*) malloc(sizeof(struct node));
  link->data = data;
  link->next = head->next;
  link->prev = head;
  head->next = link;
}

void insertAtPos(int data, int pos)
{
	struct node *link = (struct node*) malloc(sizeof(struct node));
	int i;
	link->data = data;
	temp = head->next;
	for(i=0;i<pos-1;i++)
		temp=temp->next;
	link->next = temp->next;
	link->prev = temp;
	temp->next = link;
	temp->next->prev = link;
}

void insertAtEnd(int data)
{
	struct node *link = (struct node*) malloc(sizeof(struct node));
	temp = head;
	while(temp->next!=NULL) temp = temp->next;
	link->data = data;
	link->prev = temp;
	link->next = NULL;
	temp->next = link;
}

void delete(int data)
{
	struct node *temp = (struct node*) malloc(sizeof(struct node));
	temp = head;
	while(temp->next!=NULL)
	{	if(temp->next->data == data)
		{	temp->next->prev = temp;
      temp->next = temp->next->next;	
			break;
		}
		temp = temp->next;
	}
}

void display()
{
	temp = head->next;
	while(temp!=NULL)
	{	printf("Data: %d\n",temp->data);
		temp = temp->next;
	}
}


int main()
{
	head = (struct node*) malloc(sizeof(struct node));
	head->next = NULL;
	head->prev = NULL;
	int ch, dat, pos;
	do{
		printf("1.Add node at front\n2.Add node at position\n3.Add node at end\n4.Delete node\n5.Display\n6.Exit\nEnter choice: ");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:	printf("Enter data: ");
					scanf("%d", &dat);
					insertFirst(dat);
					break;
			case 2:	printf("Enter data: ");
					scanf("%d", &dat);
					printf("Enter position: ");
					scanf("%d", &pos);
					insertAtPos(dat, pos);
					break;
			case 3:	printf("Enter data: ");
					scanf("%d", &dat);
					insertAtEnd(dat);
					break;
			case 4:	printf("Enter data in node to delete: ");
					scanf("%d", &dat);
					delete(dat);
					break;
			case 5:	display();
					break;
			case 6:	printf("Exiting..\n");
					break;
			default:printf("Invalid choice!\n");
					break;
		}
	}while(ch!=6);
}
