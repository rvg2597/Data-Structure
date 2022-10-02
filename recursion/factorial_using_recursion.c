#include <stdio.h>
int fact(int mul,int n)
{
    if(n==0)
    {
        return mul;
    }
    else
    {
        return fact(mul*n,n-1);
    }
}
int main()
{
    int n,mul=1;
    printf("Enter The Number :");
    scanf("%d",&n);
    printf("The Factoial Of Number Is :%d",fact(mul,n));
}