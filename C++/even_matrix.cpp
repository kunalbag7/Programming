#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	scanf("%d",&t);
	while(t--)
	{
	        int n,k=5;
	        scanf("%d",&n);
	        if(n==1)
	        printf("1\n");
	        int arr[n][n];
	        arr[0][0]=1;
	        arr[0][1]=2;
	        arr[1][0]=4;
	        arr[1][1]=3;
	        for(int i=2; i<n; i++)
	        {
	                for(int j=0; j<=i; j++)
	                {
	                        arr[j][i]=k;
	                        k++;
	                }
	                for(int j=i-1; j>=0; j--)
	                {
	                       arr[i][j]=k;
	                       k++;
	                }
	        }
	        for(int i=0; i<n; i++)
	        {
	                for(int j=0; j<n; j++){

	                       printf("%d  ",arr[i][j]);

	                }

	               printf("\n");
	        }

	}
	return 0;
}
