#include <stdio.h>
#include<stdlib.h>
void insert_at_beg();
void insert_at_end();
void insert_after_element();
void delete();
void display();

struct node
{
    int data; 
    struct node* left;
    struct node* right;
};
struct node* root;
int main()
{
    root=NULL;
    int choice;
    while(1)
    {
        printf("\n1.Insert at Beginning\n2.Insert At End\n3.Insert Afer Element\n4.Delete\n5.Display\n6.Exit\n");
        printf("Enter Your Choice :");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                insert_at_beg();
            break;
            case 2:
                insert_at_end();
            break;
            case 3:
                insert_after_element();
            break;
            case 4:
                delete();
            break;
            case 5:
                display();
            break;
            case 6:
                printf("Thank You");
                exit(0);
            break;
            default:
                printf("Enter Correct choice");
        }
        
    }
    return 0;
}
void insert_at_end()
{
    struct node* temp;
    int n;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter the number : ");
    scanf("%d",&n);
    temp->data=n;
    temp->right=NULL;
    temp->left=NULL;
    if(root==NULL)
    {
        root=temp;
    }
    else
    {
        struct node* p;
        p=root;
        while(p->right!=NULL)
        {
            p=p->right;
        }
        p->right=temp;
        temp->left=p;
    }
}
void insert_at_beg()
{
    struct node* temp;
    int n;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter the number : ");
    scanf("%d",&n);
    temp->data=n;
    temp->right=NULL;
    temp->left=NULL;
    if(root==NULL)
    {
        root=temp;
    }
    else
    {
        temp->right=root;
        root->left=temp;
        root=temp;
    }
}
void insert_after_element()
{
    struct node *temp;
    int n,x;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter the number : ");
    scanf("%d",&n);
    temp->data=n;
    temp->right=NULL;
    temp->left=NULL;
    if(root==NULL)
    {
        root=temp;
    }
    else
    {
        struct node* p;
        p=root;
        printf("Enter the number after which you want to insert : ");
        scanf("%d",&x);
        while(p->data!=x)
        {
            p=p->right;
        }
        temp->right=p->right;
        temp->left=p;
        p->right=temp;
        temp->right->left=temp;
        
    }
}
void display()
{
    if(root==NULL)
    {
        printf("The Linked List Is Empty");
    }
    else if(root->right==NULL)
    {
        printf("The Data in Linked List Are : ");
        printf("%d",root->data);
    }
    else
    {
        printf("The Data in Linked List Are : ");
        struct node* p;
        p=root;
        while(p!=NULL)
        {
            printf("%d ",p->data);
            p=p->right;
        } 
    }
    
}
void delete()
{
    struct node *p,*temp;
    int n;
    printf("\nEnter The Element To Be Deleted :");
    scanf("%d",&n);
    p=root;
    while(p->data!=n)
    {
        temp=p;
        p=p->right;
    }
    if(p->data==n)
    {
        if(root==p)
        {
            if(root->right!=NULL)
            {
                root->left=NULL;
                root=root->right;
            }
            else
            {
                root=NULL;
            }
                
        }
        else if(p->right==NULL)
        {
            temp->right=NULL;
        }
        else
        {
            p->right->left=p->left;
            p->left->right=p->right;
            p->left=NULL;
            p->right=NULL;
        }
        
    }
    else
    {
        printf("Element Not Found");   
    }
}
