/*
You have a list of words and a pattern, and you want to know which words in words
matches the pattern.

A word matches the pattern if there exists a permutation of letters p so that after
replacing every letter x in the pattern with p(x), we get the desired word.

(Recall that a permutation of letters is a bijection from letters to letters: every
 letter maps to another letter, and no two letters map to the same letter.)

Return a list of the words in words that match the given pattern.

You may return the answer in any order.
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        map<char,vector<int> > table;
        for(int i = 0;i < pattern.size();i++)
        {
            if(table.find(pattern[i]) == table.end())
            {
                vector<int> tmp;
                table[pattern[i]] == tmp;
            }
            table[pattern[i]].push_back(i);
        }
        vector<string> ret;
        for(int i = 0;i < words.size();i++)
        {
            bool isP = true;
            map<char,vector<int> >::iterator it;
            for(it = table.begin();it != table.end();it++)
            {
                char ch = words[i][it->second[0]];
                for(int j = 1;j < it->second.size();j++)
                {
                    if(words[i][it->second[j]] != ch)
                    {
                        isP = false;
                        break;
                    }
                }
            }
            if(isP)
            {
                ret.push_back(words[i]);
            }
        }
        vector<string> ans;
        for(int i = 0;i < ret.size();i++)
        {
            bool isP = true;
            map<char,vector<int> >::iterator it;
            map<char,int> check;
            for(it = table.begin();it != table.end();it++)
            {
                char ch = ret[i][it->second[0]];
                if(check.find(ch) == check.end())
                {
                    check[ch] = 0;
                }
                else
                {
                    isP = false;
                    break;
                }
            }
            if(isP)
            {
                ans.push_back(ret[i]);
            }
        }
        return ans;
    }
};

int main()
{
    ifstream f;
    f.open("in.txt");
    string str;
    vector<string> words;
    getline(f,str);
    for(int i = 0;i < str.size();i++)
    {
        if(str[i] == '"')
        {
            string tmp = "";
            i++;
            while(str[i] != '"')
            {
                tmp += str[i];
                i++;
            }
            words.push_back(tmp);
            tmp.clear();
        }
    }
    string pattern;
    getline(f,pattern);
    pattern = pattern.substr(1,pattern.size()-2);
    Solution s;
    vector<string> ans = s.findAndReplacePattern(words,pattern);
    for(int i = 0;i < ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
