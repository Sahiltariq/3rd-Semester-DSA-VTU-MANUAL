#include<stdio.h>
#include<stdlib.h>
void create();
void display();
void search();
void create_secondll();
void concat();
void insert_front();

struct node
{
int info;
struct node *next;
};
struct node *start=NULL,*second=NULL,*last=NULL,*temp;
int main()
{
int choice;
    while(1)
    {
printf("-----MENU-----\n");
printf("1.Create\n");
printf("2.Display\n");
printf("3.Insert front\n");
printf("4.Search\n");
printf("5.Create second ll\n");
printf("6.Concat\n");
printf("7.exit\n");
printf("Enter your choice\n");
scanf("%d",&choice);
        switch(choice)
        {
            case 1 :create();
            break;
            case 2 :display();
            break;
            case 3 :insert_front();
            break;
            case 4 :search();
            break;
            case 5 :create_secondll();
            break;
            case 6 :concat();
            break;
            
            case 7:exit(0);
default:printf("Invalid choice\n");
        }
    }
    return 0;
}
void create()
{
struct node*newnode;
newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
printf("Out of memory\n");
        exit(0);
    }
printf("Enter the value for the new node\n");
scanf("%d",&newnode->info);
    if(start==NULL)
    {
        temp=start=newnode;
    }
    else
    {
        temp->next=newnode;
        temp=newnode;
        temp->next=NULL;
    }
}
void create_secondll()
{
struct node*newnode;
newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
printf("Out of memory\n");
        exit(0);
    }
printf("Enter the value for the new node\n");
scanf("%d",&newnode->info);
    if(second==NULL)
    {
        temp=second=newnode;
    }
    else
    {
        temp->next=newnode;
        temp=newnode;
        temp->next=NULL;
    }
}
void display()
{
struct node*ptr;
    if(start==NULL)
    {
printf("List is empty\n");
        return;
    }
    else
    {
ptr=start;
printf("The elements are\n");
        while(ptr!=NULL)
        {
printf("%d\t",ptr->info);
ptr=ptr->next;
    }
    }
}
void search()
{
struct node *p;
int key,count=0;
printf("Enter the key\n");
scanf("%d",&key);
printf("Key is %d\n",key);
    if(start==NULL)
    {
printf("No data\n");
    }
    else
    {
        p=start;
        while(p!=NULL)
        {
printf("%d\t",p->info);
            if(key==p->info)
            {
                count++;
                break;
            }
            else
                p=p->next;
        }
        if(count==1)
        {
printf("\nKey found\n");
        }
        else
        {
printf("\nKey not found\n");
        }
    }
}
void concat()
{
struct node *p=start;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=second;
}
void insert_front()
{
struct node *newnode;
newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
printf("Out of memory\n");
        exit(0);
    }
printf("Enter the value for the new node\n");
scanf("%d",&newnode->info);
newnode->next=start;
    start=newnode;
}