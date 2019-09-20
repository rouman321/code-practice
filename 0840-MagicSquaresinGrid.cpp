/*
A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9 such
that each row, column, and both diagonals all have the same sum.

Given an grid of integers, how many 3 x 3 "magic square" subgrids are there?  (Each
subgrid is contiguous).
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    bool isMagic(vector<vector<int> > grid,int x,int y)
    {
        int sum = grid[x][y]+grid[x][y+1]+grid[x][y+2];
        int i,j;
        for(i = 0;i <= 2;i++)
        {
            for(j = 0;j <= 2;j++)
            {
                if(grid[x+i][y+j] > 9||grid[x+i][y+j] < 1)
                {
                    return false;
                }
            }
        }
        for(i = 1;i <= 2;i++)
        {
            if(grid[x+i][y]+grid[x+i][y+1]+grid[x+i][y+2] != sum)
            {
                return false;
            }
        }
        for(i = 0;i <= 2;i++)
        {
            if(grid[x][y+i]+grid[x+1][y+i]+grid[x+2][y+i] != sum)
            {
                return false;
            }
        }
        if(grid[x][y]+grid[x+1][y+1]+grid[x+2][y+2] != sum)
        {
            return false;
        }
        if(grid[x][y+2]+grid[x+1][y+1]+grid[x+2][y] != sum)
        {
            return false;
        }
        return true;
    }
    int numMagicSquaresInside(vector<vector<int> >& grid) {
        if(grid.size() < 3)
        {
            return 0;
        }
        if(grid[0].size() < 3)
        {
            return 0;
        }
        int cnt = 0;
        int i,j;
        for(i = 0;i < grid.size()-2;i++)
        {
            for(j = 0;j < grid[0].size()-2;j++)
            {
                if(isMagic(grid,i,j))
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

int main()
{
    ifstream input;
    input.open("in.txt",ios::in);
    string s;
    getline(input,s);
    int pos = 1;
    vector< vector<int> > grid;
    while(pos <= s.size())
    {
        if(s[pos] == '[')
        {
            pos++;
            vector<int> row;
            int tmp = 0;
            while(s[pos] != ']')
            {
                if(s[pos] != ',')
                {
                    tmp *= 10;
                    tmp += s[pos]-'0';
                }
                else
                {
                    row.push_back(tmp);
                    tmp = 0;
                }
                pos++;
            }
            row.push_back(tmp);
            grid.push_back(row);
        }
        pos++;
    }
    Solution ans;
    cout<<ans.numMagicSquaresInside(grid)<<endl;
    return 0;
}
