#include <iostream>

#define N 8

using namespace std;

bool validPlacement(char board[N][N], int row, int col){
	int i, j;
	for(i = 0; i<col; i++){
		if(board[row][i] == 'Q'){ return false; }
	}
	for(i = row, j = col; i>=0 && j>=0; i--, j--){
		if(board[i][j] == 'Q'){ return false; }
	}
	for(i = row, j = col; j>= 0 && i<N; i++, j--){
		if(board[i][j] == 'Q'){ return false; }
	}
	return true;
}

bool queens8Solve(char board[N][N], int col, int& count){

	if(col == N){ count++; return true; }

	bool res = false;
	for(int i = 0; i<N; i++){
		if( validPlacement(board, i, col) && board[i][col] == '.' ){

			// Try to place Quuen
			board[i][col] = 'Q';

			// Recursively place the rest of the queens
			res = queens8Solve(board, col+1, count) || res;

			// Backtrack
			board[i][col] = '.';

		}
	}
	return res;
}

int main(){

	char board[N][N];
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			cin >> board[i][j];
		}
	}
	int count = 0;
	queens8Solve(board, 0, count);
	cout << count << endl;
	return 0;
}
