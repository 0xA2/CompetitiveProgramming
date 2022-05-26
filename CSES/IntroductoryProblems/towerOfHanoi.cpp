#include <iostream>
#include <vector>

#include <math.h>

using namespace std;

void makeLegalMove(int n1, int n2, vector<int>& t1, vector<int>& t2){
	if( (!t1.empty() && t2.empty()) || (!t1.empty() && !t2.empty() && t1.back() < t2.back())  ){
		int tmp = t1.back();
		t1.pop_back();
		t2.push_back(tmp);
		cout << n1 << " " << n2 << endl;
	}
	else{
		int tmp = t2.back();
		t2.pop_back();
		t1.push_back(tmp);
		cout << n2 << " " << n1 << endl;

	}
}


void solveHanoi(vector<int> t1, vector<int> t2, vector<int> t3, int n){
	if(n%2 != 0){
		while(1){

			// Make legal move between 1 and 3
			makeLegalMove(1, 3, t1, t3);
			if(t1.empty() && t2.empty()){ break; }

			// Make legal move between 1 and 2
			makeLegalMove(1, 2, t1, t2);
			if(t1.empty() && t2.empty()){ break; }

			// Make legal move between 2 and 3
			makeLegalMove(2, 3, t2, t3);
			if(t1.empty() && t2.empty()){ break; }

		}

	}
	else{
		while(1){

			// Make legal move between 1 and 2
			makeLegalMove(1, 2, t1, t2);
			if(t1.empty() && t2.empty()){ break; }

			// Make legal move between 1 and 3
			makeLegalMove(1, 3, t1, t3);
			if(t1.empty() && t2.empty()){ break; }

			// Make legal move between 2 and 3
			makeLegalMove(2, 3, t2, t3);
			if(t1.empty() && t2.empty()){ break; }

		}
	}

}

int main(){
	int n; cin >> n;

	vector<int> tower1;
	vector<int> tower2;
	vector<int> tower3;

	for(int i = n; i>0; i--){ tower1.push_back(i); }

	cout << (pow(2,n) - 1) << endl;

	solveHanoi(tower1, tower2, tower3, n);

	return 0;
}
