#include <iostream>

#define N 7
#define MAX N*N

using namespace std;

bool grid[N][N];
int validPaths = 0;
int steps = 0;

void dfs(int row, int col, string path, bool up, bool down, bool left, bool right){

	// Optimizations

	// If we reach any of the sides of the grid and can turn to either side we stop searching
	if( col == (N-1) && 0 < row && row < (N-1) && !grid[row-1][col] && !grid[row+1][col] ){ return; }
	if( row == (N-1) && 0 < col && col < (N-1) && !grid[row][col-1] && !grid[row][col+1] ){ return; }
	if( col == 0 && 0 < row && row < (N-1) && !grid[row-1][col] && !grid[row+1][col] ){ return; }
	if( row == 0 && 0 < col && col < (N-1) && !grid[row][col-1] && !grid[row][col+1] ){ return; }

	// If we reach any point in the middle of the grid where we cannot keep going forward but can turn to either we stop searching
	if( 0 < col && col < (N-1) && 0 < row && row < (N-1) && grid[row-1][col] && grid[row+1][col] && !grid[row][col-1] && !grid[row][col+1]){ return; }
	if( 0 < col && col < (N-1) && 0 < row && row < (N-1) && grid[row][col-1] && grid[row][col+1] && !grid[row-1][col] && !grid[row+1][col]){ return; }

	// Base Cases
	if(grid[row][col]){ return; }
	if(row == N-1 && col == 0){
		if(steps == (N*N)-1){ validPaths++; }
		return;
	}

	// Mark current node as visited
	grid[row][col] = true;

	// If the step the next step to be taken is known other paths will be ignored
	if(path[steps] != '?'){
		if(path[steps] == 'U'){ down = false; left = false; right = false; }
		if(path[steps] == 'D'){ up = false; left = false; right = false; }
		if(path[steps] == 'L'){ up = false; down = false; right = false; }
		if(path[steps] == 'R'){ up = false; down = false; left = false; }
	}

	// Recursive Step
	if(up && row > 0 && !grid[row-1][col]){
		// Up
		steps++;
		dfs(row-1, col, path, true, true, true, true);
		steps--;
	}
	if(down && row < (N-1) && !grid[row+1][col]){
		// Down
		steps++;
		dfs(row+1, col, path, true, true, true, true);
		steps--;
	}
	if(right && col < (N-1) && !grid[row][col+1] ){
		// Right
		steps++;
		dfs(row, col+1, path, true, true, true, true);
		steps--;
	}
	if(left && col > 0 && !grid[row][col-1] ){
		// Left
		steps++;
		dfs(row, col-1, path, true, true, true, true);
		steps--;
	}

	// Backtrack
	grid[row][col] = false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string path; cin >> path;
	dfs(0,0, path, true, true, true, true);
	cout << validPaths << endl;
	return 0;
}
