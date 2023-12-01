#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *lchild;
    int data;
    struct node *rchild;
};
typedef struct node *NODE;
NODE root = NULL;
NODE create_node()
{
    NODE ptr;
    ptr = (NODE)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("Insufficient memory\n");
        exit(0);
    }
    else
    {
        printf("Enter data:: ");
        scanf("%d", &ptr->data);
        ptr->lchild = ptr->rchild = NULL;
    } /* end of else*/
    return ptr;
} /* end of create_node function*/
NODE create_bst(NODE root)
{
    NODE ptr, temp, p;
    ptr = create_node();
    if (root == NULL)
    {
        root = ptr;
        return root;
    } /* end of if*/
    p = NULL;
    temp = root;
    while (temp != NULL)
    {
        p = temp;
        if (ptr->data == temp->data)
        {
            printf("Duplicate items are not allowed\n\n");
            free(ptr);
            return root;
        } /* end of if*/
        if (ptr->data < temp->data)
            temp = temp->lchild;
        else
            temp = temp->rchild;
    }

    if (ptr->data < p->data)
    {
        p->lchild = ptr;
    }
    else
        p->rchild = ptr;
    return root;
}
void inorder(NODE t)
{
    if (t != NULL)
    {
        inorder(t->lchild);
        printf("%d\t", t->data);
        inorder(t->rchild);
    } /* end of if*/
} /* end of inorder*/
void preorder(NODE t)
{
    if (t != NULL)
    {
        printf("%d\t", t->data);
        preorder(t->lchild);
        preorder(t->rchild);
    } /* end of if*/
} /* end of preorder*/
void postorder(NODE t)
{
    if (t != NULL)
    {
        postorder(t->lchild);
        postorder(t->rchild);
        printf("%d\t", t->data);
    } /* end of if*/
} /* end of postorder*/
void traverse(NODE root)
{
    if (root == NULL)
        printf("Empty tree\n\n");
    else
    {
        printf("\n\nPreorder traversal:\t");
        preorder(root);
        printf("\n\nInorder traversal:\t");
        inorder(root);
        printf("\n\nPostorder traversal:\t");
        postorder(root);
    } /* end of else*/
} /* end of traversal function*/
void main()
{
    int ch, n, i;
    for (;;)
    {
        printf("\n\nOPERATIONS ON BST\n\n");
        printf("\n\n1:CREATE BST \n2:TRAVERSE BST\n3:EXIT\n\n");
        printf("Enter your choice::");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter number of elements in BST::");
            scanf("%d", &n);
            for (i = 0; i < n; i++)
                root = create_bst(root);
            break;
        case 2:
            traverse(root);
            break;
        default:
            exit(0);
        } /* end of switch*/
    }     /* end of for*/
} /* end of main*/