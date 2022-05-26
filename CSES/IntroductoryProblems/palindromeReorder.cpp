#include <iostream>
#include <deque>

using namespace std;

int main(){
	string s; cin >> s;
	int map[26] = { 0 };
	for(unsigned long i = 0; i<s.length(); i++){
		map[int(s[i])-65] += 1;
	}

	int flag = -1;
	deque<char> solution;
	for(int i = 0; i<26; i++){
		if(map[i]%2 != 0){
			if(flag >= 0){cout << "NO SOLUTION" << endl; return 0;}
			flag = i;
			for(int j = 0; j<map[i]; j++){
				solution.push_back(char(i+65));
			}
		}
	}

	for(int i = 0; i<26; i++){
		if(i != flag){
			for(int j = 0; j<map[i]/2; j++){
				solution.push_front(char(i+65));
				solution.push_back(char(i+65));

			}
		}
	}


	for(unsigned long i = 0; i < solution.size(); i++){
		cout << solution[i];
	}
	cout << endl;
	return 0;
}
