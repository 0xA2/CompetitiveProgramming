#include <iostream>

using namespace std;

int main(){
	int n; cin >> n;
	// Integers that can be written as 4k+1 and 4k+2 for an integer k cannot be divided as intended
	if(  (n-1)%4 == 0 || (n-2)%4 == 0 ){ cout << "NO" << endl; return 0; }

	// Case for numbers that can be written as 4k+3 for an integer k
	else if( (n-3)%4 == 0 ){
		cout << "YES" << endl;
		cout << (n/2) << endl;
		for(int i = 3; i <= n; i++){
			cout << i << " ";
			if(i%4 == 0){ i += 2; }
		}
		cout << endl;
		cout << (n/2)+1 << endl;
		for(int i = 1; i < n; i++){
			cout << i << " ";
			if(i%2 == 0){ i += 2;  }
		}
	}

	// Case for numbers that can be written as 4k for an integer k
	else{
		cout << "YES" << endl;
		cout << (n/2) << endl;
		for(int i = 1; i <= n; i++){
			cout << i << " ";
			if(i == n/4){ i += n - (n/2); }
		}
		cout << endl;
		cout << (n/2) << endl;
		for(int i = n/4; i < 3*n/4; i++){
			cout << i + 1 << " ";
		}
	}
	cout << endl;
	return 0;
}
