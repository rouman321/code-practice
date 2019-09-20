/*
The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci
sequence, such that each number is the sum of the two preceding ones, starting from
0 and 1. That is,

F(0) = 0,   F(1) = 1
F(N) = F(N - 1) + F(N - 2), for N > 1.
Given N, calculate F(N).
*/
#include "../LCInput/numInput.h"

class Solution {
public:
    int fib(int N) {
        vector<int> fibTable;
        for(int i = 0;i <= N;i++)
        {
            if(i == 0)
            {
                fibTable.push_back(0);
            }
            else if(i == 1)
            {
                fibTable.push_back(1);
            }
            else
            {
                fibTable.push_back(fibTable[i-1]+fibTable[i-2]);
            }
        }
        return fibTable[N];
    }
};

int main()
{
    int N = numInput("in.txt");
    Solution s;
    cout<<s.fib(N)<<endl;
    return 0;
}
