// Online C compiler to run C program online
#include<stdio.h>  
#include<stdlib.h> 
void insert(int);
void delete(int);
int max_bst();
int min_bst();
struct node  
{  
    int data;  
    struct node *left;   
    struct node *right;   
};  
struct node *root; 
void main ()  
{  
    int choice,item,x;
    root=NULL;
    while(1)
    {
        printf("\n1. INSERT\n");
        printf("2. DELETE\n");
        printf("3. DISPLAY\n");
        printf("4. Find Maximum Element in BST\n");
        printf("5. Find Minimum Element in BST\n");
        printf("6. EXIT\n");
        printf("ENTER THE CHOICE :");
        scanf("%d",&choice);
        if(choice==1)
        {
            printf("Enter The Element To Be Inserted :");
            scanf("%d",&item);
            insert(item);
        }
        else if(choice==2)
        {
            printf("Enter The Element To Be Deleted :");
            scanf("%d",&item);
            delete(item);
        }
        else if(choice==3)
        {
            printf("1. Inorder\n");
            printf("2. Preorder\n");
            printf("3. Postorder\n");
            printf("ENTER THE CHOICE :");
            scanf("%d",&x);
            if(x==1)
            {
                inorder(root);
            }
            else if(x==2)
            {
                preorder(root);
            }
            else if(x==3)
            {
                postorder(root);
            }
            else
            {
                printf("Invalid Entry");
            }
        }
        else if(choice==4)
        {
            printf("The Maximum element in BST is :%d",max_bst());
        }
        else if(choice==5)
        {
            printf("The Minimum element in BST is :%d",min_bst());
        }
        else if(choice==6)
        {
            exit(0);
        }
        else
        {
            printf("Invalid Choice");
        }
    }
}  


void insert(int item)  
{  
    struct node *temp, *parent , *run;  
    temp = (struct node *) malloc(sizeof (struct node));  
    temp -> data = item;  
    temp -> left = NULL;  
    temp -> right = NULL;   
    if(root == NULL)  
    {  
        root = temp;
    }  
    else   
    {  
        parent = NULL;  
        run = root;   
        while(run != NULL)  
        {  
            parent = run;   
            if(item < run->data)  
            {  
                run = run -> left;   
            }   
            else   
            {  
                run = run -> right;  
            }  
        }  
        if(item < parent -> data)  
        {  
            parent -> left = temp;   
        }  
        else   
        {  
            parent -> right = temp;   
        }  
    }  
}  

int max_bst()
{
    struct node *run,*parent;
    run=root;
    while(run!=NULL)
    {
        parent=run;
        run=run->right;
    }
    return parent->data;
}
int min_bst()
{
    struct node *run,*parent;
    run=root;
    while(run!=NULL)
    {
        parent=run;
        run=run->left;
    }
    return parent->data;
}
void delete(int item)
{
    struct node *run,*parent,*x;
    int val;
    
    run=root;
    while(run->data!=item)
    {
        parent=run;
        if(run->data<item)
        {
            run=run->right;
        }
        else
        {
            run=run->left;
        }
    }
    if(run->left==NULL && run->right==NULL)
    {
        if(run==root)
        {
            root=NULL;
        }
        else
        {
            if(parent->left==run)
            {
                parent->left=NULL;
                printf("Element Deleted");
            }
            else
            {
                parent->right=NULL;
                printf("Element Deleted");
            }
            free(run);
        }
    }
    else if(run->left!=NULL && run->right!=NULL)
    {
        x=run->right;
        while(x->left!=NULL)
        {
           x=x->left;
        }
        val = x->data;
        delete(x->data);
        run->data=val;
    }
    else
    {
        if(run!=root)
        {
            if(run==parent->left)
            {
                parent->left=run->left;
                printf("Element Deleted");
            }
            else
            {
                parent->right=run->right;
                printf("Element Deleted");
            }
        }
        free(run);
    }
}
void inorder(struct node *run)
{
    if (run != NULL) 
    {
        inorder(run->left);
        printf("%d  ", run->data);
        inorder(run->right);
    }
}
void preorder(struct node *run)
{
    if (run != NULL) 
    {
        printf("%d  ", run->data);
        preorder(run->left);
        preorder(run->right);
    }
}
void postorder(struct node *run)
{
    if (run != NULL) 
    {
        postorder(run->left);
        postorder(run->right);
        printf("%d  ", run->data);
    }
}












