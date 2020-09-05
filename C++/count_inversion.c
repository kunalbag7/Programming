// C program to Count 
// Inversions in an array 
// using Merge Sort 
#include <stdio.h> 
#include<stdlib.h>

/*long int _mergeSort(long int arr[],long int temp[],long int left,long int right); 
long int merge(long int arr[],long int temp[],long int left,long int mid,long int right); 

long int mergeSort(long int arr[],long int array_size) 
{ 
long int* temp = (long int*)malloc(sizeof(long int) * array_size); 
	return _mergeSort(arr, temp, 0, array_size - 1); 
} 

long int _mergeSort(long int arr[],long int temp[],long int left,long int right) 
{ 
long int mid, inv_count = 0; 
	if (right > left) { 
		
		mid = (right + left) / 2; 

	
		inv_count += _mergeSort(arr, temp, left, mid); 
		inv_count += _mergeSort(arr, temp, mid + 1, right); 

	
		inv_count += merge(arr, temp, left, mid + 1, right); 
	} 
	return inv_count; 
} 


long int merge(long int arr[],long int temp[],long int left,long int mid,long int right) 
{ 
	long int i, j, k; 
	long int inv_count = 0; 

	i = left; 
	j = mid;
	k = left;
	while ((i <= mid - 1) && (j <= right)) { 
		if (arr[i] <= arr[j]) { 
			temp[k++] = arr[i++]; 
		} 
		else { 
			temp[k++] = arr[j++]; 

		
			inv_count = inv_count + (mid - i); 
		} 
	} 

	while (i <= mid - 1) 
		temp[k++] = arr[i++]; 


	while (j <= right) 
		temp[k++] = arr[j++]; 

	for (i = left; i <= right; i++) 
		arr[i] = temp[i]; 

	return inv_count; 
} 

long int getInvCount(long int arr[],long int n) 
{ 
    long int inv_count = 0,i,j; 
    for (i = 0; i < n - 1; i++) 
        for (j = i + 1; j < n; j++) 
            if (arr[i] > arr[j]) 
                inv_count++; 
  
    return inv_count; 
}*/


long long int merge(long long int arr[], long long int temp[], long long int left, long long int mid, long long int right) {
   long long int i, j, k;
   long long int count = 0;
   
   i = left;    //i to locate first array location
   j = mid;     //i to locate second array location
   k = left;    //i to locate merged array location

   while ((i <= mid - 1) && (j <= right)) {
      if (arr[i] <= arr[j]) {    //when left item is less than right item
         temp[k++] = arr[i++];
      }else{
         temp[k++] = arr[j++];
         count += (mid - i);    //find how many convertion is performed
      }
   }

    while (i <= mid - 1)    //if first list has remaining item, add them in the list
       temp[k++] = arr[i++];

    while (j <= right)    //if second list has remaining item, add them in the list
       temp[k++] = arr[j++];
   
    for (i=left; i <= right; i++)
       arr[i] = temp[i];    //store temp Array to main array
    return count;
}

long long int mergeSort(long long int arr[], long long int temp[], long long int left, long long int right) {
   long long int mid, count = 0;

   if (right > left) {
      mid = (right + left)/2;    //find mid index of the array
      count  = mergeSort(arr, temp, left, mid);    //merge sort left sub array
      count += mergeSort(arr, temp, mid+1, right);    //merge sort right sub array
         
      count += merge(arr, temp, left, mid+1, right);    //merge two sub arrays
   }
   return count;
}

long long int arrInversion(long long int arr[],long long int n) {
   long long int temp[n];
   return mergeSort(arr, temp, 0, n - 1);
}


/* Driver program to test above functions */
int main() 
{ 
FILE *file;
file = fopen("integer.txt", "r");
	long long int arr[100000],i,num;
	for(i=0; i<100000; i++)
	{
		fscanf(file, "%lld", &num);
		arr[i]=num;
	}
	printf("Number of inversions are %lld \n", arrInversion(arr, 100000));
	getchar(); 
	return 0; 
} 

