/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes
of the grid.
Empty cells are indicated by the character '.'
*/
#include<iostream>
#include<vector>
#include<string>
#include<fstream>

using namespace std;

void print(vector<vector<char> > board)
{
    int i,j;
    for(i = 0;i < board.size();i++)
	{
		for(j = 0;j < board[i].size();j++)
		{
			cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}
}

class Solution {
public:
    void attempt(vector<vector<char> >&board,int index)
    {
        //print(tmp);
        //cout<<endl;
        if(index == 81)
        {
            board = tmp;
            return;
        }
        int i = index/9;
        int j = index%9;
        if(tmp[i][j] == '.')
        {
            //cout<<"1 "<<index<<endl;
            int k;
            for(k = 0;k < 9;k++)
            {
                if(!(column[j][k]||row[i][k]||sub[(i/3)*3+j/3][k]))
                {
                    tmp[i][j] = '1'+k;
                    column[j][k] = true;
                    row[i][k] = true;
                    sub[(i/3)*3+j/3][k] = true;
                    attempt(board,index+1);
                    tmp[i][j] = '.';
                    column[j][k] = false;
                    row[i][k] = false;
                    sub[(i/3)*3+j/3][k] = false;
                }
            }
        }
        else
        {
            //cout<<"0 "<<index<<endl;
            attempt(board,index+1);
        }
    }
    void solveSudoku(vector<vector<char> >& board) {
        tmp = board;
        int i,j;
        for(i = 0;i < 9;i++)
        {
            for(j = 0;j < 9;j++)
            {
                column[i][j] = false;
                row[i][j] = false;
                sub[i][j] = false;
            }
        }
        for(i = 0;i < 9;i++)
        {
            for(j = 0;j < 9;j++)
            {
                if(board[i][j] != '.')
                {
                    column[j][board[i][j]-'1'] = true;
                    row[i][board[i][j]-'1'] = true;
                    sub[(i/3)*3+j/3][board[i][j]-'1'] = true;
                }
            }
        }
        attempt(board,0);
    }
private:
    vector<vector<char> > tmp;
    bool column[9][9];
    bool row[9][9];
    bool sub[9][9];
};

int main()
{
	ifstream input;
	string s;
	input.open("in.txt");
	getline(input,s);
	vector<char> tmp;
	vector<vector<char> > board;
	int i,j;
	for(i = 1;i < s.size();i++)
	{
		if(s[i] == '[')
		{
			i++;
			while(s[i] != ']')
			{
				if((s[i] != '"')&&(s[i] != ','))
				{
					tmp.push_back(s[i]);
				}
				i++;
			}
			board.push_back(tmp);
			tmp.clear();
		}
	}
	Solution so;
	so.solveSudoku(board);
	print(board);
	return 0;
}
