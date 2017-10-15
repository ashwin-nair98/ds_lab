#include<stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

struct node *head;

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
		printf("1.Add to front\n2.Display all\n3.Exit");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:	printf("Enter data: ");
					scanf("%d", &dat);
					insertFirst(dat);
					break;
			case 2:	display();
					break;
			case 3:	printf("Exiting..\n");
					break;
			default:printf("Error,try again..\n");
					break;
		}
	}while(ch!=3);
	return 0;
}