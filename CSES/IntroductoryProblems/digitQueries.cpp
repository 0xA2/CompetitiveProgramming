#include <iostream>
#include <string>

#include <math.h>

using namespace std;

unsigned long findDigit(unsigned long n){
	unsigned long len;
	unsigned long curLenCount;
	for(len = 1, curLenCount = 9; n > curLenCount; len++){
		n -= curLenCount;
		curLenCount = (curLenCount * 10)/len * (len+1);
	}
	unsigned long number = long(pow(10,(len-1))) + (n-1)/len;
	return to_string(number)[(n-1)%len] - '0';
}

int main(){
	int n; cin >> n;
	for(int i = 0; i<n; i++){
		unsigned long k; cin >> k;
		cout << findDigit(k) << endl;
	}

	return 0;
}
