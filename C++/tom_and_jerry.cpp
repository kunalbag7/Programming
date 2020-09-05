#include <iostream>
using namespace std;

int main() {
	// your code goes here
        long long int k;
	scanf("%lld",&k);
	while(k-->0){
	         int ts;
	        //scanf("%lld",&ts);
	        for (int i=1; i<101; i++)
	        {
                ts=i;
	             while(ts%2==0)
	                ts=ts/2;
    	        if(ts!=0)
    	        {
    	        printf("%d->%d\n",i,ts/2);
    	        }
    	        else
    	        printf("%d->0\n",i);
	        }



	}
	return 0;
}
