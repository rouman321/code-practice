/*
LeetCode 378. Kth Smallest Element in a Sorted Matrix
medium
time:	31.28%
space:	100%
*/
struct comp{
    bool operator()(pair<int,int>& a, pair<int,int>& b){
            return a.first>b.first;
    }
};
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int row = matrix.size();
        vector<int> ind(row,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,comp> que;
        for(int i = 0;i < row;i++){
            que.push(make_pair(matrix[i][0],i));
        }
        for(int i = 0;i < k-1;i++){
            pair<int,int> cur = que.top();
            que.pop();
            ind[cur.second]++;
            if(ind[cur.second]<row){
                que.push(make_pair(matrix[cur.second][ind[cur.second]],cur.second));
            }
        }
        return que.top().first;
    }
};