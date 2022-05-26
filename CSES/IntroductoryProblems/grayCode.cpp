#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

void printBitString(int bitString[], int n){
	for(int i = n-1; i>=0; i--){
		cout << bitString[i];
	}
	cout << '\n';
}

vector<int> getPattern(int n){
	vector<int> pattern;
	pattern.push_back(1);
	for(int i = 2; i<n; i++){
		vector<int> tmp = pattern;
		pattern.push_back(i);
		pattern.insert(pattern.end(), tmp.begin(), tmp.end());
	}
	return pattern;
}

int main(){
	int n; cin >> n;
	int bitString[n] = {0};

	if(n == 1){ cout << "0" << "\n1" << endl; return 0; }

	printBitString(bitString, n);

	vector<int> pattern = getPattern(n);
	int patternIndex = 0;
	unsigned long ncodes = pattern.size()*2+1;

	for(unsigned long i = 1; i<=ncodes; i++){
		if(i%2 != 0){ bitString[0] = (bitString[0] + 1)%2; }
		else{
			int curIndex = pattern[patternIndex];
			bitString[curIndex] = (bitString[curIndex] + 1)%2;
			patternIndex++;
		}
		printBitString(bitString, n);
	}

	return 0;
}
