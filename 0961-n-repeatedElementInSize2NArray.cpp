/*
In a array A of size 2N, there are N+1 unique elements, and exactly one of these
elements is repeated N times.

Return the element repeated N times
*/
#include<iostream>
#include"../LCInput/numInput.h"

class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        vector<bool> mark(10000,false);
        for(int i = 0;i < A.size();i++)
        {
            if(mark[A[i]])
            {
                return A[i];
            }
            else
            {
                mark[A[i]] = true;
            }
        }
    }
};

int main()
{
    vector<int> A = numVectorInput("in.txt");
    Solution s;
    cout<<s.repeatedNTimes(A)<<endl;
    return 0;
}
