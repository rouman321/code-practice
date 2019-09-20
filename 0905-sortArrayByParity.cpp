/*
Given an array A of non-negative integers, return an array consisting of all the
even elements of A, followed by all the odd elements of A.

You may return any answer array that satisfies this condition.
*/
#include "../LCInput/numInput.h"
#include <iostream>

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> odd;
        vector<int> even;
        for(int i = 0;i < A.size();i++)
        {
            if(A[i]%2 == 0)
            {
                even.push_back(A[i]);
            }
            else
            {
                odd.push_back(A[i]);
            }
        }
        for(int i = 0;i < A.size();i++)
        {
            if(i < even.size())
            {
                A[i] = even[i];
            }
            else
            {
                A[i] = odd[i-even.size()];
            }
        }
        return A;
    }
};

int main()
{
    vector<int> A = numVectorInput("in.txt");
    Solution s;
    vector<int> ans = s.sortArrayByParity(A);
    for(int i = 0;i < ans.size();i++)
    {
        cout<<ans[i]<<",";
    }
    cout<<endl;
    return 0;
}
