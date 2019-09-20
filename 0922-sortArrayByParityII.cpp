#include<iostream>
#include<fstream>
#include<vector>
#include<string>
/*
Given an array A of non-negative integers, half of the integers in A are odd, and
half of the integers are even.

Sort the array so that whenever A[i] is odd, i is odd; and whenever A[i] is even,
i is even.

You may return any answer array that satisfies this condition.
*/
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int mark = -1;
        int pos = -1;
        vector<int> posList;
        int i;
        for(i = 0;i < A.size();i++)
        {
            if(A[i]%2 != i%2)
            {
                if(posList.size() == 0)
                {
                    posList.push_back(i);
                    mark = A[i]%2;
                }
                else
                {
                    if(mark != A[i]%2)
                    {
                        int npos = posList[posList.size()-1];
                        int tmp = A[npos];
                        A[npos] = A[i];
                        A[i] = tmp;
                        posList.pop_back();
                    }
                    else
                    {
                        posList.push_back(i);
                    }
                }
            }
        }
        return A;
    }
};

int main()
{
    ifstream input;
    input.open("in.txt");
    string str;
    getline(input,str);
    vector<int> arr;
    int tmp;
    int i;
    for(i = 0;i < str.size();i++)
    {
        if(isNum(str[i]))
        {
            tmp = 0;
            while(isNum(str[i]))
            {
                tmp *= 10;
                tmp += str[i]-'0';
                i++;
            }
            arr.push_back(tmp);
        }
    }
    Solution s;
    cout<<s.sortArrayByParityII(arr)<<endl;
    return 0;
}
