#include<stdio.h>
int main()
{
	int k;
	scanf("%d",&k);
	while(k-->0)
	{
		long long int k,n;
		scanf("%lld %lld",&n,&k);
		long long int arr[n];
		for (long long int i=0; i<n;i++)
		{
			scanf("%lld",&arr[i]);
		}
		while(1)
		{
			int swap=0;
			for(long long int i=0; i<n-k;i++)
		{
			if(arr[i]>arr[i+k])
			{
				long long int temp= arr[i+k];
				arr[i+k]=arr[i];
				arr[i]=temp;
				swap=1;
			}

		}
			if(swap==0)
				break;
		}

		int flag=0;
		for (long long int i=0; i<n-1;i++)
		{
			if(arr[i]>arr[i+1])
			{
				flag=1;
				break;
			}

		}
		if(flag==1)
		{
			printf("no\n");

		}
		else printf("yes\n");

	}
}
