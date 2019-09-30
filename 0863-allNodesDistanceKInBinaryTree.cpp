/*
LeetCode 863. All Nodes Distance K in Binary Tree
medium
time:	93.97%
space:	72.73%
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        unordered_map<TreeNode*,TreeNode*> m;
        TreeNode* cur = root;
        stack<TreeNode*> s;
        while(!s.empty()||cur!=NULL){
            while(cur!=NULL){
                s.push(cur);
                cur = cur->left;
            }
            cur = s.top();
            s.pop();
            if(cur->left!=NULL){
                m[cur->left] = cur;
            }
            if(cur->right!=NULL){
                m[cur->right] = cur;
            }
            cur = cur->right;
        }
        vector<int> ret;
        queue<pair<TreeNode*,int>> q;
        unordered_set<TreeNode*> check;
        q.push(make_pair(target,0));
        check.insert(target);
        while(!q.empty()){
            cur = q.front().first;
            int tmp = q.front().second;
            q.pop();
            if(tmp == K){
                ret.push_back(cur->val);
                continue;
            }
            if(m.find(cur)!=m.end()&&check.find(m[cur])==check.end()){
                q.push(make_pair(m[cur],tmp+1));
                check.insert(m[cur]);
            }
            if(cur->left!=NULL&&check.find(cur->left)==check.end()){
                q.push(make_pair(cur->left,tmp+1));
                check.insert(cur->left);
            }
            if(cur->right!=NULL&&check.find(cur->right)==check.end()){
                q.push(make_pair(cur->right,tmp+1));
                check.insert(cur->right);
            }
        }
        return ret;
    }
};