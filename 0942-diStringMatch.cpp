/*
Given a string S that only contains "I" (increase) or "D" (decrease), let
N = S.length.

Return any permutation A of [0, 1, ..., N] such that for all i = 0, ..., N-1:

If S[i] == "I", then A[i] < A[i+1]
If S[i] == "D", then A[i] > A[i+1]
*/
#include "../LCInput/stringVector.h"
#include <iostream>

class Solution {
public:
    vector<int> diStringMatch(string S) {
        int I = 0;
        int D = 0;
        for(int i = 0;i < S.size();i++)
        {
            if(S[i] == 'I')
            {
                I++;
            }
            else if(S[i] == 'D')
            {
                D++;
            }
        }
        vector<int> ret(S.size()+1,0);
        I = D+1;
        ret[0] = D;
        D--;
        for(int i = 0;i < S.size();i++)
        {
            if(S[i] == 'D')
            {
                ret[i+1] = D;
                D--;
            }
            else if(S[i] == 'I')
            {
                ret[i+1] = I;
                I++;
            }
        }
        return ret;
    }
};

int main()
{
    string S = stringInput("in.txt");
    Solution s;
    vector<int> ans = s.diStringMatch(S);
    for(int i = 0;i < ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
