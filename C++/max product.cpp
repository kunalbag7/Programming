#include<stdio.h>

int mult (int arr[], int n)
{
	int start = 0;
        int end = 1;
        long product = arr[0];
        int count = 0;
        while (start <= end && end <= n) {
            
			
			
			}
        return count;
}


int main()
{
	int k,n;
	//scanf("%d",&k);
	scanf("%d",&n);
	int num[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&num[i]);
	}
	printf("%d\n",mult(num,n));	
	
}
