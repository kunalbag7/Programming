#include <stdio.h>

int check(long long int h[], long long int b, long long int c)
{
        long long int i,f=0;
        if(b>c)
        {
                for(i=c; i<b; i++)
                {
                      if(h[i]>=h[b]){
                      f=1;
                      break;}
                }
                return f;
        }
        else{
                for(i=b+1; i<=c; i++)
                {
                      if(h[i]>=h[b]){
                      f=1;
                      break;}
                }
                return f;
        }
        if(b>c){
                
        }
        
}


void merge(long long int arr[][2],long long int l,long long int m,long long int r) 
{ 
    long long int i, j, k; 
    long long int n1 = m - l + 1; 
    long long int n2 = r - m; 
  
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
  
void mergeSort(long long int arr[][2],long long int l,long long int r) 
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

int main(void) {
	// your code goes here
	
	long long int n,q,i,j,k,a,b,c,taste=0,temp1,temp2;
	scanf("%lld %lld",&n,&q);
	long long int h[n],t[n],stat[n][2];
	for(i=0; i<n ;i++)
	scanf("%lld",&h[i]);
	for(i=0; i<n ;i++)
	scanf("%lld",&t[i]);
	while(q--)
	{
	        scanf("%lld %lld %lld",&a,&b,&c);
	        b--; c--;
	        if(a==1) t[b]=c+1;
	        else
	        {
	                if(check(h,b,c)) printf("-1\n");
	                else{
	                        if(b==c){ printf("%lld",t[b]); goto flag3;}
	                        if(b<c){
	                                
	                                for(i=b+1,j=0; i<=c; j++,i++)
	                                {
	                                        stat[j][0]=h[b]-h[i];
	                                        stat[j][1]=j+1;
	                                }
	                        }
	                        else{
	                               for(i=b-1,j=0; i>=c; j++,i--)
	                                {
	                                        stat[j][0]=h[b]-h[i];
	                                        stat[j][1]=j+1;
	                                } 
	                        }
	                        
	                        mergeSort(stat,0,j-1);
	                        taste=t[b];
	                        if(b<c)
	                        {
	                                /*i=0; temp2=0;
	                                while(stat[i][0]==stat[i+1][0])
	                                i++;
	                                for(k=0; k<=i; k++)
	                                {
	                                     if(stat[k][1]<j && stat[k][0]<stat[j-1][0]) temp2++;   
	                                }
	                                if(temp2>1){ printf("-1"); goto flag3; }*/
	                                
	                                i=0;
	                                temp1=0;
	                                while(1)
	                                {
	                                        while(stat[i][0]==stat[i+1][0]){
	                                               if(stat[i][1]==j)
	                                                goto flag;
	                                               i++;
	                                               
	                                        }
	                                        if(stat[i][1]==j)
	                                                goto flag;
	                                                
	                                        if(stat[i][1]>temp1){
	                                            taste=taste+t[b+stat[i][1]];
	                                            temp1=stat[i][1];
	                                           
	                                        }
	                                        i++;
	                                }
	                                flag:
	                                     taste=taste+t[c];
	                                     printf("%lld\n",taste);
	                        }
	                        else
	                        {
	                        	/*i=0; temp2=0;
	                        	while(stat[i][0]==stat[i+1][0])
	                                i++;
	                                for(k=0; k<=i; k++)
	                                {
	                                     if(stat[k][1]<j && stat[k][0]<stat[j-1][0]) temp2++;   
	                                }
	                                if(temp2>1){ printf("-1"); goto flag3; }*/
	                                
	                                i=0;
	                                temp1=0;
	                                while(1)
	                                {
	                                        while(stat[i][0]==stat[i+1][0]){
	                                               if(stat[i][1]==j)
	                                                goto flag;
	                                               i++;
	                                               
	                                        }
	                                        if(stat[i][1]==j)
	                                                goto flag1;
	                                                
	                                        if(stat[i][1]>temp1){
	                                            taste=taste+t[b-stat[i][1]];
	                                            temp1=stat[i][1];
	                                           
	                                        }
	                                        i++;
	                                }
	                                flag1:
	                                     taste=taste+t[c];
	                                     printf("%lld\n",taste);
	                        	
							} 
	                      flag3:
	                            printf("\n");
	                }
	        }
	        
	}
	return 0;
}

/*18 5
8 5 7 5 6 2 4 2 6 2 5 2 6 5 3 1 2 5
1 7 3 5 10 11 2 4 8 9 9 7 8 3 5 10 9 7*/

