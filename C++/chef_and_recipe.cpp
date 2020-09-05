#include<stdio.h>
#include<stdlib.h>
void solve()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    int* count1= (int*)calloc(1001, sizeof(int));
    int temp1=arr[0];
    for(int i=1; i<n; i++)
    {
        if(temp1!=arr[i])
        {
            if(count1[arr[i-1]]!=1)
            {
                count1[arr[i-1]]=1;
            }
            else
            {
                printf("NO");
                return;
            }
            
        }
        temp1=arr[i];
    }
    free(count1);
    int* count= (int*)calloc(n, sizeof(int));
    int temp=arr[0],index=0,c=0;
    for(int i=1;i<n;i++)
    {
        if (temp==arr[i])
            c++;
        else
        {
            count[index]=c;
            index++;
            c=0;
        }
        temp=arr[i];    
    }
    count[index]=c;

    for(int i=0; i<=index; i++)
    {
        int a=count[i];
        for(int j=0;j<=index && i!=j; j++)
        {
            if(count[i]==count[j])
            {
                printf("NO\n");
                return;
            }
        }
    }
    printf("YES\n");
    
}

int main()
{
    int k;
    scanf("%d",&k);
    while(k-->0)
        solve();
}