/*
In a 2 dimensional array grid, each value grid[i][j] represents the height of a
building located there. We are allowed to increase the height of any number of
buildings, by any amount (the amounts can be different for different buildings).
Height 0 is considered to be a building as well.

At the end, the "skyline" when viewed from all four directions of the grid, i.e.
top, bottom, left, and right, must be the same as the skyline of the original grid.
 A city's skyline is the outer contour of the rectangles formed by all the
 buildings when viewed from a distance. See the following example.

What is the maximum total sum that the height of the buildings can be increased?
*/
#include<iostream>
#include"../LCInput/numInput.h"

using namespace std;

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int> >& grid) {
        int ret = 0;
        if(grid.size() == 0)
        {
            return ret;
        }
        if(grid[0].size() == 0)
        {
            return ret;
        }
        vector<int> x(grid.size(),0);
        vector<int> y(grid.size(),0);
        int i,j;
        for(i = 0;i < grid.size();i++)
        {
            for(j = 0;j < grid[i].size();j++)
            {
                if(grid[i][j] > x[i])
                {
                    x[i] = grid[i][j];
                }
                if(grid[i][j] > y[j])
                {
                    y[j] = grid[i][j];
                }
            }
        }
        for(i = 0;i < grid.size();i++)
        {
            for(j = 0;j < grid.size();j++)
            {
                ret += min(x[i],y[j])-grid[i][j];
            }
        }
        return ret;
    }
};

int main()
{
    ifstream f;
    f.open("in.txt");
    string str;
    getline(f,str);
    vector<int> tmp;
    vector<vector<int> > grid;
    int i;
    for(i = 1;i < str.size();i++)
    {
        if(str[i] == '[')
        {
            i++;
            int num = 0;
            while(str[i] != ']')
            {
                if(isNum(str[i]))
                {
                    num *= 10;
                    num += str[i]-'0';
                }
                else
                {
                    tmp.push_back(num);
                    num = 0;
                }
                i++;
            }
            tmp.push_back(num);
            grid.push_back(tmp);
            tmp.clear();
        }
    }
    /*
    int j;
    for(i = 0;i < grid.size();i++)
    {
        for(j = 0;j < grid[i].size();j++)
        {
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }*/
    Solution s;
    cout<<s.maxIncreaseKeepingSkyline(grid)<<endl;
    return 0;
}
