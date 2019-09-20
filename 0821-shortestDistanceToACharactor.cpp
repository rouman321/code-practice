/*
Given a string S and a character C, return an array of integers representing the
shortest distance from the character C in the string.
*/
#include "../LCInput/stringVector.h"

class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        vector<int> pos;
        for(int i = 0;i < S.size();i++)
        {
            if(S[i] == C)
            {
                pos.push_back(i);
            }
        }
        int last = -1;
        int next = pos[0];
        int posI = 0;
        vector<int> ret;
        for(int i = 0;i < S.size();i++)
        {
            if(last == -1)
            {
                ret.push_back(next-i);
            }
            else if(next == -1)
            {
                ret.push_back(i-last);
            }
            else
            {
                ret.push_back(min(next-i,i-last));
            }
            if(S[i] == C)
            {
                posI++;
                last = next;
                if(posI < pos.size())
                {
                    next = pos[posI];
                }
                else
                {
                    next = -1;
                }
            }
        }
        return ret;
    }
};

int main()
{
    ifstream f;
    f.open("in.txt");
    string str = "";
    getline(f,str);
    string S = str.substr(1,str.size()-2);
    char C;
    getline(f,str);
    C = str[1];
    Solution s;
    cout<<"[";
    vector<int> ans = s.shortestToChar(S,C);
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
