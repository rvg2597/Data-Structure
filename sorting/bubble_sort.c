#include<stdio.h>
#include<stdlib.h>
void bubble_sort(int[],int);
void main()
{
    int a[20],i,n;
    printf("Enter the number of element you want to enter :");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the number :");
        scanf("%d",&a[i]);
    }
    bubble_sort(a,n);
    printf("The number In Sorted Order Is :");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}
void bubble_sort(int a[],int n)
{
    int i,j,temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}