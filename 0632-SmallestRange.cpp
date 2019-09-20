/*
You have k lists of sorted integers in ascending order. Find the smallest range
that includes at least one number from each of the k lists.

We define the range [a,b] is smaller than range [c,d] if b-a < d-c or a < c if
b-a == d-c.
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>//for sort()

using namespace std;

class Solution {
public:
    vector<int> smallestRange(vector<vector<int> >& nums) {
        vector<pair<int,int> > all;
        vector<int> inc;
        vector<int> res;
        int i,j;
        for(i = 0;i < nums.size();i++)
        {
            for(j = 0;j < nums[i].size();j++)
            {
                all.push_back({nums[i][j],i});
            }
            inc.push_back(0);
        }
        sort(all.begin(),all.end());
        int len = all[all.size()-1].first-all[0].first+1;
        int left = 0;
        int right;
        int cnt = 0;
        for(right = 0;right < all.size();right++)
        {
            if(inc[all[right].second] == 0)
            {
                cnt++;
            }
            inc[all[right].second]++;
            while(cnt == nums.size())
            {
                if(all[right].first-all[left].first < len)
                {
                    len = all[right].first-all[left].first;
                    res.clear();
                    res.push_back(all[left].first);
                    res.push_back(all[right].first);
                }
                inc[all[left].second]--;
                if(inc[all[left].second] == 0)
                {
                    cnt--;
                }
                left++;
            }
        }
        return res;
    }
};

void print(vector<int> v)
{
    for(int i = 0;i < v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

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
    vector<vector<int> > arr;
    vector<int> t;
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
            t.push_back(tmp);
        }
        if(str[i] == ']'&&t.size() != 0)
        {
            arr.push_back(t);
            t.clear();
        }
    }
    Solution s;
    vector<int> a = s.smallestRange(arr);
    print(a);
    return 0;
}

