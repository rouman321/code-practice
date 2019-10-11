/*
LeetCode 337. House Robber III
medium
time:	79.41%
space:	94.44%
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
    int rob(TreeNode* root) {
        pair<int,int> ret = dfs(root);
        // cout<<ret.first<<" "<<ret.second<<endl;
        return max(ret.first,ret.second);
    }
    
    pair<int,int> dfs(TreeNode* root){
        if(root==NULL){
            return {0,0};
        }
        pair<int,int> l = dfs(root->left);
        pair<int,int> r = dfs(root->right);
        return {l.second+r.second+root->val,max(l.first,l.second)+max(r.first,r.second)};
    }
};