#include<stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

struct node *head;
struct node *temp;

void insertLast(int data) {
  struct node *link = (struct node*) malloc(sizeof(struct node));
  temp = head;
  while(temp->next!=NULL) temp = temp->next;
  link->data = data;
  link->next = NULL;
  temp->next = link;
}


void number_of_node()
{
	int count = 0;
	temp = head;
	while(temp->next!=NULL) {
		temp = temp->next;
		count ++;
	}
	printf("No of nodes: %d\n", count);
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
	int ch, dat;
	do{
		printf("1.Add node\n2.Number of nodes\n3.Display all\n4.Exit\nEnter your choice: ");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:	printf("Enter data: ");
					scanf("%d", &dat);
					insertLast(dat);
					break;
			case 2:	number_of_node();
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