#include<stdio.h>
#include<stdlib.h>

int main()
{
  int t;
  scanf("%d",&t);
  while (t-->0) {
    /* code */
    int n,count=0,no=0,in=-1;
    scanf("%d",&n);
    int* pos= (int*)malloc(n * sizeof(int));
    int* dis= (int*)malloc((n+1) * sizeof(int));

    for(int i=0; i<n; i++)
    {
      scanf("%d",&pos[i]);
    }
    dis[0]=0;
    dis[n]=4;
    for (int i = 1; i < n; i++) {
      /* code */
      dis[i]=pos[i]-pos[i-1];
      if(dis[i]>=3)
      no++;
    }
    no++;
    int* diff= (int*)calloc(no, sizeof(int));
    for(int i=0; i<=n; i++)
    {
      if(dis[i]>=3)
      {
        in++;
        diff[in]=count;
        count=0;
      }
      else
      {
        count++;
      }
    }
    for(int i=1; i<=in; i++)
    {
      diff[i]=diff[i]+1;
    }
    int m=diff[0];
    for(int i=1; i<=in; i++)
    {
      if(diff[i]<m)
      m=diff[i];
    }
    printf("%d ",m);
    m=diff[0];
    for(int i=1; i<=in; i++)
    {
      if(diff[i]>m)
      m=diff[i];
    }
    printf("%d\n",m);

  }
}
