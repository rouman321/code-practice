/*
On a 2 dimensional grid with R rows and C columns, we start at (r0, c0) facing
east.

Here, the north-west corner of the grid is at the first row and column, and the
south-east corner of the grid is at the last row and column.

Now, we walk in a clockwise spiral shape to visit every position in this grid.

Whenever we would move outside the boundary of the grid, we continue our walk
outside the grid (but may return to the grid boundary later.)

Eventually, we reach all R * C spaces of the grid.

Return a list of coordinates representing the positions of the grid in the order
they were visited.
*/
#include "../LCInput/numInput.h"

class Solution {
public:
    vector<vector<int> > spiralMatrixIII(int R, int C, int r0, int c0) {
        vector<vector<int> > ret;
        vector<int> tmp;
        int dir = 0;
        int r = r0;
        int c = c0;
        int num = R*C;
        int cnt = 0;
        int cEnd = c+1;
        int rEnd = 0;
        while(cnt < num)
        {
            if(r>=0 && r<R && c>=0 && c<C)
            {
                tmp.push_back(r);
                tmp.push_back(c);
                ret.push_back(tmp);
                tmp.clear();
                cnt++;
            }
            switch(dir){
                case 0:
                    c++;
                    if(c == cEnd)
                    {
                        dir++;
                        rEnd = 2*r0-r+1;
                    }
                    break;
                case 1:
                    r++;
                    if(r == rEnd)
                    {
                        dir++;
                        cEnd = 2*c0-c;
                    }
                    break;
                case 2:
                    c--;
                    if(c == cEnd)
                    {
                        dir++;
                        rEnd = 2*r0-r;
                    }
                    break;
                case 3:
                    r--;
                    if(r == rEnd)
                    {
                        dir = 0;
                        cEnd = 2*c0-c+1;
                    }
                    break;
            }
        }
        return ret;
    }
};

int main()
{
    string str;
    ifstream f;
    f.open("in.txt");
    getline(f,str);
    int R = 0;
    for(int i = 0;i < str.size();i++)
    {
        R *= 10;
        R += str[i]-'0';
    }
    getline(f,str);
    int C = 0;
    for(int i = 0;i < str.size();i++)
    {
        C *= 10;
        C += str[i]-'0';
    }
    getline(f,str);
    int r0 = 0;
    for(int i = 0;i < str.size();i++)
    {
        r0 *= 10;
        r0 += str[i]-'0';
    }
    getline(f,str);
    int c0 = 0;
    for(int i = 0;i < str.size();i++)
    {
        c0 *= 10;
        c0 += str[i]-'0';
    }
    Solution s;
    numVectorVectorOutput(s.spiralMatrixIII(R,C,r0,c0));
    return 0;
}
