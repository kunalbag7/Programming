#include<stdio.h>
int main()
{
        int t;
        scanf("%d",&t);
        while(t-->0){
                int a[5],p,sum=0;
                for(int i=0; i<5; i++)
                {
                      scanf("%d",&a[i]);
                }
                scanf("%d",&p);
                for(int i=0; i<5; i++)
                {
                      sum=sum+(a[i]*p);
                }
                if(sum<=120) printf("NO\n");
                else printf("YES\n");
        }
}
