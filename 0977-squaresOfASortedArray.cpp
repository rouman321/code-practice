/*
Given an array of integers A sorted in non-decreasing order, return an array of the
squares of each number, also in sorted non-decreasing order.
*/
#include "../LCInput/numInput.h"

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int pos = 0;
        while(A[pos] < 0)
        {
            pos++;
        }
        int left = pos-1;
        vector<int> ret;
        while(pos < A.size()&&left >=0)
        {
            if(A[pos] < -1*A[left])
            {
                ret.push_back(A[pos]*A[pos]);
                pos++;
            }
            else
            {
                ret.push_back(A[left]*A[left]);
                left--;
            }
        }
        while(left >= 0)
        {
            ret.push_back(A[left]*A[left]);
            left--;
        }
        while(pos < A.size())
        {
            ret.push_back(A[pos]*A[pos]);
            pos++;
        }
        return ret;
    }
};

int main()
{
    vector<int> A = signedNumVectorInput("in.txt");
    Solution s;
    numVectorOutput(s.sortedSquares(A));
    return 0;
}
