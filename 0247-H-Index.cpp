/*
Given an array of citations (each citation is a non-negative integer) of a
researcher, write a function to compute the researcher's h-index.

According to the definition of h-index on Wikipedia: "A scientist has index h if h
of his/her N papers have at least h citations each, and the other N − h papers have
 no more than h citations each."
*/

#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int i,j;
        for(i = 0;i < citations.size();i++)
        {
            for(j = 0;j < citations.size()-i-1;j++)
            {
                if(citations[j] < citations[j+1])
                {
                    int tmp = citations[j];
                    citations[j] = citations[j+1];
                    citations[j+1] = tmp;
                }
            }
        }
        for(i = 0;i < citations.size();i++)
        {
            if(citations[i] < i+1)
            {
                break;
            }
        }
        return i;
    }
};

bool isNum(char c)
{
    if(c >= '0'&&c <= '9')
    {
        return true;
    }
    return false;
}

vector<int> readVector(string input)
{
    vector<int> res;
    int i;
    for(i = 0;i< input.size();i++)
    {
        if(isNum(input[i]))
        {
            int tmp = 0;
            while(isNum(input[i]))
            {
                tmp = tmp*10+input[i]-'0';
                i++;
            }
            res.push_back(tmp);
        }
    }
    return res;
}

int main()
{
    ifstream input;
    input.open("in.txt");
    string content;
    getline(input,content);
    vector<int> citations = readVector(content);
    Solution s;
    cout<<s.hIndex(citations)<<endl;
    return 0;
}
