#include <iostream>

using namespace std;

unsigned long modularPower(unsigned long base, unsigned long exponent, unsigned long modulus){
	if( modulus == 1){ return 0; }
	unsigned long result = 1;
	while(exponent > 0){
		if( exponent%2 != 0){
			result = (result*base)%modulus;
		}
		exponent = exponent >> 1;
		base = (base*base)%modulus;
	}
	return result;
}

int main(){
	int n; cin >> n;
	unsigned long mod = 10*10*10*10*10*10*10*10*10+7;
	cout << modularPower(2, n, mod) << endl;
	return 0;
}
