#include<stdio.h>
int main()
{
	int c=0,d=0;
	for (int i=1; i<=16;i++)
	{
		for (int j=1; j<=16;j++)
		{
			for (int k=1; k<=16;k++)
			{
				if(i+j+k == 16)
				{
					if(i>10 || j>10 || k>10)
					{
						printf("%d  %d  %d\n",i,j,k);
					c++;
					}
					d++;
				}
			}
		}
	}
	printf("%d	%d",c,d);
}
