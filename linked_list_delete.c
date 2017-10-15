#include<stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

struct node *head;


void delete(int data)
{
	struct node *temp = (struct node*) malloc(sizeof(struct node));
	temp = head;
	while(temp->next!=NULL)
	{	if(temp->next->data == data)
		{	temp->next = temp->next->next;
			break;
		}
		temp = temp->next;
	}
}

void insertFirst(int data) {
  struct node *link = (struct node*) malloc(sizeof(struct node));
  link->data = data;
  link->next = head->next;
  head->next = link;
}

void display()
{
	struct node *temp = head->next;
	while(temp!=NULL)	
	{	printf("Data: %d\n",temp->data);
		temp = temp->next;
	}
}


int main()
{
	head = (struct node*) malloc(sizeof(struct node));
	head->next = NULL;
	int ch, dat;
	do{
		printf("1.Add to front\n2.Display all\n3.Delete element\n4.Exit");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:	printf("Enter data: ");
					scanf("%d", &dat);
					insertFirst(dat);
					break;
			case 2:	display();
					break;
			case 3:	printf("Enter element to delete: ");
					scanf("%d", &dat);
					delete(dat);
					break;
			case 4:	printf("Exiting..\n");
					break;
			default:printf("Error,try again..\n");
					break;
		}
	}while(ch!=4);
	return 0;
}