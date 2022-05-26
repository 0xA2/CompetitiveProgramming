#include <iostream>
#include <set>

using namespace std;

void getAllPermutations(string n, unsigned long left, unsigned long right, set<string>& results){
	if( left == right){ results.insert(n); }
	for(unsigned long i = left; i<=right; i++){
		swap(n[left], n[i]);
		getAllPermutations(n, left+1, right, results);
		swap(n[left], n[i]);
	}

}

int main(){
	string n; cin >> n;
	set<string> results;
	getAllPermutations(n, 0, n.length()-1, results);
	cout << results.size() << endl;
	for(auto it = results.begin(); it != results.end(); it++){
		cout << *it << endl;
	}
	return 0;
}
