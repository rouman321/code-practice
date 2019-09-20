/*Given two words (beginWord and endWord), and a dictionary's word list, find the
length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list. Note that beginWord is not a
transformed word.
Note:

Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
*/
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
    int diff(string a,string b)
    {
        int i;
        int cnt = 0;
        for(i = 0;i < a.size();i++)
        {
            if(a[i] != b[i])
            {
                cnt++;
            }
        }
        return cnt;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int i;
        int endInd = -1;
        for(i = 0;i < wordList.size();i++)
        {
            if(wordList[i] == endWord)
            {
                endInd = i;
                break;
            }
        }
        if(endInd == -1)
        {
            return 0;
        }
        vector<bool> mark(wordList.size(),true);
        queue<pair<string,int> > myqueue;
        for(i = 0;i < mark.size();i++)
        {
            if(wordList[i] == beginWord)
                mark[i] = false;
            else if(diff(wordList[i],beginWord) == 1)
            {
                myqueue.push({i,2});
                mark[i] = false;
            }
        }
        while(!myqueue.empty())
        {
            pair<int,int> current = myqueue.front();
            myqueue.pop();
            if(wordList[current.first] == endWord)
            {
                return current.second;
            }
            for(i = 0;i < wordList.size();i++)
            {
                if(diff(wordList[i],wordList[current.first]) == 1&&mark[i])
                {
                    myqueue.push({i,current.second+1});
                    mark[i] = false;
                }
            }
        }
        return 0;
    }
};

int main()
{
    ifstream f;
    f.open("in.txt");
    string instr;
    getline(f,instr);
    string beginWord = instr.substr(1,instr.size()-2);
    getline(f,instr);
    string endWord = instr.substr(1,instr.size()-2);
    getline(f,instr);
    vector<string> wordList;
    int i = 0;
    for(i = 0;i < instr.size();i++)
    {
        if(instr[i] == '"')
        {
            i++;
            string tmp = "";
            while(instr[i] != '"')
            {
                tmp += instr[i];
                i++;
            }
            wordList.push_back(tmp);
            tmp.clear();
        }
    }
    Solution s;
    cout<<s.ladderLength(beginWord,endWord,wordList)<<endl;
    return 0;
}
//3.452
