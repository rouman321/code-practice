/*
At a lemonade stand, each lemonade costs $5.

Customers are standing in a queue to buy from you, and order one at a time (in the
order specified by bills).

Each customer will only buy one lemonade and pay with either a $5, $10, or $20 bill.
You must provide the correct change to each customer, so that the net transaction is
that the customer pays $5.

Note that you don't have any change in hand at first.

Return true if and only if you can provide every customer with correct change.
*/
#include "../LCInput/numInput.h"
#include <iostream>

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;
        int i;
        for(i = 0;i < bills.size();i++)
        {
            if(bills[i] == 5)
            {
                five++;
            }
            else if(bills[i] == 10)
            {
                ten++;
                if(five == 0)
                {
                    return false;
                }
                five--;
            }
            else
            {
                if(ten != 0&&five != 0)
                {
                    ten --;
                    five --;
                }
                else if(five >= 3)
                {
                    five -= 3;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};

int main()
{
    vector<vector<int> > in = input("in.txt");
    vector<int> bills = in[0];
    Solution s;
    if(s.lemonadeChange(bills))
    {
        cout<<"True"<<endl;
    }
    else
    {
        cout<<"False"<<endl;
    }
    return 0;
}
