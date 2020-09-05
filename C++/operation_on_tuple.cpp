#include<stdio.h>
#define GARBAGE 2147483600

int equal_num(long int a[],long int b[])
{
  int count=0;
  for (int i = 0; i < 3; i++) {
    /* code */
    if(a[i]==b[i]) count++;
  }
  return count;
}

int same_ele(long int a[])
{

  int count=0;
  /*for (int i = 0; i < 3; i++) {

          printf("%d  ",a[i]);
      }*/
  for (int i = 0; i < 3; i++)
    for (int j = i+1; j < 3; j++)
              //printf("%d %d\n",a[i],a[j] );
              if(a[i]==a[j])
              {
                count++;
              }



  //printf("%d",count);
  return count;
}

int toggle(long int a[])
{
  int flag=0;
  if(a[0]==a[1]+a[2]) flag=1;
  else if(a[1]==a[0]+a[2]) flag=1;
  else if(a[2]==a[0]+a[1]) flag=1;

  return flag;

}

int toggle1(long int a[])
{
  int flag=0;
  if(a[0]==a[1]*a[2]) flag=1;
  else if(a[1]==a[0]*a[2]) flag=1;
  else if(a[2]==a[0]*a[1]) flag=1;

  return flag;

}

int small(long int a[])
{
  long int temp=a[0];
  int in=0;
  for(int i=1; i<3; i++)
  {
          if(a[i]<temp)
          {
                  temp=a[i];
                  in=i;
          }
  }
  //printf("%d",in);
        return in;
}

