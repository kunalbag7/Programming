#include<stdio.h>
#include<stdlib.h>



long long int occ(long long int ar[],long long int n) 
{ 
    long long int res = 0, i;  
    for (i = 0; i < n; i++)      
        res = res ^ ar[i]; 
      
    return res; 
} 

void swap(long long int* a,long long int* b)  
{  
    long long int t = *a;  
    *a = *b;  
    *b = t;  
}

long long int partition (long long int arr[],long long int low,long long int high)  
{  
    long long int pivot = arr[high];  
    long long int i = (low - 1),j;  
  
    for (j = low; j <= high - 1; j++)  
    {   
        if (arr[j] < pivot)  
        {  
            i++;
            swap(&arr[i], &arr[j]);  
        }  
    }  
    swap(&arr[i + 1], &arr[high]);  
    return (i + 1);  
}
  
void quickSort(long long int arr[],long long int low,long long int high)  
{  
    if (low < high)  
    {  
        long long int pi = partition(arr, low, high);    
        quickSort(arr, low, pi - 1);  
        quickSort(arr, pi + 1, high);  
    }  
}

int check(long long int a[], long long int b[], long long int n)
{
        quickSort(a,0,n-1);
        quickSort(b,0,n-1);
        int flag=0;
        long long int i;
        for(i=0; i<n; i++)
        {
              if(a[i]!=b[i])
              {
                      flag=1;
                      break;
              }
        }
        if(flag==1)
        return 0;
        else
        return 1;
}

long long int xyz(long long int A[], long long int B[], long long int n, long long int Aswap[])
{
	long long int i=0,j=0,Ac=1,Bc=0,index=0,temp;
       while(i<(n-1))
       {
       	while(A[i]==A[i+1])
       	{
       		i++;
       		Ac++;
       		
		   }
		   temp=A[i];
		   
		  while(B[j]!=temp && B[j]<temp && j<n)
		  j++;
		  
		  if(B[j]==temp)
		   while(B[j]==temp && j<n ){
		   	Bc++;
		   	j++;
		   }
		     
		  if(Ac>Bc)
		   {
		   	Ac=(Ac-Bc)/2;
		   	while(Ac--)
		   	{
		   		Aswap[index]=temp;
		   		index++;
			   }
			   
		   }
		   Ac=1;
		   Bc=0;
		   i++;		  
		  
	   }
	   
	   return index;
}


int main() {
	int t;
	scanf("%d",&t);
	while(t--)
	{
	        long long int i,n,m,j;
			long long int sml,ans=0;
	        scanf("%lld",&n);
	        m=2*n;
	        long long int A[n],B[n],C[m],Aswap[n],Bswap[n];
	        
	        for(i=0; i<n; i++){
	        scanf("%lld",&A[i]);
	        C[i]=A[i];}
	        
	        for(i=0; i<n; i++){
	        scanf("%lld",&B[i]);
	        C[n+i]=B[i];}
	        
	       /* for(i=0; i<num; i++)
           {
                   printf("%lld ",freqA[i]);
           }
           printf("\n");
           for(i=0; i<num; i++)
           {
                   printf("%lld ",freqB[i]);
           }*/

	        if(occ(C,m) != 0 )
	          printf("-1\n");
	        else{
	                if(check(A,B,n))
	                printf("0\n");
	                else{
	                        
	                        
                               sml=A[0];
                               if(sml>B[0])
                               sml=B[0];
                               sml=2*sml;
                              j=xyz(A,B,n,Aswap);
							  j= xyz(B,A,n,Bswap); 
                              
							   
							   for(i=0; i<j; i++)
							   {
							   	printf("%lld  ",Aswap[i]);
							   }
							   printf("\n");
							   for(i=0; i<j; i++)
							   {
							   	printf("%lld  ",Bswap[i]);
							   }
                               
                              for(i=0; i<j; i++)
                              {
                              	if (Aswap[i] <= Bswap[j-i-1] && Aswap[i] <= sml) 
							        ans=ans+Aswap[i]; 
							  
							    else if (Bswap[j-i-1] <= Aswap[i] && Bswap[j-i-1] <= sml) 
							        ans=ans+ Bswap[j-i-1];
							  
							    else
							    	ans=ans+sml;
							  }
							  
	                       printf("%lld\n",ans);
	                       
	                       
	                }
	               
	                        
	        }
	  }
	        
}

