class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                int rc=0, cc = 0;
                char c = board[i][j];
                if(c=='.') continue;
                for(int k=0; k<9; k++){
                    if(board[i][k]==c){
                        rc++;
                    }
                    if(board[k][j]==c) cc++;
                }
                if(rc>1 || cc>1) return false;
                pair<int,int> blockno = {i/3,j/3};
                int bc=0;
                for(int s=blockno.first*3; s<blockno.first*3+3; s++){
                    for(int m=blockno.second*3; m<blockno.second*3+3; m++){
                        if(board[s][m]==c) bc++;
                    }
                }
                if(bc>1) return false;
            }
        }
        return true;
        
    }
};
