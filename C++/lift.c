#include <stdio.h>

int main(void) {
	int k;
	scanf("%d",&k);
	while(k-->0)
	{
		//printf("kk");
	    long long int n,q,p=0,tot=0,i;
	    scanf("%lld %lld",&n,&q);

	    for(i=0; i<q; i++)
	    {
	        long long int temp1,temp2;
	       long long int a,b;
	        scanf("%lld %lld",&a,&b);
	        temp1=p-a;
	        if(temp1<0)
	            temp1=temp1*(-1);
	        tot=tot+temp1;
	        temp2=a-b;
	        if(temp2<0)
	            temp2=temp2*(-1);
	        tot=tot+temp2;
	        p=b;

	    }
	    printf("%lld\n",tot);

	}
	return 0;
}
