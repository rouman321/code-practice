/*
Suppose Andy and Doris want to choose a restaurant for dinner, and they both have a
list of favorite restaurants represented by strings.

You need to help them find out their common interest with the least list index sum.
If there is a choice tie between answers, output all of them with no order
requirement. You could assume there always exists an answer.
*/
#include "../LCInput/stringVector.h"
#include<iostream>
#include<map>

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        map<string,int> m;
        int i;
        for(i = 0;i < list1.size();i++)
        {
            if(m.find(list1[i]) == m.end())
            {
                m[list1[i]] = i;
            }
            else
            {
                m[list1[i]] += i;
            }
        }
        vector<int> index;
        for(i = 0;i < list2.size();i++)
        {
            if(m.find(list2[i]) != m.end())
            {
                index.push_back(i);
            }
        }
        vector<string> ret;
        int s = 2000;
        for(i = 0;i < index.size();i++)
        {
            int j = m[list2[index[i]]];
            if(j+index[i] <= s)
            {
                if(j+index[i] < s)
                {
                    ret.clear();
                    s = j+index[i];
                }
                ret.push_back(list2[index[i]]);
            }
        }
        return ret;
    }
};

int main()
{
    vector<vector<string> > in;
    in = input("in.txt");
    Solution s;
    vector<string> result = s.findRestaurant(in[0],in[1]);
    int i;
    for(i = 0;i < result.size();i++)
    {
        cout<<result[i]<<endl;
    }
    return 0;
}
