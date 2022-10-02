/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int insertion_sort(int,int);
int binary_search(int,int);
int a[20];
int main()
{
    int n,i;
    printf("Enter The Number Of Digits To Be Inserted :");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter The Number :");
        scanf("%d",&a[i]);
    }
    insertion_sort(n,i);
    binary_search(n,i);
}
int insertion_sort(int n,int i)
{
    int j,key;
    for(i=1;i<n;i++)
    {
        key=a[i];
        j=i-1;
        while(key<a[j])
        {
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=key;
    }
    printf("The Element Are :");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
int binary_search(int n,int i)
{
    int mid,j,search;
    printf("\nEnter The Number To Be Searched :");
    scanf("%d",&search);
    i=0;
    j=n-1;
    while(i<=j)
    { 
        mid=(i+j)/2;
        if(search==a[mid])
        {
            printf("The Element Present At %d Position Which Is %d",mid+1,a[mid]);
            return 0;
        }
        else if(a[mid]<search)
        {
            i=mid+1;
        }
        else
        {
            j=mid-1;
        }
    }
    printf("Element Not Found In The List ");
    
}