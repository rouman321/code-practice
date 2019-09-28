/*
LeetCode 48. Rotate Image
medium
time:	100%
space:	97.65%
*/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int half = n/2;
		for(int i = 0; i < half; ++i){
			for(int j = 0; j < half; ++j){
				int x = i;
                int y = j;
                int c = 4;
				int pre = matrix[x][y];
                int cur;
				while(c > 0){
                    // cout<<x<<" "<<y<<endl;
					cur = matrix[y][n - 1 - x];
					matrix[y][n - 1 - x] = pre;
					pre = cur;
                    int tmp = n-1-x;
					x = y;
					y = tmp;
                    c--;
				}
			}
		}
        if(n%2!=0){
            for(int i = 0;i < half;i++){
                int x = i;
                int y = half;
                int c = 4;
                int pre = matrix[x][y];
                int cur;
                while(c > 0){
                    // cout<<x<<" "<<y<<endl;
                    cur = matrix[y][n - 1 - x];
                    matrix[y][n - 1 - x] = pre;
                    pre = cur;
                    int tmp = n-1-x;
                    x = y;
                    y = tmp;
                    c--;
                }
            }
        }
    }
};