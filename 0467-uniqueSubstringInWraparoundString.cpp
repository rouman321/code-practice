/*
Consider the string s to be the infinite wraparound string of
"abcdefghijklmnopqrstuvwxyz",
so s will look like this:
"...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd....".

Now we have another string p. Your job is to find out how many unique non-empty
substrings of p are present in s. In particular, your input is the string p and you
need to output the number of different non-empty substrings of p in the string s.

Note: p consists of only lowercase English letters and the size of p might be over
10000.
*/
#include "../LCInput/stringVector.h"
#include<iostream>

class Solution{
public:
    int findSubstringInWraproundString(string p)
    {
        int len = 0;
        int cnt = 0;
        int forLen = 0;
        int i;
        int mark[26] = {0};
        for(i = 0;i < p.size();i++)
        {
            if(i == 0)
            {
                cnt = 1;
            }
            else if((p[i] == p[i-1]+1)||(p[i] == 'a'&&p[i-1] == 'z'))
            {
                cnt++;
            }
            else
            {
                cnt = 1;
            }
            mark[p[i]-'a'] = max(mark[p[i]-'a'],cnt);
        }
        for(i = 0;i < 26;i++)
        {
            len += mark[i];
        }
        return len;
    }
};

int main()
{
    vector<vector<string> > pList;
    pList = input("in.txt");
    Solution s;
    cout<<s.findSubstringInWraproundString(pList[0][0])<<endl;
    return 0;
}
