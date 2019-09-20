/*
We are given an array A of N lowercase letter strings, all of the same length.

Now, we may choose any set of deletion indices, and for each string, we delete all
the characters in those indices.

For example, if we have an array A = ["abcdef","uvwxyz"] and deletion indices
{0, 2, 3}, then the final array after deletions is ["bef", "vyz"], and the
remaining columns of A are ["b","v"], ["e","y"], and ["f","z"].  (Formally, the
c-th column is [A[0][c], A[1][c], ..., A[A.length-1][c]].)

Suppose we chose a set of deletion indices D such that after deletions, each
remaining column in A is in non-decreasing sorted order.

Return the minimum possible value of D.length.
*/
#include "../LCInput/stringVector.h"
#include <iostream>

class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        if(A.size() == 0)
        {
            return 0;
        }
        int cnt = 0;
        for(int i = 0;i < A[0].size();i++)
        {
            for(int j = 0;j < A.size()-1;j++)
            {
                if(A[j][i] > A[j+1][i])
                {
                    cnt++;
                    break;
                }
            }
        }
        return cnt;
    }
};

int main()
{
    vector<string> A = stringVectorInput("in.txt");
    Solution s;
    cout<<s.minDeletionSize(A)<<endl;
    return 0;
}
