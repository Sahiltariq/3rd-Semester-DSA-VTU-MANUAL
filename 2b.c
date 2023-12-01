#include<stdio.h>
#include<math.h>
void tower(int n,int source,int temp,int destenation)
{
    if(n==0)
    return;
    tower(n-1,source,temp,destenation);
    printf("\n move disc %d from %c to %c",n,source,destenation);
    tower(n-1,temp ,source,destenation);

}
void main()
{
    int n;
    printf("enter number of discs");
    scanf("%d",&n);
    printf("the sequence of moves involved in tower of honoi are");
    tower(n,'A','B','C');
    printf("\n total moves are :%d\n",(int)pow(2,n)-1 );
}