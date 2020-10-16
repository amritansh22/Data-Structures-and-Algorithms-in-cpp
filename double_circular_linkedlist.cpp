#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
    struct node *prv;
};

void create(struct node **h)
{
    int n,i;
    printf("How many elements you want to enter: ");
    scanf("%d",&n);
    struct node *ptr=NULL;
    for(i=0;i<n;i++)
    {
        struct node *cur=(struct node *)malloc(sizeof(struct node));
        cur->data=rand()%10;
        cur->next=NULL;
        cur->prv=NULL;

        if(*h==NULL)
        {
            *h=cur;
            cur->next=cur->prv=cur;
            ptr=cur;
        }
        else 
        {
            cur->prv=ptr;
            ptr->next=cur;
            cur->next=*h;
            ptr=cur;
        }
    }

} 

void display(struct node *h)
{   
    struct node *cur;
    printf("linked list:\t");
  for(cur=h;cur->next!=h;cur=cur->next)
  {
      printf("%d\t",cur->data);
  }
  printf("%d",cur->data);
}

void insert(struct node **h,int x,int p)
{
    struct node *cur;
    struct node *ptr;
    cur=(struct node *)malloc(sizeof(struct node));
    cur->data=x;
    cur->next=cur->prv=NULL;
    
    if(*h==NULL)
    {
        *h=cur;
        cur->next=cur->prv=cur;
    }
    else if(p==0)
    {
       cur->next=*h;
       cur->prv=(*h)->prv;
       (*h)->prv->next=cur;
       (*h)->prv=cur;
       *h=cur;
    }
    else
    {
        ptr=*h;
        int i=1;
        while(i<p && ptr->next!=*h)
        {
            ptr=ptr->next;
            i++;
        }
        cur->next=ptr->next;
        cur->prv=ptr;
        ptr->next->prv=cur;
        ptr->next=cur;
    }

}

void del(struct node **h,int p)
{
    struct node *ptr;
    struct node *cur;
    if(*h==NULL)
    {
        printf("EMPTY");
    }
    else if(p==0)
    {
        for(ptr=*h;ptr->next!=*h;ptr=ptr->next){}

        ptr->next=(*h)->next;
        cur=*h;
        *h=(*h)->next;
        (*h)->next->prv=ptr;
        free(cur);   
    }
    else
    {
        ptr=*h;
        int i=1;
        while(i<p && ptr->next!=*h)
        {
            cur=ptr;
            ptr=ptr->next;
            i++;
        }
        cur->next=ptr->next;
        ptr->next->prv=cur;
        free(ptr);
    }
}

int main()
{
    struct node *head=NULL;
    create(&head);
    display(head);
    insert(&head,2,6);
    display(head);
    printf("\n");
    del(&head,0);
    display(head);
    return 0;
}