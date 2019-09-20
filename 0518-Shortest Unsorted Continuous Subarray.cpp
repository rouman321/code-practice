/*
Given an integer array, you need to find one continuous subarray that if you only
sort this subarray in ascending order, then the whole array will be sorted in
ascending order, too.

You need to find the shortest such subarray and output its length.
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int i = 1;
        int left = 0;
        while(i < nums.size()&&nums[i] >= nums[i-1])
        {
            i++;
        }
        left = i-1;
        if(left == nums.size()-1)
        {
            return 0;
        }
        int right = nums.size()-1;
        i = right-1;
        while(i >= 0&& nums[i] <= nums[i+1])
        {
            i--;
        }
        right = i+1;
        int few = -1;
        int much = -1;
        for(i = left;i <= right;i++)
        {
            if(few > nums[i]||few == -1)
            {
                few = nums[i];
            }
            if(much < nums[i]||much == -1)
            {
                much = nums[i];
            }
        }
        while(left >= 0&&nums[left] > few)
        {
            left--;
        }
        while(right < nums.size()&&nums[right] < much)
        {
            right++;
        }
        return right-left-1;
    }
};

bool isNum(char a)
{
    if(a >= '0' && a <= '9')
    {
        return true;
    }
    return false;
}

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
    cout<<s.findUnsortedSubarray(arr)<<endl;
    return 0;
}
