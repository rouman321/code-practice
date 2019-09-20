/*
We have a two dimensional matrix A where each value is 0 or 1.

A move consists of choosing any row or column, and toggling each value in that row
or column: changing all 0s to 1s, and all 1s to 0s.

After making any number of moves, every row of this matrix is interpreted as a
binary number, and the score of the matrix is the sum of these numbers.

Return the highest possible score.
*/
#include "../LCInput/numInput.h"

class Solution {
public:
    int matrixScore(vector<vector<int> >& A) {
        int numCnt = A.size();
        if(numCnt == 0)
        {
            return 0;
        }
        int len = A[0].size();
        for(int i = 0;i < numCnt;i++)
        {
            if(A[i][0] == 0)
            {
                for(int j = 0;j < len;j++)
                {
                    A[i][j] = (A[i][j]+1)%2;
                }
            }
        }
        for(int j = 1;j < len;j++)
        {
            int zero = 0;
            for(int i = 0;i < numCnt;i++)
            {
                if(A[i][j] == 0)
                {
                    zero++;
                }
            }
            if(zero > numCnt-zero)
            {
                for(int i = 0;i < numCnt;i++)
                {
                    A[i][j] = (A[i][j]+1)%2;
                }
            }
        }
        int ret = 0;
        for(int i = 0;i < numCnt;i++)
        {
            int tmp = 1;
            for(int j = len-1;j >= 0;j--)
            {
                if(A[i][j] == 1)
                {
                    ret += tmp;
                }
                tmp *= 2;
            }
        }
        return ret;
    }
};

int main()
{
    vector<vector<int> > A = oneLineVectorVectorInput("in.txt");
    Solution s;
    cout<<s.matrixScore(A)<<endl;
    return 0;
}
