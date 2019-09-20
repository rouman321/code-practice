/*
Let's call an array A a mountain if the following properties hold:

A.length >= 3
There exists some 0 < i < A.length - 1 such that A[0] < A[1] < ... A[i-1] < A[i] >
A[i+1] > ... > A[A.length - 1]
Given an array that is definitely a mountain, return any i such that A[0] < A[1] <
... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1].
*/
#include "../LCInput/numInput.h"

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int left = 0;
        int right = A.size();
        int mid = (left+right)/2;
        while(left < right-1)
        {
            mid = (left+right)/2;
            if(A[mid] > A[mid+1])
            {
                right = mid;
            }
            else
            {
                left = mid;
            }
        }
        int ret;
        if(A[left] > A[right])
        {
            ret = left;
        }
        else
        {
            ret = right;
        }
        return ret;
    }
};

int main()
{
    vector<int> A = numVectorInput("in.txt");
    Solution s;
    cout<<s.peakIndexInMountainArray(A)<<endl;
    return 0;
}
