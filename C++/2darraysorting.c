#include<stdio.h>
void merge(int arr[][2], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 = r - m; 
  
    /* create temp arrays */
    int L[n1][2], R[n2][2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++){
    	L[i][0] = arr[l + i][0];
    	L[i][1]=arr[l + i][1];
	}
         
    for (j = 0; j < n2; j++){
    	R[j][0] = arr[m + 1 + j][0];
    	R[j][1] = arr[m + 1 + j][1];
	} 
         
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) { 
        if (L[i][0] <= R[j][0]) { 
            arr[k][0] = L[i][0];
			arr[k][1] = L[i][1]; 
            i++; 
        } 
        else { 
            arr[k][0] = R[j][0]; 
            arr[k][1] = R[j][1]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) { 
        arr[k][0] = L[i][0]; 
        arr[k][1] = L[i][1];
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) { 
        arr[k][0] = R[j][0]; 
        arr[k][1] = R[j][1];
        j++; 
        k++; 
    } 
} 
  
void mergeSort(int arr[][2], int l, int r) 
{ 
    if (l < r) { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l + (r - l) / 2; 
  
        // Sort first and second halves 
        mergeSort(arr, l, m); 
        mergeSort(arr, m + 1, r); 
  
        merge(arr, l, m, r); 
    } 
} 

void print(int a[][2], int n){
	int i;
	for(i=0 ; i<n; i++){
		printf("%d %d\n",a[i][0],a[i][1]);
	}
}
int main()
{
	int n=10,m=2,i;
	int d[n][m];
	for(i=0; i<n; i++)
	{
		d[i][0]=n-i;
		d[i][1]=i;
	}
	
	print(d,n);
	mergeSort(d,0, n-1);
	printf("-------------\n");
	print(d,n);
}
