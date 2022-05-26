#include <iostream>

using namespace std;

int main(){
	unsigned long n; cin >> n;
	unsigned long prev; cin >> prev;
	unsigned long moves = 0;
	for(unsigned long i = 1; i<n; i++){
		unsigned long cur; cin >> cur;
		if(cur < prev){ moves += (prev - cur);}
		else{ prev = cur; }
	}
	cout << moves;
	return 0;
}
