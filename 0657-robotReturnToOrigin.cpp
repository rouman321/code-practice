/*
There is a robot starting at position (0, 0), the origin, on a 2D plane. Given a
sequence of its moves, judge if this robot ends up at (0, 0) after it completes
its moves.

The move sequence is represented by a string, and the character moves[i] represents
its ith move. Valid moves are R (right), L (left), U (up), and D (down). If the
robot returns to the origin after it finishes all of its moves, return true.
Otherwise, return false.

Note: The way that the robot is "facing" is irrelevant. "R" will always make the
robot move to the right once, "L" will always make it move left, etc. Also, assume
that the magnitude of the robot's movement is the same for each move.
*/
#include "../LCInput/stringVector.h"
#include <iostream>

class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0;
        int y = 0;
        for(int i = 0;i < moves.size();i++)
        {
            switch(moves[i])
            {
                case 'U':
                    y++;
                    break;
                case 'D':
                    y--;
                    break;
                case 'L':
                    x--;
                    break;
                case 'R':
                    x++;
                    break;
            }
        }
        return x==y&&x==0;
    }
};

int main()
{
    string moves = stringInput("in.txt");
    Solution s;
    if(s.judgeCircle(moves))
    {
        cout<<"true"<<endl;
    }
    else
    {
        cout<<"false"<<endl;
    }
    return 0;
}