int main()
{
  int t;
  scanf("%d",&t);
  while(t--)
  {
    long int real[3],tar[3];
    scanf("%ld %ld %ld",&real[0],&real[1],&real[2]);
    scanf("%ld %ld %ld",&tar[0],&tar[1],&tar[2]);
    long int diff[3],mul[3];
    int w,w1,w2;
    for (int i = 0; i < 3; i++) {
          diff[i]=tar[i]-real[i];
          //printf("%d  ",diff[i]);
      }
    int r=equal_num(real,tar);
    //printf("%d",r);
    switch (r) {
      case 3: printf("0"); goto flag1;
      case 2: printf("1"); goto flag1;
      case 1: //printf("Yes");
              w=same_ele(diff);
              //printf("%d",w);
              if(w==1)
              {printf("1"); goto flag1;}
              else{
                    for (int i = 0; i < 3; i++) {
                      if(real[i]!=0)
                      {
                        if(tar[i]%real[i]==0)
                        {
                          mul[i]=tar[i]/real[i];
                          if(mul[i]==1) mul[i]=0;
                        }else mul[i]=GARBAGE;
                      }
                      else mul[i]=GARBAGE;
                    }
                     w=same_ele(mul);
                     if(w==1)
                     {printf("1"); goto flag1; }
                     else
                     {printf("2"); goto flag1; }

              }

          case 0: //printf("Yes");
                  w=same_ele(diff);
                  //printf("%d\n",w );
                  if(w==3) { printf("1"); goto flag1; }
                  else if(w==1) {
                    for (int i = 0; i < 3; i++) {
                      if(real[i]!=0)
                      {
                        if(tar[i]%real[i]==0)
                        {
                          mul[i]=tar[i]/real[i];
                        }else mul[i]=GARBAGE;
                      }else mul[i]=GARBAGE;
                    }
                    w1=same_ele(mul);
                    //printf("%d",w1);
                    if(w1==3){ printf("1"); goto flag1;}
                    else { printf("2"); goto flag1; }
                  }
                  else{
                     for (int i = 0; i < 3; i++) {
                      if(real[i]!=0)
                      {
                        if(tar[i]%real[i]==0)
                        {
                          mul[i]=tar[i]/real[i];
                          //if(mul[i]==1) mul[i]=0;
                          //printf("%d  ",mul[i]);
                        }else mul[i]=GARBAGE;
                      }else mul[i]=GARBAGE;
                      //else mul[i]=-1;
                    }
                    if(toggle(diff)) { printf("2"); goto flag1; }
                    if(toggle1(mul)) { printf("2"); goto flag1; }
                    w1=small(diff);
                   // printf("%d",w1);
                    switch(w1){
                      case 0:  real[0]=real[0]+diff[0];
                              //printf("yes");
                              if(tar[1]>=real[1]+diff[0]){
                              real[1]=real[1]+diff[0];

                              for (int i = 0; i < 3; i++) {
                                if(real[i]!=0)
                                {
                                  if(tar[i]%real[i]==0)
                                  {
                                    mul[i]=tar[i]/real[i];
                                    if(mul[i]==1) mul[i]=0;
                                  }else mul[i]=GARBAGE;
                                }else mul[i]=GARBAGE;
                              }
                              w=same_ele(mul);
                              if(w==1) {printf("2"); goto flag1; }  real[1]=real[1]-diff[0];}
                              if(tar[2]>=real[2]+diff[0]){
                              real[2]=real[2]+diff[0];
                              //real[1]=real[1]-diff[0];
                              for (int i = 0; i < 3; i++) {
                                if(real[i]!=0)
                                {
                                  if(tar[i]%real[i]==0)
                                  {
                                    mul[i]=tar[i]/real[i];
                                    if(mul[i]==1) mul[i]=0;
                                  }else mul[i]=GARBAGE;
                                }else mul[i]=GARBAGE;
                              }
                              w=same_ele(mul);
                              if(w==1) {printf("2"); goto flag1; }  real[2]=real[2]-diff[0]; }
                              if(tar[1]>=real[1]+diff[0] && tar[2]>=real[2]+diff[0]){
                              real[1]=real[1]+diff[0];  real[2]=real[2]+diff[0];
                              for (int i = 0; i < 3; i++) {
                                if(real[i]!=0)
                                {
                                  if(tar[i]%real[i]==0)
                                  {
                                    mul[i]=tar[i]/real[i];
                                    if(mul[i]==1) mul[i]=0;
                                  }else mul[i]=GARBAGE;
                                }else mul[i]=GARBAGE;
                              }
                              w=same_ele(mul);
                              if(w==1) {printf("2"); goto flag1; }
                              real[1]=real[1]-diff[0]; real[2]=real[2]-diff[0];
                               }
                              real[0]=real[0]-diff[0];
                              //printf("Yes");
                              break;

                          case 1: real[1]=real[1]+diff[1];

                                if(tar[0]>=real[0]+diff[1]){
                                real[0]=real[0]+diff[1];
                                for (int i = 0; i < 3; i++) {
                                  if(real[i]!=0)
                                  {
                                    if(tar[i]%real[i]==0)
                                    {
                                      mul[i]=tar[i]/real[i];
                                      if(mul[i]==1) mul[i]=0;
                                    }else mul[i]=GARBAGE;
                                  }else mul[i]=GARBAGE;
                                }
                                w=same_ele(mul);
                                if(w==1) {printf("2"); goto flag1; }   real[0]=real[0]-diff[1]; }
                                if(tar[2]>=real[2]+diff[1]){
                                real[2]=real[2]+diff[1];
                                //real[0]=real[0]-diff[1];
                                for (int i = 0; i < 3; i++) {
                                  if(real[i]!=0)
                                  {
                                    if(tar[i]%real[i]==0)
                                    {
                                      mul[i]=tar[i]/real[i];
                                      if(mul[i]==1) mul[i]=0;
                                    }else mul[i]=GARBAGE;
                                  }else mul[i]=GARBAGE;
                                }
                                w=same_ele(mul);
                                if(w==1) {printf("2"); goto flag1; } real[2]=real[2]-diff[1];}
                                if(tar[0]>=real[0]+diff[1] && tar[2]>=real[2]+diff[1]){
                                real[0]=real[0]+diff[1];
                                real[2]=real[2]+diff[1];
                                for (int i = 0; i < 3; i++) {
                                  if(real[i]!=0)
                                  {
                                    if(tar[i]%real[i]==0)
                                    {
                                      mul[i]=tar[i]/real[i];
                                      if(mul[i]==1) mul[i]=0;
                                    }else mul[i]=GARBAGE;
                                  }else mul[i]=GARBAGE;
                                }
                                w=same_ele(mul);
                                if(w==1) {printf("2"); goto flag1; }real[0]=real[0]-diff[1];
                                real[2]=real[2]-diff[1];}
                                real[1]=real[1]-diff[1];
                                break;

                                case 2: real[2]=real[2]+diff[2];
                                if(tar[0]>=real[0]+diff[2]){
                                      real[0]=real[0]+diff[2];

                                      for (int i = 0; i < 3; i++) {
                                        if(real[i]!=0)
                                        {
                                          if(tar[i]%real[i]==0)
                                          {
                                            mul[i]=tar[i]/real[i];
                                            if(mul[i]==1) mul[i]=0;
                                          }else mul[i]=GARBAGE;
                                        }else mul[i]=GARBAGE;
                                      }
                                      w=same_ele(mul);
                                      if(w==1) {printf("2"); goto flag1; }real[0]=real[0]-diff[2]; }
                                      if(tar[1]>=real[1]+diff[2]){
                                      real[1]=real[1]+diff[2];
                                      //real[0]=real[0]-diff[2];
                                      for (int i = 0; i < 3; i++) {
                                        if(real[i]!=0)
                                        {
                                          if(tar[i]%real[i]==0)
                                          {
                                            mul[i]=tar[i]/real[i];
                                            if(mul[i]==1) mul[i]=0;
                                          }else mul[i]=GARBAGE;
                                        }else mul[i]=GARBAGE;
                                      }
                                      w=same_ele(mul);
                                      if(w==1) {printf("2"); goto flag1; } real[1]=real[1]-diff[2];}
                                      if(tar[0]>=real[0]+diff[2] && tar[1]>=real[1]+diff[2]){
                                      real[0]=real[0]+diff[2];
                                      real[1]=real[1]+diff[2];
                                      for (int i = 0; i < 3; i++) {
                                        if(real[i]!=0)
                                        {
                                          if(tar[i]%real[i]==0)
                                          {
                                            mul[i]=tar[i]/real[i];
                                            if(mul[i]==1) mul[i]=0;
                                          }
                                          else mul[i]=GARBAGE;
                                        }
                                        else mul[i]=GARBAGE;
                                      }
                                      w=same_ele(mul);
                                      if(w==1) {printf("2"); goto flag1; } real[0]=real[0]-diff[2];
                                      real[1]=real[1]-diff[2];}
                                      break;
                    }
                    for (int i = 0; i < 3; i++) {
                      if(real[i]!=0)
                      {
                        if(tar[i]%real[i]==0)
                        {
                          mul[i]=tar[i]/real[i];
                          //if(mul[i]==1) mul[i]=0;
                          //printf("%d  ",mul[i]);
                        }
                        else mul[i]=GARBAGE;
                      }
                      else mul[i]=GARBAGE;
                      //printf("%d ",mul[2]);

                  }
                  w1=small(mul);
                    //printf("%d",w1);
                    switch(w1){
                            case 0:
                                   real[0]=real[0]*mul[0];
                                   if(tar[1]>=real[1]*mul[0]){
                                           real[1]=real[1]*mul[0];
                                           for (int i = 0; i < 3; i++) {
                                                  diff[i]=tar[i]-real[i];
                                                  //printf("%d  ",diff[i]);
                                              }
                                         w2=same_ele(diff);
                                         if(w2==1) { printf("2"); goto flag1; }

                                   }
                                   if(tar[2]>=real[2]*mul[0]){
                                           real[1]=real[1]/mul[0];
                                           real[2]=real[2]*mul[0];
                                           for (int i = 0; i < 3; i++) {
                                                  diff[i]=tar[i]-real[i];
                                                  //printf("%d  ",diff[i]);
                                              }
                                         w2=same_ele(diff);
                                         if(w2==1) { printf("2"); goto flag1; }

                                   }
                                   if(tar[1]>=real[1]*mul[0] && tar[2]>=real[2]/mul[0]){
                                           real[1]=real[1]*mul[0];
                                           for (int i = 0; i < 3; i++) {
                                                  diff[i]=tar[i]-real[i];
                                                  //printf("%d  ",diff[i]);
                                              }
                                         w2=same_ele(diff);
                                         if(w2==1) { printf("2"); goto flag1; }

                                   }
                                   break;
                                case 1: //printf("Yes");
                                       real[1]=real[1]*mul[1];
                                   if(tar[0]>=real[0]*mul[1]){
                                           real[0]=real[0]*mul[1];
                                           for (int i = 0; i < 3; i++) {
                                                  diff[i]=tar[i]-real[i];
                                                //  printf("%ld  ",diff[i]);
                                              }
                                         w2=same_ele(diff);
                                         if(w2==1) { printf("2"); goto flag1; }

                                   }
                                   if(tar[2]>=real[2]*mul[1]){
                                           real[0]=real[0]/mul[1];
                                           real[2]=real[2]*mul[1];
                                           for (int i = 0; i < 3; i++) {
                                                  diff[i]=tar[i]-real[i];
                                                  //printf("%d  ",diff[i]);
                                              }
                                         w2=same_ele(diff);
                                         if(w2==1) { printf("2"); goto flag1; }

                                   }
                                   if(tar[0]>=real[0]*mul[1] && tar[2]>=real[2]/mul[1]){
                                           real[0]=real[0]*mul[1];
                                           for (int i = 0; i < 3; i++) {
                                                  diff[i]=tar[i]-real[i];
                                                  //printf("%d  ",diff[i]);
                                              }
                                         w2=same_ele(diff);
                                         if(w2==1) { printf("2"); goto flag1; }

                                   }
                                   break;

                                case 2:
                                        real[2]=real[2]*mul[2];
                                   if(tar[1]>=real[1]*mul[2]){
                                           real[1]=real[1]*mul[2];
                                           for (int i = 0; i < 3; i++) {
                                                  diff[i]=tar[i]-real[i];
                                                  //printf("%d  ",diff[i]);
                                              }
                                         w2=same_ele(diff);
                                         if(w2==1) { printf("2"); goto flag1; }

                                   }
                                   if(tar[0]>=real[0]*mul[2]){
                                           real[1]=real[1]/mul[2];
                                           real[0]=real[0]*mul[2];
                                           for (int i = 0; i < 3; i++) {
                                                  diff[i]=tar[i]-real[i];
                                                  //printf("%d  ",diff[i]);
                                              }
                                         w2=same_ele(diff);
                                         if(w2==1) { printf("2"); goto flag1; }

                                   }
                                   if(tar[1]>=real[1]*mul[2] && tar[0]>=real[0]/mul[2]){
                                           real[1]=real[1]*mul[2];
                                           for (int i = 0; i < 3; i++) {
                                                  diff[i]=tar[i]-real[i];
                                                  //printf("%d  ",diff[i]);
                                              }
                                         w2=same_ele(diff);
                                         if(w2==1) { printf("2"); goto flag1; }

                                   }
                                   break;
                    }


               }
               break;
}
    printf("3");
    flag1:
          printf("\n");
  }
}
