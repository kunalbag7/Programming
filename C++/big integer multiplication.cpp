#include <iostream>
#include <math.h>
//#include "KaratsubaMultiplication.h"
using namespace std;



/*int getLength(long long value) {
	int counter = 0;
	while (value != 0) {
		counter++;
		value /= 10;
	}
	return counter;
}

long long multiply(long long x, long long y) {
	int xLength = getLength(x);
	int yLength = getLength(y);

	// the bigger of the two lengths
	int N = (int)(fmax(xLength, yLength));

	// if the max length is small it's faster to just flat out multiply the two nums
	if (N < 10)
		return x * y;

	//max length divided and rounded up
	N = (N/2) + (N%2);

	long long multiplier = pow(10, N);

	long long b = x/multiplier;
	long long a = x - (b * multiplier);
	long long d = y / multiplier;
	long long c = y - (d * N);

	long long z0 = multiply(a,c);
	long long z1 = multiply(a + b, c + d);
	long long z2 = multiply(b, d);


    return z0 + ((z1 - z0 - z2) * multiplier) + (z2 * (long long)(pow(10, 2 * N)));

}*/


// C++ example (uses cout...)
// (this code works in straight C too though if you use a different main function)
int main() {
	// two numbers
	int i=0;
	char a[65], b[65];
	int a1[64],b1[64];
	scanf("%s",&a);
	scanf("%s",&b);
	printf("\n");
	while(a[i]){
			a1[i] = (int)a[i]-48;
			printf("%d",a[i]-48);
			i++;
	}
	printf("\n");
	i=0;
	while(b[i]){
			b1[i] = (int)b[i]-48;
			printf("%d",b1[i]);
			i++;
	}
	//cout << multiply(a,b) << endl;
	
	return 0;
}
