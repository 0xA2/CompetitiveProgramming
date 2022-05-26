#include <iostream>

using namespace std;

int main(){
	unsigned long n; cin >> n;
	for(unsigned long i = 0; i<n; i++){
		unsigned long y,x; cin >> y; cin >> x;
		unsigned long m = max(y,x);

		unsigned long sum = ((m-1)*(m))/2;
		unsigned long diagonal = 1+2*sum;

		if(x == y){
			cout << diagonal << endl;
		}
		else if(y < x){
			if(x%2 == 0){
				cout << diagonal + (y-x)  << endl;
			}
			else{
				cout << diagonal - (y-x)  << endl;
			}
		}
		else{
			if(y%2 == 0){
				cout << diagonal - (x-y)  << endl;
			}
			else{
				cout << diagonal + (x-y) << endl;
			}
		}
	}
	return 0;
}
