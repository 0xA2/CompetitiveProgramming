#include <iostream>

using namespace std;

int main(){
	int n; cin >> n;
	for(int i = 0; i<n; i++){
		int a; cin >> a;
		int b; cin >> b;
		int diff = max(a,b)-min(a,b);
		if( (diff <= min(a,b)) && ((a+b)%3 == 0) ){ cout << "YES" << endl; }
		else{
			cout << "NO" << endl;
		}
	}

	return 0;
}
