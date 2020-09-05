#include <stdio.h>
#include <math.h>
/* INCREASE OR DECREASE ARRAY_SIZE TO INCREASE OR DECREASE THE
*  RANGE OF NUMBERS WHOSE FACTORIAL YOU WANT TO CALCULATE 
*  TESTED ON DEV C++ 
*  AUTHOR: TEACHER    
*/
#define ARRAY_SIZE 12000
int fact(int a[],int number,int *f){
int i,carry=0,temp;
for(i=ARRAY_SIZE-1;i>=(*f);--i){
temp=(a[i])*(number)+carry;
a[i]=temp%10;
carry=(temp/10);
}
while(carry){
a[i]=carry%10;
carry=carry/10;
i--;
}
*f=i+1;
}
int main(){
int i=ARRAY_SIZE-1,f=ARRAY_SIZE-1,n,x;
static int a[ARRAY_SIZE];
printf("enter number to calculate its  factorial: ");    
scanf("%d",&x);
if(x==0){
printf("1");
}
else{
int temp=x;
while(temp){
a[i]=temp%10;
temp=temp/10;
i--;
}
f=i+1;
for(i=x-1;i>=1;--i){
fact(a,i,&f);
}
for(i=f;i<=ARRAY_SIZE-1;++i){  
printf("%d",a[i]);
}
printf("\n"); 
}
}
