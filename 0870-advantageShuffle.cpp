/*
Given two arrays A and B of equal size, the advantage of A with respect to B is the
number of indices i for which A[i] > B[i].

Return any permutation of A that maximizes its advantage with respect to B.
*/

#include "../LCInput/numInput.h"
#include<iostream>
#include<algorithm>

class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        vector<pair<int,int> > newb;
        vector<pair<int,int> > newa;
        int i;
        for(i = 0;i < B.size();i++)
        {
            newb.push_back({B[i],i});
        }
        sort(newb.begin(),newb.end());
        for(i = 0;i < A.size();i++)
        {
            newa.push_back({A[i],i});
        }
        sort(newa.begin(),newa.end());
        vector<int> ret;
        for(i = 0;i < newb.size();i++)
        {
            ret.push_back(0);
        }
        int left = 0;
        int right = newb.size()-1;
        for(i = ret.size()-1;i >= 0;i--)
        {
            if(newb[i].first < newa[right].first)
            {
                ret[newb[i].second] = newa[right].first;
                right--;
            }
            else
            {
                ret[newb[i].second] = newa[left].first;
                left++;
            }
        }
        return ret;
    }
};

int main()
{
    vector<vector<int> > in = input("in.txt");
    Solution s;
    vector<int> ans = s.advantageCount(in[0],in[1]);
    for(int i = 0;i < ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
