/*
Every email consists of a local name and a domain name, separated by the @ sign.

For example, in alice@leetcode.com, alice is the local name, and leetcode.com is
the domain name.

Besides lowercase letters, these emails may contain '.'s or '+'s.

If you add periods ('.') between some characters in the local name part of an email
address, mail sent there will be forwarded to the same address without dots in the
local name.  For example, "alice.z@leetcode.com" and "alicez@leetcode.com" forward
to the same email address.  (Note that this rule does not apply for domain names.)

If you add a plus ('+') in the local name, everything after the first plus sign
will be ignored. This allows certain emails to be filtered, for example
m.y+name@email.com will be forwarded to my@email.com.  (Again, this rule does not
apply for domain names.)

It is possible to use both of these rules at the same time.

Given a list of emails, we send one email to each address in the list.  How many
different addresses actually receive mails?
*/
#include<iostream>
#include"../LCInput/stringVector.h"

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        int cnt = 0;
        vector<string> uniqueEmails;
        string trueaddr = "";
        for(int i = 0;i < emails.size();i++)
        {
            for(int j = 0;j < emails[i].size();j++)
            {
                if(emails[i][j] != '.'&&emails[i][j] != '+')
                {
                    trueaddr += emails[i][j];
                }
                else if(emails[i][j] == '+')
                {
                    while(emails[i][j] != '@')
                    {
                        j++;
                    }
                    trueaddr += emails[i].substr(j,emails[i].size()-j);
                }
            }
            bool flag = true;
            for(int j = 0;j < uniqueEmails.size();j++)
            {
                if(uniqueEmails[j] == trueaddr)
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
            {
                cnt++;
                uniqueEmails.push_back(trueaddr);
            }
            trueaddr = "";
        }
        return cnt;
    }
};

int main()
{
    vector<string> emails = stringVectorInput("in.txt");
    Solution s;
    cout<<s.numUniqueEmails(emails)<<endl;
    return 0;
}
