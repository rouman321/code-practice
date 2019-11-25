/*
LeetCode 688. Knight Probability in Chessboard
medium
time:	12ms
space:	10.3mb
*/
class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        if(K==0){
            return 1;
        }
        vector<vector<double>> dp(N,vector<double>(N,0));
        vector<int> dx({-2,-1,1,2,2,1,-1,-2});
        vector<int> dy({1,2,2,1,-1,-2,-2,-1});
        for(int i = 0;i < N;++i){
            for(int j = 0;j < N;++j){
                int cnt = 0;
                for(int m = 0;m < 8;++m){
                    int x = i+dx[m];
                    int y = j+dy[m];
                    if(x<0||x>=N||y<0||y>=N){
                        ++cnt;
                    }
                }
                dp[i][j] = 1-(double)cnt/8;
            }
        }
        for(int t = 0;t < K-1;++t){
            vector<vector<double>> next = dp;
            for(int i = 0;i < N;++i){
                for(int j = 0;j < N;++j){
                    double cnt = 0;
                    for(int m = 0;m < 8;++m){
                        int x = i+dx[m];
                        int y = j+dy[m];
                        if(x>=0&&x<N&&y>=0&&y<N){
                            cnt += dp[x][y];
                        }
                    }
                    next[i][j] = cnt/8;
                }
            }
            dp = next;
        }
        return dp[r][c];
    }
};