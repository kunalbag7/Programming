#include<stdio.h>

void count(int a[], int idx)
{
	int temp=1;
	for(int i=0; i<=idx; i++)
	{
			
	}	
}

void subsqh(int a[], int , int idx, int p[], int pi)
{
	if(idx>=n)
		return;
	
	p[pi]=a[idx];
	count(p,pi);
	for(int i=idx+1; i<n; i++)
	{
		subsqh(a,n,i,p,pi+1)	
	}
}
void subsq( int a[] , int n)
{
	int p[n];
	for(int i=0; i<n; i++)
	{
		subsqh(a,n,i,p,0);
	}
}

int main()
{
	
}
