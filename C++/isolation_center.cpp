#include<stdio.h>
#include<stdlib.h>
int main()
{
  int k;
  scanf("%d",&k);
  while(k-->0)
  {
    int n,q;
    int c;
    int count=1, in=-1;
    scanf("%d %d",&n,&q);
    char* str = (char*) malloc ((n+1)* sizeof(char));
    int* carr = (int*) calloc (26 , sizeof(int));
    scanf("%s",str);
    for (int i = 0; i < n; i++) {
      /* code */
      int temp = str[i];
      temp=temp-97;
      carr[temp]++;
    }
    for (int i = 0; i < 26; i++) {
      if(carr[i]==1)
        carr[i]=0;
    }
    for (int i = 0; i < q; i++) {
      int c1=0;
      scanf("%d",&c);
      for(int j=0; j<26; j++)
      {
        if(carr[j]>=c)
          carr[j]=carr[j]-c;
        else
          carr[j]=0;

        c1=c1+carr[j];
      }
      printf("%d\n",c1);

    }

  }


}
