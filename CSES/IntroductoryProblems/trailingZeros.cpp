#include <iostream>

using namespace std;

int main(){
	int n; cin >> n;
	int zeros = 0;
	for(int i = 5;  n%i != n; i *= 5){
		zeros += n/i;
	}
	cout << zeros << endl;
	return 0;
}
