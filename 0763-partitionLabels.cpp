/*
A string S of lowercase letters is given. We want to partition this string into as
many parts as possible so that each letter appears in at most one part, and return
a list of integers representing the size of these parts.
*/
#include "../LCInput/stringVector.h"
#include <iostream>
#include <map>

class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> ret;
        map<char,int> table;
        for(int i = 0;i < S.size();i++)
        {
            table[S[i]] = i;
        }
        int pos = 0;
        int start = 0;
        for(int i = 0;i < S.size();i++)
        {
            pos = max(table[S[i]],pos);
            if(i == pos)
            {
                ret.push_back(pos-start+1);
                start = i+1;
            }
        }
        return ret;
    }
};

int main()
{
    string S = stringInput("in.txt");
    Solution s;
    vector<int> ans = s.partitionLabels(S);
    cout<<"[";
    for(int i = 0;i < ans.size();i++)
    {
        cout<<ans[i];
        if(i != ans.size()-1)
        {
            cout<<",";
        }
    }
    cout<<"]"<<endl;
    return 0;
}
