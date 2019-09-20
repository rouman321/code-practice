/*
Given a word, you need to judge whether the usage of capitals in it is right or not


We define the usage of capitals in a word to be right when one of the following
cases holds:

All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital if it has more than one letter, like
"Google".
Otherwise, we define that this word doesn't use capitals in a right way.
*/
#include<iostream>
#include"../LCInput/stringVector.h"

class Solution {
public:
    bool isCap(char c)
    {
        return c>='A' && c<='Z';
    }
    bool detectCapitalUse(string word) {
        int i;
        int state = 0;
        for(i = 0;i < word.size();i++)
        {
            if(isCap(word[i]))
            {
                if(state != 0)
                {
                    return false;
                }
            }
            else
            {
                if(i == 0)
                {
                    state = 1;
                }
                else if(i == 1&&state == 0)
                {
                    state = 2;
                }
                else if(state == 0)
                {
                    return false;
                }
            }
        }
        return true;
    }
};

int main()
{
    vector<vector<string> > in;
    in = input("in.txt");
    Solution s;
    if(s.detectCapitalUse(in[0][0]))
    {
        cout<<"true"<<endl;
    }
    else
    {
        cout<<"false"<<endl;
    }
}
