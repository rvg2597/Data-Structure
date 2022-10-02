
#include <stdio.h>
int binary_search(int arr[],int l,int r,int search)
{
    int mid;
    if(l<=r)
    {    
        mid=(l+r)/2;
        if(arr[mid]==search)
        {
           return mid; 
        }
        else if(arr[mid]>search)
        {
            return binary_search(arr,l,mid-1,search);
        }
        else
        {
            return binary_search(arr,mid+1,r,search);
        }
    }
    else
    {
        return -1;
    }
}
int main()
{
    int n,arr[20],i,l,r,search,mid;
    printf("Enter The Number :");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter The Number To Be Inserted :");
        scanf("%d",&arr[i]);
    }
    printf("Enter The Number To Be Searched :");
    scanf("%d",&search);
    l=0;
    r=n-1;
    mid=binary_search(arr,l,r,search);
    if(mid==-1)
    {
        printf("Element Not Found");
    }
    else
    {
        printf("The Element is found at %d",mid+1);
    }
}
