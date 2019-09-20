/*
Implement function ToLowerCase() that has a string parameter str, and returns the
same string in lowercase.
*/
#include "../LCInput/stringVector.h"
#include <iostream>

class Solution {
public:
    string toLowerCase(string str) {
        for(int i = 0;i < str.size();i++)
        {
            if(str[i] >= 'A'&&str[i] <= 'Z')
            {
                str[i] = str[i]+32;
            }
        }
        return str;
    }
};

int main()
{
    string str = stringInput("in.txt");
    str = str.substr(1,str.size()-2);
    Solution s;
    cout<<s.toLowerCase(str)<<endl;
    return 0;
}
