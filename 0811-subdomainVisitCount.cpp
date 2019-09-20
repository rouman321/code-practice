/*
A website domain like "discuss.leetcode.com" consists of various subdomains. At the
top level, we have "com", at the next level, we have "leetcode.com", and at the
lowest level, "discuss.leetcode.com". When we visit a domain like "discuss.leetcode.com", we will also visit the parent domains "leetcode.com" and "com" implicitly.

Now, call a "count-paired domain" to be a count (representing the number of visits
this domain received), followed by a space, followed by the address. An example of
a count-paired domain might be "9001 discuss.leetcode.com".

We are given a list cpdomains of count-paired domains. We would like a list of
count-paired domains, (in the same format as the input, and in any order), that
explicitly counts the number of visits to each subdomain.
*/
#include "../LCInput/stringVector.h"
#include <unordered_map>

class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        vector<string> ret;
        unordered_map<string,int> m;
        for(int i = 0;i < cpdomains.size();i++)
        {
            int cnt = 0;
            int pos = 0;
            while(cpdomains[i][pos] != ' ')
            {
                cnt *= 10;
                cnt += cpdomains[i][pos]-'0';
                pos++;
            }
            pos++;
            while(pos < cpdomains[i].size())
            {
                string domain = cpdomains[i].substr(pos,cpdomains[i].size()-pos);
                if(m.count(domain) == 0)
                {
                    m[domain] = 0;
                }
                m[domain] += cnt;
                while(cpdomains[i][pos] != '.'&&pos < cpdomains[i].size()-1)
                {
                    pos++;
                }
                pos++;
            }
        }
        unordered_map<string,int>::iterator it;
        for(it = m.begin();it != m.end();it++)
        {
            string num = "";
            int cnt = it->second;
            while(cnt != 0)
            {
                char ch = cnt%10+'0';
                num = ch+num;
                cnt /= 10;
            }
            ret.push_back(num+" "+it->first);
        }
        return ret;
    }
};

int main()
{
    vector<string> cpdomains = stringVectorInput("in.txt");
    Solution s;
    stringVectorOutput(s.subdomainVisits(cpdomains));
}
