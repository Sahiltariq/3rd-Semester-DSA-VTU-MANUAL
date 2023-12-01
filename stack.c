#include <stdio.h>
#include <stdlib.h>
int s[5],top=-1;

void push()
{
    if(top==4)
        printf("\nStack overflow!!!!");
    else
    {
        printf("\nEnter element to insert:");
        scanf("%d",&s[++top]);
    }
}

void pop()
{
    if(top==-1)
        printf("\nStack underflow!!!");
    else
        printf("\nElement popped is: %d",s[top--]);
}
void disp()
{
    int t=top;
    if(t==-1)
        printf("\nStack empty!!");
    else
        printf("\nStack elements are:\n");
    while(t>=0)
        printf("%d ",s[t--]);
}
void pali()
{
    int num[5],rev[5],i,t;
    for(i=0,t=top;t>=0;i++,t--)
        num[i]=rev[t]=s[t];
    for(i=0;i<=top;i++)
        if(num[i]!=rev[i])
        break;
    /*printf(" num     rev\n");
    for(t=0;t<=top;t++)
      printf("%4d   %4d\n",num[t],rev[t]);*///remove /* */ to display num and rev
    if(i==top+1)
        printf("\nIt is a palindrome");
    else
        printf("\nIt is not a palindrome");
}

int main()
{
    int ch;
    do
    {
        printf("\n...Stack operations.....\n");
        printf("1.PUSH\n");
        printf("2.POP\n");
        printf("3.Palindrome\n");
        printf("4.Display\n");
        printf("5.Exit\n________________\n");
        printf("Enter choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:push();break;
            case 2:pop();break;
            case 3:pali();break;
            case 4:disp();break;
            case 5:exit(0);
            default:printf("\nInvalid choice");
        }
    }
    while(1);
    return 0;

}
// 
// #include<stdio.h>
// #include<stdlib.h>
// #define MAX 10
// int s[10],top=-1;
// int underflow()
// {
//     if(top==-1)
//     return 1;
//     return 0;
// }
// int overflow()
// {
//     if(top==MAX-1)
//     return 1;
//     return 0;
// }
// void push()
// {
//     if(overflow())
//     {
//         printf("stack id full\n");
//     }
//     else
//     {
//         printf("enter the element to be inseerted\n");
//         scanf("%d",&s[++top]);
//     }
// }
// void pop()
// {
//     if(underflow())
//     {
//         printf("stackk id empty\n");
//     }
//     else{
//         printf("enter the element to be deleted");
//         printf("deleted element is %d",s[top--]);
//     }
// }
// void display()
// {
//     int t=top;
//     if(top==-1)
//     printf("stack is empty");
//     printf("stack elemets are:\n");
//     for(int i=0;i<=t;i++)
//     printf("%d\t",s[i]);
// }
// int main()
// {
//     int ch;
//     while(ch)
//     {
//         printf("---MENU\n");
//         printf("1.push\n");
//         printf("2.pop\n");
//         printf("3.display\n");
//         printf("4.exit\n");
//         printf("enter your choice");
//         scanf("%d",&ch);
//         switch(ch)
//         {
//             case 1: push();
//             break;
//             case 2: pop();
//             break;
//             case 3:display();
//             break;
//             case 4: exit(0);
//             default:printf("invalid choice");
//         } 
//     }
//     return 0;
// // }