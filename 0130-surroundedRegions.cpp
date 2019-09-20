/*
Given a 2D board containing 'X' and 'O' (the letter O), capture all regions
surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.
*/
#include<iostream>
#include<vector>
#include<string>
#include<fstream>

using namespace std;

class Solution {
public:
    void changeMark(vector<vector<char> >& board,int x,int y)
    {
        if(board[x][y] == 'O')
        {
            board[x][y] = '1';
            if(y < board[x].size()-1)
                changeMark(board,x,y+1);
            if(x < board.size()-1)
                changeMark(board,x+1,y);
            if(x > 0)
                changeMark(board,x-1,y);
            if(y > 0)
                changeMark(board,x,y-1);
        }
    }
    void solve(vector<vector<char> >& board) {
        if(board.size() == 0)
            return;
        vector<int> tmp(board[0].size(),0);
        vector<vector<int> > mark(board.size(),tmp);
        int i,j;
        for(i = 0;i < board.size();i++)
        {
            if(i == 0||i == board.size()-1)
            {
                for(j = 0;j < board[i].size();j++)
                {
                    if(board[i][j] == 'O'&&mark[i][j] != 1)
                    {
                        changeMark(board,i,j);
                    }
                }
            }
            else
            {
                if(board[i][0] == 'O'&&mark[i][0] != 1)
                {
                    changeMark(board,i,0);
                }
                if(board[i][board[i].size()-1] == 'O'&&mark[i][board[i].size()-1] != 1)
                {
                    changeMark(board,i,board[i].size()-1);
                }
            }
        }
        for(i = 0;i < board.size();i++)
        {
            for(j = 0;j < board[i].size();j++)
            {
                if(board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
                else if(board[i][j] == '1')
                {
                    board[i][j] = 'O';
                }
            }
        }
    }
};

int main()
{
    ifstream f;
    f.open("in.txt");
    string str;
    getline(f,str);
    vector<vector<char> > board;
    vector<char> tmp;
    int i;
    for(i = 1;i < str.size();i++)
    {
        if(str[i] == '[')
        {
            i++;
            while(str[i] != ']')
            {
                if(str[i] != '"'&&str[i] != ',')
                {
                    tmp.push_back(str[i]);
                }
                i++;
            }
            board.push_back(tmp);
            tmp.clear();
        }
    }
    Solution s;
    s.solve(board);
    int j;
    for(i = 0;i < board.size();i++)
    {
        for(j = 0;j < board[i].size();j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
