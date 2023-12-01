#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node*lchild;
    int data;
    struct node*rchild;

};
typedef struct node *NODE;
NODE root=NULL;
NODE createnode(int a[],int i){
    NODE ptr;
    ptr=(NODE)malloc(sizeof(struct node));
    if(ptr==NULL){
        printf("out of memory\n");
        exit(0);
    }
    else
    {
        ptr->data=a[i];
        ptr->lchild=ptr->rchild=NULL;
    }
    return ptr;
}
NODE insertlevelorder(NODE root ,int a[],int i,int n)
{
    NODE ptr=NULL;
    if(i<n){
        ptr=createnode(a,i);
        ptr->lchild=insertlevelorder(ptr->lchild,a,2*i+1,n);
        ptr->rchild=insertlevelorder(ptr->rchild,a,2*i+2,n);
    }
    return ptr;
}
void inorder(NODE t)
{
    if(t!=NULL)
    {
        inorder(t->lchild);
        printf("%d\t",t->data);
        inorder(t->rchild);
    }
}
int main(){
    int a[20],i,n;
    printf("enter the no elements IN BINARY tree\n");
    scanf("%d",&n);
    printf("enter the elements in array form\n");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    root=insertlevelorder(root,a,0,n);
    printf("constructed binaray tree \n");
    inorder(root);
}