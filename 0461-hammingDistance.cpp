/*
The Hamming distance between two integers is the number of positions at which the
corresponding bits are different.

Given two integers x and y, calculate the Hamming distance.
*/
 #include <iostream>
 #include <fstream>

 using namespace std;

 class Solution {
public:
    int hammingDistance(int x, int y) {
        if(x == y)
        {
            return 0;
        }
        if(x > y)
        {
            int tmp = y;
            y = x;
            x = tmp;
        }
        int cnt = 0;
        while(x > 0)
        {
            if(y%2 != x%2)
            {
                cnt++;
            }
            y /= 2;
            x /= 2;
        }
        while(y > 0)
        {
            if(y%2 == 1)
            {
                cnt++;
            }
            y /= 2;
        }
        return cnt;
    }
};

int main()
{
    ifstream f;
    f.open("in.txt");
    int x;
    f>>x;
    int y;
    f>>y;
    Solution s;
    cout<<s.hammingDistance(x,y)<<endl;
    return 0;
}
