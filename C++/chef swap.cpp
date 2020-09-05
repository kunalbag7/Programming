#include <iostream>
using namespace std;



long long int occ(long long int ar[],long long int n) 
{ 
    long long int res = 0, i;  
    for (i = 0; i < n; i++)      
        res = res ^ ar[i]; 
      
    return res; 
} 

void merge(long long int arr[],long long int l,long long int m,long long int r) 
{ 
   long long int i, j, k; 
    long long int n1 = m - l + 1; 
    long long int n2 = r - m; 
  
    /* create temp arrays */
    long long int L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1 + j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) { 
        if (L[i] <= R[j]) { 
            arr[k] = L[i]; 
            i++; 
        } 
        else { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
/* l is for left index and r is right index of the 
   sub-array of arr to be sorted */
void mergeSort(long long int arr[],long long int l,long long int r) 
{ 
    if (l < r) { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        long long int m = l + (r - l) / 2; 
  
        // Sort first and second halves 
        mergeSort(arr, l, m); 
        mergeSort(arr, m + 1, r); 
  
        merge(arr, l, m, r); 
    } 
}

int check(long long int a[], long long int b[], long long int n)
{
        mergeSort(a,0,n-1);
        mergeSort(b,0,n-1);
        int flag=0;
        for(long long int i=0; i<n; i++)
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

long long int small(long long int a, long long int b, long long int c)
{
        long long int t=a;
        if(a>b)
        t=b;
        
        if(t>c)
        t=c;
        
        return c;
        
        
}

int main() {
	int t;
	scanf("%d",&t);
	long long int num=1000000001;
	long long int *freqA=(long long int *) calloc (num, sizeof(long long int));
	long long int *freqB=(long long int *) calloc (num, sizeof(long long int));
	while(t--)
	{
	        long long int i,n,m,j,tot1=0,tot2=0;
	        scanf("%lld",&n);
	        m=2*n;
	        long long int A[n],B[n],C[m];
	        
	        for(i=0; i<n; i++){
	        scanf("%lld",&A[i]);
	        freqA[A[i]]++;
	        C[i]=A[i];}
	        
	        for(i=0; i<n; i++){
	        scanf("%lld",&B[i]);
	        freqB[B[i]]++;
	        C[n+i]=B[i];}
	        
	        if(occ(C,m) != 0 )
	          printf("-1\n");
	        else{
	                if(check(A,B,n))
	                printf("0\n");
	                else{
	                        
	                        long long int sml,index1=0,index2=0,temp,ans=0;
                               sml=A[0];
                               if(sml>B[0])
                               sml=B[0];
                               sml=2*sml;
	                       for(i=1; i<num; i++){
	                               freqA[i]=(freqA[i]-freqB[i])/2;
	                       }
	                       
	                       for(i=0; i<n; i++)
	                       {
	                               A[i]=B[i]=0;
	                       }
	                       
	                       for(i=1; i<num; i++)
	                       {
	                               if(freqA[i]>0)
	                               {
	                                       temp=freqA[i];
	                                       while(temp--)
	                                       {
	                                               A[index1]=i;
	                                               index1++;
	                                       }
	                               }
	                               if(freqA[i]<0)
	                               {
	                                       temp=freqA[i]*(-1);
	                                       while(temp--)
	                                       {
	                                              B[index2]=i;
	                                              index2++;
	                                       }
	                               }
	                       }
	                       
	                       for(i=0,j=index2-1; i<index2, j>=0; j--,i++)
	                       {
	                               ans=ans+small(A[i],B[j],sml);
	                       }
	                       
	                       for(i=0; i<num; i++)
	                       {
	                               freqA[i]=freqB[i]=0;
	                       }
	                       printf("%lld\n",ans);
	                       
	                       
	                }
	               
	                        
	        }
	  }
	        
}

