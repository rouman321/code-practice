/*
Given two strings representing two complex numbers.

You need to return a string representing their multiplication. Note i2 = -1
according to the definition.
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int reala = 0;
        int realb = 0;
        int ia = 0;
        int ib = 0;
        int tmp = 0;
        int i = 0;
        bool flag = false;
        if(a[i] == '-')
        {
            flag = true;
            i++;
        }
        while(a[i] != '+')
        {
            tmp *= 10;
            tmp += a[i]-'0';
            i++;
        }
        if(flag)
        {
            tmp *= -1;
            flag = false;
        }
        reala = tmp;
        i++;
        tmp = 0;
        if(a[i] == '-')
        {
            flag = true;
            i++;
        }
        while(a[i] != 'i')
        {
            tmp *= 10;
            tmp += a[i]-'0';
            i++;
        }
        if(flag)
        {
            tmp *= -1;
            flag = false;
        }
        ia = tmp;
        i = 0;
        tmp = 0;
        if(b[i] == '-')
        {
            flag = true;
            i++;
        }
        while(b[i] != '+')
        {
            tmp *= 10;
            tmp += b[i]-'0';
            i++;
        }
        if(flag)
        {
            flag = false;
            tmp *= -1;
        }
        realb = tmp;
        tmp = 0;
        i++;
        if(b[i] == '-')
        {
            flag = true;
            i++;
        }
        while(b[i] != 'i')
        {
            tmp *= 10;
            tmp += b[i]-'0';
            i++;
        }
        if(flag)
        {
            tmp *= -1;
        }
        ib = tmp;
        string ret = "";
        int realr = reala*realb-ia*ib;
        int ir = reala*ib+realb*ia;
        if(realr < 0)
        {
            ret += "-";
        }
        string t  = "";
        realr = abs(realr);
        t += realr%10+'0';
        realr /= 10;
        while(realr != 0)
        {
            char ch = realr%10+'0';
            t = ch+t;
            realr /= 10;
        }
        ret += t;
        ret += "+";
        if(ir < 0)
        {
            ret += "-";
        }
        ir = abs(ir);
        t = "";
        t += ir%10+'0';
        ir /= 10;
        while(ir != 0)
        {
            char ch = ir%10+'0';
            t = ch+t;
            ir /= 10;
        }
        ret += t+"i";
        return ret;
    }
};

int main()
{
    ifstream f;
    f.open("in.txt");
    string s;
    getline(f,s);
    string a = s.substr(1,s.size()-2);
    getline(f,s);
    string b = s.substr(1,s.size()-2);
    Solution ss;
    cout<<ss.complexNumberMultiply(a,b)<<endl;
    return 0;
}
