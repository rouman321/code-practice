/*
Given an integer array with even length, where different numbers in this array
represent different kinds of candies. Each number means one candy of the
corresponding kind. You need to distribute these candies equally in number to
brother and sister. Return the maximum number of kinds of candies the sister could
gain.
*/
#include<iostream>
#include"../LCInput/numInput.h"
#include<map>

class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        int limit = candies.size()/2;
        map<int,bool> check;
        int cnt = 0;
        for(int i = 0;i < candies.size();i++)
        {
            if(check.find(candies[i]) == check.end())
            {
                check[candies[i]] = true;
                cnt ++;
            }
            if(cnt == limit)
            {
                return limit;
            }
        }
        return min(cnt,limit);
    }
};

int main()
{
    vector<int> candies = numVectorInput("in.txt");
    Solution s;
    cout<<s.distributeCandies(candies)<<endl;
    return 0;
}
