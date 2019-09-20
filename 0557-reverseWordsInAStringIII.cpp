/*
Given a string, you need to reverse the order of characters in each word within a
sentence while still preserving whitespace and initial word order
*/
#include "../LCInput/stringVector.h"

class Solution {
public:
    string reverseWords(string s) {
        string ret = "";
        string tmp = "";
        for(int i = 0;i < s.size();i++)
        {
            if(s[i] != ' '&& i!=s.size()-1)
            {
                tmp += s[i];
            }
            else
            {
                if(i == s.size()-1)
                {
                    tmp += s[i];
                }
                for(int j = tmp.size()-1;j >= 0;j--)
                {
                    ret += tmp[j];
                }
                if(i != s.size()-1)
                {
                    ret += " ";
                }
                tmp = "";
            }
        }
        return ret;
    }
};

int main()
{
    string s = stringInput("in.txt");
    Solution ss;
    cout<<ss.reverseWords(s)<<endl;
    return 0;
}
