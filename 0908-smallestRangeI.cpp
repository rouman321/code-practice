/*
Given an array A of integers, for each integer A[i] we may choose any x with
-K <= x <= K, and add x to A[i].

After this process, we have some array B.

Return the smallest possible difference between the maximum value of B and the
minimum value of B.
*/
#include "../LCInput/numInput.h"

class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        if(A.size() <= 1)
        {
            return 0;
        }
        int minN = A[0];
        int maxN = 0;
        for(int i = 0;i < A.size();i++)
        {
            minN = min(minN,A[i]);
            maxN = max(maxN,A[i]);
        }
        return max(0,maxN-minN-2*K);
    }
};

int main()
{
    ifstream f;
    f.open("in.txt");
    string str;
    getline(f,str);
    vector<int> A;
    for(int i = 1;i < str.size();i++)
    {
        int tmp = 0;
        while(isNum(str[i]))
        {
            tmp *= 10;
            tmp += str[i] - '0';
            i++;
        }
        A.push_back(tmp);
    }
    int K = 0;
    getline(f,str);
    for(int i = 0;i < str.size();i++)
    {
        K *=10;
        K += str[i]-'0';
    }
    Solution s;
    cout<<s.smallestRangeI(A,K)<<endl;
    return 0;
}
