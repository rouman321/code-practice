/*
LeetCode 289. Game of Life
medium
time:	62.09%
space:	100%
*/
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        for(int i = 0;i < board.size();i++){
            for(int j = 0;j < board[i].size();j++){
                int cnt = 0;
                for(int x = i-1;x <= i+1;x++){
                    if(x<0||x>=board.size()){
                        continue;
                    }
                    for(int y = j-1;y <= j+1;y++){
                        if(y<0||y>=board[x].size()||(y==j&&x==i)){
                            continue;
                        }
                        if(board[x][y]==1||board[x][y]==2){
                            cnt++;
                        }
                    }
                }
                if(cnt<2||cnt>3){
                    if(board[i][j]==1){
                        board[i][j] = 2;// now alive, should die in next state
                    }
                }
                else{
                    if(cnt==3&&board[i][j]==0){
                        board[i][j] = 3;// now dead, should come to live in next state
                    }
                }
            }
        }
        for(int i = 0;i < board.size();i++){
            for(int j = 0;j < board[i].size();j++){
                if(board[i][j]==2){
                    board[i][j] = 0;
                }
                else if(board[i][j]==3){
                    board[i][j] = 1;
                }
            }
        }
    }
};