/*Given two words (beginWord and endWord), and a dictionary's word list, find all
shortest transformation sequence(s) from beginWord to endWord, such that:

Only one letter can be changed at a time
Each transformed word must exist in the word list. Note that beginWord is not a
transformed word.
Note:

Return an empty list if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
*/
#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<queue>

using namespace std;

class Solution {
public:
    bool isAdj(string a,string b)
    {
        if(a.size()!=b.size())
        {
            return false;
        }
        int i;
        int cnt = 0;
        for(i = 0;i < a.size();i++)
        {
            if(a[i]!=b[i])
            {
                cnt++;
            }
        }
        return cnt==1;
    }

    vector<vector<string> > findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int i,j;
        vector<vector<string> > ret;
        vector<int> tmp;
        vector<vector<int> > graph;
        for(i = 0;i < wordList.size()+1;i++)
        {
            for(j = 0;j < wordList.size()+1;j++)
            {
                //if()
                if(i!=0 && j!=0&&isAdj(wordList[i-1],wordList[j-1]))
                {
                    tmp.push_back(1);
                }
                else
                {
                    tmp.push_back(0);
                }
            }
            graph.push_back(tmp);
            tmp.clear();
        }
        int end = -1;
        for(i = 0;i < wordList.size();i++)
        {
            if(isAdj(beginWord,wordList[i]))
            {
                graph[0][i+1] = 1;
            }
            if(endWord==wordList[i])
            {
                end = i+1;
            }
        }
        if(end == -1)
        {
            return ret;
        }
        /*
        for(i = 0;i < graph.size();i++)
        {
            for(j = 0;j < graph[i].size();j++)
            {
                cout<<graph[i][j]<<" ";
            }
            cout<<endl;
        }
*/
        vector<vector<int> > retIndex;
        vector<int> path;
        int minLen = -1;
        queue<pair<int,vector<int> > > que;
        que.push({0,path});
        while(!que.empty())
        {
            int cur = que.front().first;
            path = que.front().second;
            path.push_back(cur);
            que.pop();
            if(cur == end)
            {
                if(path.size() < minLen||minLen == -1)
                {
                    retIndex.clear();
                    retIndex.push_back(path);
                    minLen = path.size();
                }
                else if(path.size() == minLen)
                {
                    retIndex.push_back(path);
                }/*
                for(i = 0;i < path.size();i++)
                {
                    cout<<path[i]<<" ";
                }
                cout<<endl;*/
            }
            else if(minLen==-1||path.size()<minLen)
            {
                for(i = 1;i <= wordList.size();i++)
                {
                    if(graph[cur][i] == 1)
                    {
                    //cout<<"2"<<endl;
                        que.push({i,path});
                    }
                }
            }
        }
        vector<string> wordPath;
        for(i = 0;i < retIndex.size();i++)
        {
            wordPath.push_back(beginWord);
            for(j = 1;j < retIndex[i].size();j++)
            {
                wordPath.push_back(wordList[retIndex[i][j]-1]);
            }
            ret.push_back(wordPath);
            wordPath.clear();
        }
        return ret;
    }
};

bool isChar(char ch)
{
    return ch<='z'&&ch>='a';
}

int main()
{
    string in;
    ifstream input;
    input.open("in.txt");
    getline(input,in);
    string beginWord = in.substr(1,in.size()-2);
    getline(input,in);
    string endWord = in.substr(1,in.size()-2);
    getline(input,in);
    vector<string> wordList;
    for(int i=0;i < in.size();i++)
    {
        if(isChar(in[i]))
        {
            string tmp = "";
            while(isChar(in[i]))
            {
                tmp+=in[i];
                i++;
            }
            wordList.push_back(tmp);
        }
    }
    Solution s;
    vector<vector<string> >out = s.findLadders(beginWord,endWord,wordList);
    for(int i = 0;i < out.size();i++)
    {
        for(int j = 0;j < out[i].size();j++)
        {
            cout<<out[i][j]<<",";
        }
        cout<<endl;
    }
    return 0;
}
