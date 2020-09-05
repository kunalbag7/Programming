#include <iostream>
#include<stdlib.h>
using namespace std;

void merge(long long int arr[],long long int l,long long int m,long long int r) 
{ 
    long long int i, j, k; 
    long long int n1 = m - l + 1; 
    long long int n2 = r - m; 
  
    /* create temp arrays */
    int L[n1], R[n2]; 
  
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

void mergeSort(long long int arr[],long long int l,long long int r) 
{ 
    if (l < r) { 
        long long int m = l + (r - l) / 2; 
        mergeSort(arr, l, m); 
        mergeSort(arr, m + 1, r); 
  
        merge(arr, l, m, r); 
    } 
}


int main() {
	long long int var=(2*10*10*10*10*10) + 1;
	//printf("%lld ",var);
	// your code goes here
	int k;
	scanf("%d",&k);
	while(k--)
	{
	        long long int n;
	        long long int* s=(long long int*) calloc (var , sizeof(long long int));
	        int flag=0;
	        
	        scanf("%lld",&n);
	        long long int A[n],A1[n],A2[n],A3[n],index1=0,index2=0,index3=0;
	        for(long long int i=0; i<n; i++)
	        {
	                scanf("%lld",&A[i]);
	                s[A[i]]++;
	        }
	        
	        for(long long int i=1; i<var; i++)
	        {
	        	
	                if(s[i]>2)
	                {
	                      printf("NO");
	                      goto flag;
	                }
	                
	        }
	        
	        for(long long int i=1; i<var; i++)
	        {
	                if(s[i]==1)
	                {
	                        A1[index1]=i;
	                        index1++;
	                }
	                else if(s[i]==2)
	                {
	                        A1[index1]=i;
	                        index1++;
	                        A2[index2]=i;
	                        index2++;
	                }
	        }
	        
	        mergeSort(A1,0,index1-1);
	        mergeSort(A2,0,index2-1);
	        index3=index2-1;
	        for(long long int i=0; i<index2; i++)
	        {
	               A3[index3]=A2[i];
	               index3--;
	        }
	        for(long long int i=0; i<index1; i++)
	        {
	                A[i]=A1[i];
	        }
	        
	        for(long long int i=0; i<index2; i++)
	        {
	               A[index1++]=A3[i];
	               
	        }
	        
	        
	        for(long long int i=0; i<n-1; i++)
	        {
	                if(A[i]==A[i+1])
	                {
	                        flag=1;
	                        break;
	                }
	        }
	        
	        if(flag==1)
	        printf("NO");
	        else
	        {
	                printf("YES\n");
	                for(long long int i=0; i<n; i++)
	                {
	                        printf("%lld ",A[i]);
	                } 
	                
	        }
	        
	  		flag:
	     		printf("\n");      
	}
	
}

