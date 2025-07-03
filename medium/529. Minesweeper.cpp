class Solution {
private: 
    void dfs(int i, int j, int n, int m, vector<vector<char>>& board){
        int cnt = 0;
        for(int k=-1; k<=1; k++){
            for(int l=-1; l<=1; l++){
                if(l==0 && k==0) continue;
                int nr = i+k;
                int nc = j+l;
                if(nr>=0 && nr<n && nc>=0 && nc<m && board[nr][nc]=='M'){
                    cnt++;
                }
            }
        }
        if(cnt==0){
            if(board[i][j]=='E'){
                board[i][j] = 'B'; 
                for(int k=-1; k<=1; k++){
                    for(int l=-1; l<=1; l++){
                        if(l==0 && k==0) continue;
                        int nr = i+k;
                        int nc = j+l;
                        if(nr>=0 && nr<n && nc>=0 && nc<m){
                            dfs(nr, nc, n, m, board);
                        }
                    }
                }
            }
        }
        else{
            board[i][j]=(cnt+'0');
        }
    }
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int n = board.size();
        int m = board[0].size(); 
        if(board[click[0]][click[1]] == 'M'){
            board[click[0]][click[1]] = 'X';
            return board;
        }
        dfs(click[0], click[1], n, m, board);
        return board;
    }
};
