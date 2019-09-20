/*
There is a strange printer with the following two special requirements:

1.The printer can only print a sequence of the same character each time.
2.At each turn, the printer can print new characters starting from and ending at
any places, and will cover the original existing characters.

Given a string consists of lower English letters only, your job is to count the minimum number of turns the printer needed in order to print it.
*/
#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    int dpCnt(vector<vector<int> > &dp,string s,int i,int j)
    {
        if(i == j)
        {
            return 1;
        }
        if(i > j)
        {
            return 0;
        }
        if(dp[i][j] != 0)
        {
            return dp[i][j];
        }
        dp[i][j] = dpCnt(dp,s,i+1,j)+1;
        int k;
        for(k = i+1;k <= j;k++)
        {
            if(s[i] == s[k])
            {
                dp[i][j] = min(dp[i][j],dpCnt(dp,s,i,k-1)+dpCnt(dp,s,k+1,j));
            }
        }
        return dp[i][j];
    }

    int strangePrinter(string s) {
        if(s.size() == 0)
            return 0;
        string news = "";
        news += s[0];
        int i;
        for(i = 1;i < s.size();i++)
        {
            if(s[i] != s[i-1])
            {
                news += s[i];
            }
        }
        vector<vector<int> > dp(news.size(),vector<int>(news.size(),0));
        return dpCnt(dp,news,0,news.size()-1);
    }
};

int main()
{
    ifstream input;
    input.open("in.txt");
    string s;
    getline(input,s);
    s = s.substr(1,s.size()-2);
    Solution method;
    cout<<method.strangePrinter(s)<<endl;
    return 0;
}
