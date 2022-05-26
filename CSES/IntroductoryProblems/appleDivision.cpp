#include <iostream>

using namespace std;

long long minDiff(long long array[], int n, long long curSum, long long totalSum){
	if(n == 0){ return abs((totalSum - curSum)-curSum);  }
	return min( minDiff(array, n-1, curSum+array[n-1], totalSum), minDiff(array, n-1, curSum, totalSum) );
}

int main(){
	int n; cin >> n;

	long long readNums[n];
	long long sum = 0;
	for(int i = 0; i<n; i++){
		cin >> readNums[i];
		sum += readNums[i];
	}
	cout << minDiff(readNums, n, 0, sum) << endl;
	return 0;
}
