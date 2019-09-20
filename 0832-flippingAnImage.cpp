/*
Given a binary matrix A, we want to flip the image horizontally, then invert it,
and return the resulting image.

To flip an image horizontally means that each row of the image is reversed.  For
example, flipping [1, 1, 0] horizontally results in [0, 1, 1].

To invert an image means that each 0 is replaced by 1, and each 1 is replaced by 0.
For example, inverting [0, 1, 1] results in [1, 0, 0].
*/
#include "../LCInput/numInput.h"

class Solution {
public:
    vector<vector<int> > flipAndInvertImage(vector<vector<int> >& A) {
        vector<vector<int> > ret;
        vector<int> tmp;
        for(int i = 0;i < A.size();i++)
        {
            for(int j = A[i].size()-1;j >= 0;j--)
            {
                tmp.push_back((A[i][j]+1)%2);
            }
            ret.push_back(tmp);
            tmp.clear();
        }
        return ret;
    }
};

int main()
{
    vector<vector<int> > A = oneLineVectorVectorInput("in.txt");
    Solution s;
    numVectorVectorOutput(s.flipAndInvertImage(A));
    return 0;
}
