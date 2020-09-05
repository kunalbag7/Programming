#include<stdio.h>
int main()
{
        int t;
        scanf("%d",&t);
        while(t--){
                int n;
                scanf("%d",&n);
                int a[n],b[n],sum=0;
                for(int i=0; i<n; i++){
                       scanf("%d",&a[i]);
                       if(i>0)
                       a[i]=a[i]+a[i-1];
                }

                for(int i=0; i<n; i++)
                {
                        scanf("%d",&b[i]);
                        if(i>0)
                        b[i]=b[i]+b[i-1];
                }
                int in=0;
                while(a[in]==b[in])
                  in++;
                if(in>0)
                sum=a[in-1];

                for(int i=in; i<n; i++)
                {
                     if(a[i]==b[i] && a[i-1]==b[i-1])
                     {
                             sum=sum+a[i]-a[i-1];
                     }

                }
                printf("%d\n",sum);


        }

}
