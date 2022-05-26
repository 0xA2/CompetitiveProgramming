#include <iostream>

using namespace std;

int main(){
	string dna; cin >> dna;
	int curRepeat = 1;
	int maxRepeat = 0;
	for(unsigned long i = 1; i < dna.length(); i++){
		if(dna[i] == dna[i-1]){ curRepeat++; }
		else{
			if(curRepeat > maxRepeat){ maxRepeat = curRepeat; }
			curRepeat = 1;
		}
	}
	if(curRepeat > maxRepeat){ maxRepeat = curRepeat; }
	cout << maxRepeat;
	return 0;
}
