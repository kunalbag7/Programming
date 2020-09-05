#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ss scanf
#define pp printf
#define ll long long int


ll twop[31];

void heapify(ll arr[], ll n, ll i) 
{ 
    ll largest = i; // Initialize largest as root 
    ll l = 2*i + 1; // left = 2*i + 1 
    ll r = 2*i + 2; // right = 2*i + 2 
  
    // If left child is larger than root 
    if (l < n && arr[l] > arr[largest]) 
        largest = l; 
  
    // If right child is larger than largest so far 
    if (r < n && arr[r] > arr[largest]) 
        largest = r; 
  
    // If largest is not root 
    if (largest != i) 
    { 
        swap(arr[i], arr[largest]); 
  
        // Recursively heapify the affected sub-tree 
        heapify(arr, n, largest); 
    } 
} 
  
// main function to do heap sort 
void heapSort(ll arr[], ll n) 
{ 
    // Build heap (rearrange array) 
    for (ll i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i); 
  
    // One by one extract an element from heap 
    for (ll i=n-1; i>0; i--) 
    { 
        // Move current root to end 
        swap(arr[0], arr[i]); 
  
        // call max heapify on the reduced heap 
        heapify(arr, i, 0); 
    } 
}

ll binans(ll a, ll b)
{
     ll num1=b,num2=a;
     for(int i=0; i<31; i++)
     if(twop[i]>b)
     {
             num1=num1+a*twop[i];
             break;
     }
     
     for(int i=0; i<31; i++)
     if(twop[i]>a)
     {
             num2=num2+b*twop[i];
             break;
     }
     
     if(num1-num2<0)
     return num2-num1;
     
     return num1-num2;
     
}

int main() {

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	
    for(int i=0; i<31; i++)
    twop[i]=pow(2,i);
	// your code goes here
	int t;
	ss("%d",&t);
	while(t--)
	{
	        ll n,i,max,ans=0,temp;
	        scanf("%lld",&n);
	        ll arr[n];
	        for(i=0; i<n; i++)
	        scanf("%lld",&arr[i]);
	        
	        if(n<=500)
	        {
	                for(i=0;i<n;i++)
	                for(ll j=i+1; j<n; j++){
	                temp=binans(arr[i],arr[j]);
        	        if(temp>ans)
        	        ans=temp; }
        	        
        	        pp("%lld\n",ans);
	        }
	        else{
	        heapSort(arr,n);
	        
	        max=arr[n-1];
	        
	        for(i=0; i<n-1; i++)
	        {
	             temp=binans(arr[i],max);
	             if(temp>ans)
	             ans=temp;
	        }
	        
	        pp("%lld\n",ans);}
	    
	    
	}
	return 0;
}
