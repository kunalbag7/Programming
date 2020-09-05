#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};

int main()
{
  int n,k;
  scanf("%d %d",&n,&k );

  struct node *head,*ptr,*prev;
  head=(struct node *)malloc(sizeof(struct node));
  head->data=1;
  head->next=NULL;
  prev=head;
  for(int i=2;i<=n;i++)
  {
    ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=i;
    ptr->next=NULL;
    prev->next=ptr;
    prev=ptr;
    ptr=NULL;
  }
  prev->next=head;
  ptr=head;
  for (int i = 1; i < n; i++) {
    for(int j=1; j<k; j++)
    {
      ptr=ptr->next;
      while(ptr->data==0)
        ptr=ptr->next;
    }
    ptr->data=0;
    while(ptr->data==0)
      ptr=ptr->next;
  }
  ptr=head;
  while(ptr->data==0)
    ptr=ptr->next;
  printf("The Safe position is:- %d",ptr->data);
}
