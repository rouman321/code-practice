/*
You're given strings J representing the types of stones that are jewels, and S
representing the stones you have.  Each character in S is a type of stone you have.
You want to know how many of the stones you have are also jewels.

The letters in J are guaranteed distinct, and all characters in J and S are letters.
Letters are case sensitive, so "a" is considered a different type of stone from "A".
*/
#include <vector>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        vector<int> table(52,0);
        int i;
        for(i = 0;i < J.size();i++)
        {
            if(isUpperCase(J[i]))
            {
                table[J[i]-'A'+26]++;
            }
            else
            {
                table[J[i]-'a']++;
            }
        }
        int ret = 0;
        for(i = 0;i < S.size();i++)
        {
            if(isUpperCase(S[i]))
            {
                if(table[S[i]-'A'+26] != 0)
                {
                    ret++;
                }
            }
            else
            {
                if(table[S[i]-'a'] != 0)
                {
                    ret++;
                }
            }
        }
        return ret;
    }

    bool isUpperCase(char c)
    {
        return c >= 'A'&&c <= 'Z';
    }
};

int main()
{
    ifstream f;
    f.open("in.txt");
    string in = "";
    getline(f,in);
    string J = in.substr(1,in.size()-2);
    getline(f,in);
    string S = in.substr(1,in.size()-2);
    Solution s;
    cout<<s.numJewelsInStones(J,S)<<endl;
    return 0;
}
