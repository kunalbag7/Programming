#include<stdio.h>
int main()
{
  int k;
  scanf("%d", &k);
  while(k-->0)
  {
    int n,m;
    scanf("%d %d",&n,&m);
    int arr[n],narr[m][2];

    for (int i = 0; i < n; i++)
      scanf("%d",&arr[i] );

      for (int i = 0; i < m; i++)
        for (int j = 0; j < 2; j++){
          scanf("%d",&narr[i][j] );
          narr[i][j]=narr[i][j]-1;
        }
    int count = 0;
    int i = 0;

    while (i < n)
    {
        if (arr[i] != i + 1)
        {

            while (arr[i] != i + 1)
            {
                int temp = 0;
                temp = arr[arr[i] - 1];
                arr[arr[i] - 1] = arr[i];
                arr[i] = temp;
                count++;
            }
        }
        i++;
    }
    if(count-m<0)
    printf("0\n");
    else
    printf("%d\n",count-m);
  }
}
