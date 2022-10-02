#include<stdio.h>
#include<stdlib.h>
void insertion_sort(int,int[],int);
void main()
{
    int n,i,a[20];
    printf("Enter the number of element to be entered :");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the number :");
        scanf("%d",&a[i]);
    }
    insertion_sort(n,a,i);
}
void insertion_sort(int n,int a[],int i)
{
    int temp,j,compare;
    for(i=1;i<n;i++)
    {
        compare=a[i];
        j=i-1;
        while(a[j]>compare)
        {
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=compare;
    }
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}