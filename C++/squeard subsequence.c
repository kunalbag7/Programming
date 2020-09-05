#include <stdio.h>
//now make main function
//start now
int main(void) {
	int t;
	//input t;
	scanf("%d",&t);//inputting the test cases
	while(t-->0)
	{
	    
	    long long n=0;//declaring value of n
	    scanf("%d",&n);
	    int z[n];
	    //now we take input
	    int j=0;
	    long long w=0,v=0,c=0,klk=0;//declaring variables
	    //array will be made now
	    for(j=0;j<n;j++)
	    {
	    //traversing in array
	        int uh=0;
	    
	        scanf("%d",&uh);//taking input
	        if(uh<0)
	        {
	            uh=uh*-1;//if its negavite 
	        }
	        //using of array
	        z[j]=uh;
	    }
	    //delraing elements
	    int o;
	    for(j=0;j<n;j++)//using loop
	    {
	        w=0;//using them to zero
	        v=0;
	        if(z[j]%4==2)//checking divisibility by 4
	        {
	            //in the loop
	            o=j-1;
	            while(o>=0)//checking elements before and after
	            {
	                if(z[o]%2==1)
	                {
	                    w++;//addition
	                    o--;
	                }
	                else
	                {
	                    break;//break out of loop
	                }
	            }
	            o=j+1;//updating o
	            while(o<n)
	            {
	                //using loop
	                if(z[o]%2==1)//using loop
	                {
	                    v++;
	                    o++;
	                }
	                else
	                {
	                    break;//breaking out of loop
	                }
	            }
	            //calculating c
	            c=(c+(w+v+(w*v)+1));//calculating value
	        }
	    }
	    //now we will make output
	    long long q=(n*(n+1))/2;
	    q=q-c;
	    //output result now
	    printf("%lld\n",q);//printing output
	    //end of test case
	}
	//use return 0 in the function to display output
	return 0;
}
//end of program
