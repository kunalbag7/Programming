#include<stdio.h>
#include<math.h>

void merge_sort(int i, int j, int a[], int aux[]) {
    if (j <= i) {
        return;     // the subsection is empty or a single element
    }
    int mid = (i + j) / 2;

    // left sub-array is a[i .. mid]
    // right sub-array is a[mid + 1 .. j]
    
    merge_sort(i, mid, a, aux);     // sort the left sub-array recursively
    merge_sort(mid + 1, j, a, aux);     // sort the right sub-array recursively

    int pointer_left = i;       // pointer_left points to the beginning of the left sub-array
    int pointer_right = mid + 1;        // pointer_right points to the beginning of the right sub-array
    int k;      // k is the loop counter

    // we loop from i to j to fill each element of the final merged array
    for (k = i; k <= j; k++) {
        if (pointer_left == mid + 1) {      // left pointer has reached the limit
            aux[k] = a[pointer_right];
            pointer_right++;
        } else if (pointer_right == j + 1) {        // right pointer has reached the limit
            aux[k] = a[pointer_left];
            pointer_left++;
        } else if (a[pointer_left] < a[pointer_right]) {        // pointer left points to smaller element
            aux[k] = a[pointer_left];
            pointer_left++;
        } else {        // pointer right points to smaller element
            aux[k] = a[pointer_right];
            pointer_right++;
        }
    }

    for (k = i; k <= j; k++) {      // copy the elements from aux[] to a[]
        a[k] = aux[k];
    }
}


int main()
{
	int n,k,s=0;
	//int A[],B[10];
	scanf("%d",&k);
	scanf("%d",&n);
	int A[n],B[n],Aux[n];
	for(int i=0; i<n;i++)
	{
		scanf("%d",&A[i]);
	}
	for(int i=0; i<n;i++)
	{
		scanf("%d",&B[i]);
	}
	merge_sort(0,n-1, A, Aux);
	merge_sort(0,n-1, B, Aux);
	
	for(int i=0 ; i<n; i++)
	{
		s=s+ ( sqrt(A[i]*A[i] + B[i]*B[i]) );
	}
	
	printf("%d",s);
	
}



