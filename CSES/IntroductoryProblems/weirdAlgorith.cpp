#include <iostream>

using namespace std;

int main(){
	unsigned long start;
	cin >> start;
	while(start != 1){
		cout << start << " ";
		start = (start%2 == 0) ? start/2 : (start*3+1);
	}
	cout << start;
	return 0;
}
