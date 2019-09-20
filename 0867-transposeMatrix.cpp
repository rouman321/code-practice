/*
Given a matrix A, return the transpose of A.

The transpose of a matrix is the matrix flipped over it's main diagonal, switching
the row and column indices of the matrix
*/
#include "../LCInput/numInput.h"

class Solution {
public:
    vector<vector<int> > transpose(vector<vector<int> >& A) {
        int len = A.size();
        int col = A[0].size();
        vector<vector<int> > ret;
        for(int i = 0;i < col;i++)
        {
            vector<int> tmp;
            for(int j = 0;j < len;j++)
            {
                tmp.push_back(A[j][i]);
            }
            ret.push_back(tmp);
        }
        return ret;
    }
};

int main()
{
    vector<vector<int> > A = oneLineVectorVectorInput("in.txt");
    Solution s;
    numVectorVectorOutput(s.transpose(A));
    return 0;
}
