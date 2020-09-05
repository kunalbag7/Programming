#include<stdio.h>


int main()
{
  long long int c,n,k,l,m,p,u,flag=0,temp1;
  scanf("%lld",&c);
  scanf("%lld",&n);
  scanf("%lld",&k);
  long long int interval[n][3];
  long long int cake[c];
  for(long long int i=0; i<n; i++)
    for(long long int j=0; j<2; j++)
      scanf("%lld",&interval[i][j]);

    for(long long int i=0; i<n; i++)
      interval[i][2]=interval[i][1]-interval[i][0]+1;

      long long int i, j;
      for (i = 0; i < n-1; i++)
      // Last i elements are already in place
      for (j = 0; j < n-i-1; j++)
          if (interval[j][2] < interval[j+1][2])
               {
                 l=interval[j][0];
                 m=interval[j][1];
                 p=interval[j][2];
                 interval[j][0]=interval[j+1][0];
                 interval[j][1]=interval[j+1][1];
                 interval[j][2]=interval[j+1][2];
                 interval[j+1][0]=l;
                interval[j+1][1]=m;
                interval[j+1][2]=p;
               }


      for(long long int a=0; a<c; a++)
      {
        cake[a]=0;
      }

      //scanf("%d",&interval[i][j]);

      for(long long int a=0; a<n; a++)
      {
        //int temp=interval[a][2];
        for(long long int b=interval[a][0]-1; b<=interval[a][1]-1; b++)
        {
          if(cake[b]==0)
          cake[b]=1;
          else
          {
            u=a;
            break;
          }
      }
    }
    //printf("	%d	",u);
    for(long long int a=0; a<c; a++)
    {
      if(cake[a]==0)
      {
        temp1=interval[u][2];

        for(long long int b=a, r=0; r<temp1; b++,r++)
        {
        //	printf("\n%d",temp1);
        //	printf("bg");
          if(cake[b]==1)
          {
            flag=1;
            break;
          }
       // printf("bg");
        }
      }
      break;
    }
    //printf("%d",flag);
    if(flag==1)
    printf("Bad");
    else
    printf("Good");
}
