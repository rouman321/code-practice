/*
Given a string S of '(' and ')' parentheses, we add the minimum number of
parentheses ( '(' or ')', and in any positions ) so that the resulting parentheses
string is valid.

Formally, a parentheses string is valid if and only if:

It is the empty string, or
It can be written as AB (A concatenated with B), where A and B are valid strings,
or
It can be written as (A), where A is a valid string.
Given a parentheses string, return the minimum number of parentheses we must add to
make the resulting string valid.
*/
#include "../LCInput/stringVector.h"
#include <iostream>

class Solution {
public:
    int minAddToMakeValid(string S) {
        int cur = 0;
        int cnt = 0;
        vector<bool> mark(S.size(),true);
        for(cur = 0;cur < S.size();cur++)
        {
            if(mark[cur])
            {
                if(S[cur] == '(')
                {
                    mark[cur] = false;
                    int i = cur+1;
                    while(i < S.size())
                    {
                        if(mark[i]&&S[i] == ')')
                        {
                            mark[i] = false;
                            break;
                        }
                        i++;
                    }
                    if(i == S.size())
                    {
                        cnt++;
                    }
                }
                else
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

int main()
{
    string S = stringInput("in.txt");
    Solution s;
    cout<<s.minAddToMakeValid(S)<<endl;
    return 0;
}
