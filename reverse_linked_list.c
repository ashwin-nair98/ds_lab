#include<stdio.h>
#include<stdlib.h>
 
struct Node
{
    int data;
    struct Node* next;
};
 

void reverse(struct Node** head)
{
    struct Node* prev   = NULL;
    struct Node* current = *head;
    struct Node* next;
    while (current != NULL)
    {
        next  = current->next;  
        current->next = prev;   
        prev = current;
        current = next;
    }
    *head = prev;
}
 
void push(struct Node** head, int new_data)
{
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data  = new_data;
    new_node->next = (*head);    
    (*head)    = new_node;
}
 
void display(struct Node *head)
{
    struct Node *temp = head;
    while(temp != NULL)
    {
        printf("%d  ", temp->data);    
        temp = temp->next;  
    }
    printf("\n");
}    
 
int main()
{
    
    struct Node* head = NULL;
    int ch, dat;
    do{
        printf("1.Add new element\n2.Display\n3.Reverse\n4.Exit\n");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: printf("Enter data: ");
                    scanf("%d", &dat);
                    push(&head, dat);
                    break;
            case 2: display(head);
                    break;
            case 3: reverse(&head);
                    printf("The list is reversed: \n");
                    display(head);
                    break;
            case 4: printf("Exiting..\n");
                    break;
            default:printf("Invalid choice!");
        }
    }   while(ch!=4);   
    return 0;
}