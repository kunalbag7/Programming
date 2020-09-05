#include<stdio.h>

int check(int mul)
{
	if(mul%2!=0)
	{
		return 1;
	}
	else
	{
		int a,b,c;
		c=mul/2;
		a=c+1;
		b=c-1;
		if(a%2 !=0) return 1;
		else return 0;
	}
}

int mult(int arr[], int n) 
{ 
int mul=1,count=0;
    for (int i=0; i <n; i++) 
    { 
        for (int j=i; j<n; j++) 
        { 
        	mul=1;
            for (int k=i; k<=j; k++) 
            {
            	mul=mul*arr[k];
			}
			count=count+check(mul);
        } 
    }
	return count; 
} 

int main()
{
	int k,n;
	scanf("%d",&k);
	for(int j=0; j<k; j++)
	{
		scanf("%d",&n);
	int num[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&num[i]);
	}
	printf("%d\n",mult(num,n));	
	}
	
}
