#include <iostream>

using namespace std;

int main(){
	unsigned long  n; cin >> n;
	unsigned long totalSum = (n*(n+1))/2;
	unsigned long sum = 0;
	for(unsigned long i = 0; i<(n-1); i++){
		unsigned long cur; cin >> cur;
		sum += cur;
	}
	cout << totalSum - sum;
	return 0;
}
