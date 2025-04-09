class Solution {
	vector<vector<int>>grid;
	int n;
public:
	Solution(int n) {
		// Initialize your data structure here.
		grid = vector<vector<int>>(n, vector<int>(n, 0));
		this->n = n;
	}

	int move(int row, int col, int player) {
		// Write your code here.
		grid[row][col] = player;
		bool flag = true;
		for(int j=0; j<n; j++){
			if(grid[row][j] != player){
				flag = false;
				break;
			}
		}
		if(flag) return player;
		flag = true;
		for(int j=0; j<n; j++){
			if(grid[j][col] != player){
				flag = false;
				break;
			}
		}
		if(flag) return player;
		flag = true;
		// diagonally 
		if((row == col) || row+col == n-1){
			if(row == col){
			for(int i=0; i<n; i++){
				if(grid[i][i] != player){
					flag = false;
					break;
				}
			}
			if(flag) return player;
			flag = true;
			}
			
			for(int j=0; j<n; j++){
				if(grid[j][n-1-j] != player){
					flag = false;
					break;
				}
			}
			if(flag) return player;
			// flag = true;
		}
		// cout<<flag<<endl;
		return 0;
	}
};
