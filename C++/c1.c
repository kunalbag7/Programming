#include<stdio.h>

int factorial(int n)
{
    int mul=1;
    for(int i=1;i<=n;i++)
        mul=mul*i;
    return mul;
}

void main()
{
    int n,r,fac;
    scanf("%d",&n); //n=5
    scanf("%d",&r); //r=3

    fac=factorial(n)/(factorial(r)*factorial(n-r))

    printf("%d",fac);
    
}
