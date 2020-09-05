#include<stdio.h>
int main()
{
	int k;
	scanf("%d",&k);
	while(k-->0)
	{
		int n,s;
		scanf("%d %d",&n,&s);
		int cost[n],t1[n],t2[n],tt1=0,tt2=0,t,q;
		for (int i=0; i<n;i++)
		{
			scanf("%d",&cost[i]);
		}
		for (int i=0; i<n;i++)
		{
			scanf("%d",&q);
			if(q==0)
			{
				t1[tt1]=cost[i];
				tt1++;
			}
			else
			{
				t2[tt2]=cost[i];
				tt2++;
			}
		}
		
		if(n<2)
		{
			printf("no");
			return 0;
		}
		
	
		int flag=0;
		for(int i=0; i<tt1; i++)
		{
			for(int j=0;j<tt2;j++)
			{
		
				if(s+t1[i]+t2[j]<=100)
				{
					flag=1;
					break;
				}
			}
		}
		if(flag==1)
		printf("yes\n");
		else
		printf("no\n");
		
	}
}
