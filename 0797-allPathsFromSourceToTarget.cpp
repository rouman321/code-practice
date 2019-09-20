/*
Given a directed, acyclic graph of N nodes.  Find all possible paths from node 0 to
node N-1, and return them in any order.

The graph is given as follows:  the nodes are 0, 1, ..., graph.length - 1.
graph[i] is a list of all nodes j for which the edge (i, j) exists.
*/
#include "../LCInput/numInput.h"
#include <queue>

class Solution {
public:
    vector<vector<int> > allPathsSourceTarget(vector<vector<int> >& graph) {
        vector<int> path;
        queue<vector<int> > mid;
        vector<vector<int> > ret;
        path.push_back(0);
        mid.push(path);
        path.clear();
        while(!mid.empty())
        {
            path = mid.front();
            mid.pop();
            if(path[path.size()-1] == graph.size()-1)
            {
                ret.push_back(path);
            }
            else
            {
                for(int i = 0;i < graph[path[path.size()-1]].size();i++)
                {
                    path.push_back(graph[path[path.size()-1]][i]);
                    mid.push(path);
                    path.pop_back();
                }
            }
        }
        return ret;
    }
};

int main()
{
    vector<vector<int> > graph = oneLineVectorVectorInput("in.txt");
    Solution s;
    numVectorVectorOutput(s.allPathsSourceTarget(graph));
    return 0;
}
