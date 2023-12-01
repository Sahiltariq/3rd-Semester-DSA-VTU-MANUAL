#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int s[10],top=-1;
int underflow()
{
    if(top==-1)
    return 1;
    return 0;
}
int overflow()
{
    if(top==MAX-1)
    return 1;
    return 0;
}
void push()
{
    if(overflow())
    printf("stack is full\n");
    else{
        printf("enter the element to be inserted\n");
        scanf("%d",&s[++top]);

    }
}
void pop()
{
    if(underflow())
    printf("stack underflow\n");
    else{
        printf("enter the element to be poped");
        printf("\n the poped element id %d",s[top--]);
    }
}
void display()
{
    int t=top;
    if(t==-1)
    {
        printf("stack is empty\n");
    }
    else
    {
        printf("stack elements are \n");
        for( int i=0;i<=t;i++)
        printf("%d\t",s[i]);
    }

}
int main()
{
    int ch;
    while(ch)
    {
        printf("---menu ---\n");
        printf("1.push\n");
        printf("2.pop\n");
        printf("3.display\n");
        printf("4.exit\n");
        printf("enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:push();
            break;
            case 2:pop();
            break;
            case 3:display();
            break;
            case 4:exit(0);
            default:printf("invalid choice");
         
         }
            }
            return 0;
}