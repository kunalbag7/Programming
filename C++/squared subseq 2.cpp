#include<stdio.h>

int mult(int arr[], int n)
{
		 int start = 0, end=1;
        int product = arr[0];
        int count = 0;
        while (start <= end && end <= n) {
            if (product % 2 != 0 || ((product/2)+1)%2 !=0) {
            	printf("kkk%dkkk\n",product);
                count += end - start;
                if (end < n) product *= arr[end];
                end++;
            } else {
                product /= arr[start++];
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
	printf("\n%d\n",mult(num,n));	
	}
	
}
