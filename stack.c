#include<stdio.h>

int MAXSIZE = 8; 
int stack[8]; 
int top = -1; 

int isempty() {
	if(top == -1)
		return 1;
	else
		return 0;
}

int isfull() {
	if(top == MAXSIZE)
		return 1;
	else
		return 0;
}


int pop() {
	int data;

	if(!isempty()) {
		data = stack[top];
		top = top - 1; 
		return data;
	} 
	else {
		printf("Could not retrieve data, Stack is empty.\n");
	}
	return 0;
}

void push(int data) {
	if(!isfull()) {
		top = top + 1; 
		stack[top] = data;
	} 
	else 
		printf("Could not insert data, Stack is full.\n");
}

void display()
{	int i = 0;
	if(!isempty()){
		for (int i = top; i >=0; i--)
			printf("%d\t", stack[i]);
		printf("\n");
	}
	else
		printf("Stack empty\n");
}

int main()
{
	int ch, element;
	do{
	printf("1.Push \n2.Pop \n3.Display \n4.Exit\n");
	scanf("%d", &ch);
	switch(ch)
	{
		case 1:	printf("Enter the element: ");
				scanf("%d", &element);
				push(element);
				break;
		case 2:	printf("%d popped.", pop());
				break;
		case 3:	display();
				break;
		case 4:	printf("Exiting..\n");
				break;
	}
	}while(ch!=4);
	return 0;
}
