/*
Given two strings s1 and s2, write a function to return true if s2 contains the
permutation of s1. In other words, one of the first string's permutations is the
substring of the second string.
*/
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int mark[26] = {0};
        int check[26] = {0};
        int i;
        for(i = 0;i < s1.size();i++)
        {
            mark[s1[i]-'a']++;
            check[s1[i]-'a']++;
        }
        i = 0;
        while(i < s2.size())
        {
            if(mark[s2[i]-'a'] != 0)
            {
                int j;
                int flag = 0;
                for(j = 0;j < 26;j++)
                {
                    check[j] = mark[j];
                }
                for(j = 0;j < s1.size()&&flag == 0&&j+i < s2.size();j++)
                {
                    if(check[s2[j+i]-'a'] != 0)
                    {
                        check[s2[j+i]-'a']--;
                    }
                    else
                    {
                        //cout<<"1"<<s2[j+i]<<endl;
                        if(mark[s2[j+i]-'a'] == 0)
                        {
                            i = j+i;
                        }
                        flag = 1;
                    }
                }
                if(flag == 0&&j == s1.size())
                {
                    return true;
                }
            }
            i++;
        }
        return false;
    }
};

int main()
{
    fstream input;
    input.open("in.txt");
    string s1;
    getline(input,s1);
    s1 = s1.substr(1,s1.size()-2);
    string s2;
    getline(input,s2);
    s2 = s2.substr(1,s2.size()-2);
    Solution s;
    if(s.checkInclusion(s1,s2))
    {
        cout<<"True"<<endl;
    }
    else
    {
        cout<<"False"<<endl;
    }
    return 0;
}
