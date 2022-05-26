#include <iostream>

using namespace std;

int main(){
	unsigned long n; cin >> n;
	for(unsigned long i = 1; i<=n; i++){
		// Calculate all combinations of i choosing 2 at a time
		// Then subtract number of positions in which two knights attack each other
		cout << (i*i*(i*i-1))/2 - (i-1)*(i-2)*4 << endl;
	}
	return 0;
}
