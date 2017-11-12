#include<stdio.h>
#include <stdlib.h>


struct node
{
	int e;
	int c;
	struct node *link;
}*pol1,*pol2,*f,*pol1header=NULL,*pol2header=NULL,*temp1,*temp2,*f1,*pol3,*pol3header=NULL,*temp3,*f3,*pol4,*pol4header=NULL,*temp4;

int main()
{   int pow,po,i,fl=0,op,ch=1,co;
	pol1=pol1header;
	pol2=pol2header;

	printf("Enter first polynomial\n");

	do
	{
		f=(struct node *)malloc(sizeof(struct node));
		printf("Enter power: ");
		scanf("%d",&po);
		printf("Enter coeff of power %d: ", po );
		scanf("%d",&co);
		f->e = po;
		f->c = co;
		if(pol1==NULL)
		{	f->link=NULL;
			pol1header=f;
			pol1=pol1header;

		}
		else if(pol1header->link==NULL)
		{
			f->link=NULL;
			pol1=f;
			pol1header->link=pol1;

		}
		else
		{	pol1->link=f;
			f->link=NULL;
			pol1=f;
		}
		printf("Do you want to continue?(1/0): ");
		scanf("%d",&op);
		if (op==0)
		{
			ch=0;
		}
	}while(ch==1);
	printf("Enter second polynomial\n");
	ch=1;
	do
	{
		f=(struct node *)malloc(sizeof(struct node));
		printf("Enter power: ");
		scanf("%d",&po);
		printf("Enter coeff of power %d: ", po );
		scanf("%d",&co);
		f->e = po;
		f->c = co;
		if(pol2==NULL)
		{	f->link=NULL;
			pol2header=f;
			pol2=pol2header;

		}
		else if(pol2header->link==NULL)
		{
			f->link=NULL;
			pol2=f;
			pol2header->link=pol2;

		}
		else
		{	pol2->link=f;
			f->link=NULL;
			pol2=f;
		}
		printf("Do you want to continue?(1/0): ");
		scanf("%d",&op);
		if(op==0)
		{
			ch=0;
		}
	}while(ch==1);
	temp1=pol1header;
	printf("Polynomial 1: \t");
	while(temp1!=NULL)
	{
		printf("%dx^%d",temp1->c,temp1->e );
		temp1=temp1->link;
		if(temp1) printf("+");
	}
	temp2=pol2header;
	printf("\nPolynomial 2: \t");
	while(temp2!=NULL)
	{
		printf("%dx^%d",temp2->c,temp2->e );
		temp2=temp2->link;
		if(temp2) printf("+");
	}

	temp1=pol1header;
	temp2=pol2header;
	pol3=pol3header;
	printf("\vAddition result \n");
	while(temp1!=NULL&&temp2!=NULL)
	{
			f3=(struct node *)malloc(sizeof(struct node));
		if(temp2->e > temp1->e)
		{
			if(pol3==NULL)
			{
				f3->e=temp2->e;
				f3->c=temp2->c;
				f3->link=NULL;
				pol3header=f3;
				pol3=pol3header;
			}
			else if(pol3header->link==NULL)
			{
				f3->e=temp2->e;
				f3->c=temp2->c;
				f3->link=NULL;
				pol3=f3;
				pol3header->link=pol3;
			}
			else
			{
				f3->e=temp2->e;
				f3->c=temp2->c;
				f3->link=NULL;
				pol3->link=f3;
				pol3=f3;
			}
			temp2=temp2->link;
		}
		else if(temp2->e < temp1->e)
		{
			if(pol3==NULL)
			{
				f3->e=temp1->e;
				f3->c=temp1->c;
				f3->link=NULL;
				pol3header=f3;
				pol3=pol3header;
			}
			else if(pol3header->link==NULL)
			{
				f3->e=temp1->e;
				f3->c=temp1->c;
				f3->link=NULL;
				pol3=f3;
				pol3header->link=pol3;
			}
			else
			{
				f3->e=temp1->e;
				f3->c=temp1->c;
				f3->link=NULL;
				pol3->link=f3;
				pol3=f3;
			}
		    temp1=temp1->link;
		}
		else
		{
			if(pol3==NULL)
			{
				f3->e=temp1->e;
				f3->c=temp1->c+temp2->c;
				f3->link=NULL;
				pol3header=f3;
				pol3=pol3header;
			}
			else if(pol3header->link==NULL)
			{
				f3->e=temp1->e;
				f3->c=temp1->c+temp2->c;
				f3->link=NULL;
				pol3=f3;
				pol3header->link=pol3;
			}
			else
			{
				f3->e=temp1->e;
				f3->c=temp1->c+temp2->c;
				f3->link=NULL;
				pol3->link=f3;
				pol3=f3;
			}
		temp1=temp1->link;
		temp2=temp2->link;
	}
		}
	temp3=pol3header;
	while(temp3!=NULL)
	{
		printf("%dx^%d",temp3->c,temp3->e );
		temp3=temp3->link;
		if(temp3) printf("+");
	}

	printf("\v Multiplication result\n");
	temp1=pol1header;
	pol4=pol4header;
	while(temp1!=NULL)
	{
		temp2=pol2header;
		while(temp2!=NULL)
		{
			f3=(struct node *)malloc(sizeof(struct node));

			if(pol4==NULL)
			{
				f3->e=temp1->e+temp2->e;
				f3->c=temp1->c*temp2->c;
				f3->link=NULL;
				pol4header=f3;
				pol4=pol4header;
			}
			else if(pol4header->link==NULL)
			{
				f3->e=temp1->e+temp2->e;
				f3->c=temp1->c*temp2->c;
				f3->link=NULL;
				pol4=f3;
				pol4header->link=pol4;
			}
			else
			{
				f3->e=temp1->e+temp2->e;
				f3->c=temp1->c*temp2->c;
				temp3=pol4header;
				while(temp3!=NULL)
				{
					if(f3->e==temp3->e)
					{
						fl=1;
						break;
					}temp4=temp3;
					temp3=temp3->link;
				}
				if(fl==0)
				{
					f3->link=NULL;
					temp4->link=f3;
					temp4=f3;
				}
				else if(fl==1)
				{
					temp3->c+=f3->c;
					fl=0;
				}
			}
			temp2=temp2->link;
		}
		temp1=temp1->link;
	}
	temp3=pol4header;
	while(temp3!=NULL)
	{
		printf("%dx^%d",temp3->c,temp3->e );
		temp3=temp3->link;
		if(temp3) printf("+");
	}
	printf("\n");
}
