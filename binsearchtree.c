#include<stdio.h>
#include<stdlib.h>

struct node
{
  int d;
  struct node *llink;
  struct node *rlink;
};

struct node *pa[2],*ptr,*root=NULL,*temp,*p1,*p2;
int i,j,k;

void insuc(struct node* p2)
{
pa[1]=p2;
if(p2->llink==NULL)
   return ;
pa[0]=p2;
insuc(p2->llink);
}
void ins(int m)
{
  int k;
   struct node*p,*t;
  if(root==NULL)
  {
    printf("\n enter the value of root node ");
    scanf("%d",&k);
    root=(struct node *)malloc(sizeof(struct node));
    if(root==NULL)
       return;
    root->d=k;
    root->llink=root->rlink=NULL;
  }
  p=root;
  temp=(struct node *)malloc(sizeof(struct node));
  if(temp==NULL)
       return;
  temp->llink=temp->rlink=NULL;
  temp->d=m;

  while(p!=NULL)
  {
    t=p;
    if(m>(p->d))
       p=p->rlink;
    else if(m<(p->d))
       p=p->llink;
    else
       {
         free(temp);
         return;
       }
  }
  if(t->llink==NULL && (t->d)>m)
     t->llink=temp;
  else if(t->rlink==NULL && (t->d)<m)
     t->rlink=temp;
 }
 void create()
 {
   int n,m;
   printf("\nEnter the value of root node: ");
   scanf("%d",&m);
   root=(struct node *)malloc(sizeof(struct node));
   if(root==NULL)
      return;
   root->d=m;
   root->llink=root->rlink=NULL;
   printf("\nEnter the no of elements: ");
   scanf("%d",&n);
   printf("\nEnter the elements: ");
   for(i=0;i<n;++i)
   {
      scanf("%d",&m);
      ins(m);
   }
 }
 void del()
 {

   int k;
    struct node*p,*t;
   p=root;
   if(root==NULL)
   {
     printf("\n empty tree ");
     return;
   }
   t=NULL;
   printf("\n enter the element to be deleted");
   scanf("%d",&k);
   while(p!=NULL)
   {
     if(k>(p->d))
     {
          t=p;
          p=p->rlink;
      }
     else if(k<(p->d))
      {
           t=p;
           p=p->llink;
      }
     else
         break;

   }

   if(p==NULL)
   {
      printf("\n not found");
      return;
   }
   else if(p->llink==NULL && p->rlink==NULL)
   {
      if(p==root)
       {
         free(root);
         root=NULL;
         return;
       }
      if(k>(t->d))
          t->rlink=NULL;
      else if(k<(t->d))
          t->llink=NULL;

      free(p);
   }
   else if(p->llink==NULL)
   {
      if(p==root)
      {
        temp=root;
        root=p->rlink;

        free(temp);
        return;
      }
      else
      {
         if(t->rlink==p)
            t->rlink=p->rlink;
         else
            t->llink=p->rlink;

         free(p);
      }
    }
    else if(p->rlink==NULL)
   {
      if(p==root)
      {
        temp=root;
        root=p->llink;
        free(temp);
        return;
      }
      else
      {
         if(t->rlink==p)
            t->rlink=p->llink;
         else
            t->llink=p->llink;

         free(p);
      }
   }
   else
   {  if(p->rlink->llink==NULL)
       {
         p->d=p->rlink->d;
         p1=p->rlink;
         p->rlink=p->rlink->rlink;
         free(p1);
       }
      else
      {
        insuc(p->rlink);
        p->d=pa[1]->d;
        pa[0]->llink=pa[1]->rlink;
        free(pa[1]);
      }
  }
}
void trav(struct node *pr)
{
  if(pr==NULL)
    return;
  trav(pr->llink);
  printf("%d ",pr->d);
  trav(pr->rlink);
}

int main()
{
  int ch,m;
  struct node*p;
  do
  {
    printf("1.Create\n2.Insert\n3.Delete\n4.Traversal(inorder)\n5.Exit\nEnter your choice: ");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:create();
              break;
      case 2:printf("\n enter the value of node ");
             scanf("%d",&m);
             ins(m);
             break;
      case 3:del();
              break;
      case 4:p=root;
             if(p==NULL)
               printf("\n empty tree");
             trav(p);
             break;
      case 5:break;
    }
  }while(ch!=5);
  return 0;
}
