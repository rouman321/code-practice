/*
LeetCode 102. Binary Tree Level Order Traversal
medium
time:	93.31%
space:	21.12%
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        traverse(root,ret,0);
        return ret;
    }
    
    void traverse(TreeNode* root, vector<vector<int>>& ret, int level){
        if(root==NULL){
            return;
        }
        int cur = ret.size();
        if(level>cur-1){
            ret.push_back(vector<int> ());
        }
        ret[level].push_back(root->val);
        traverse(root->left,ret,level+1);
        traverse(root->right,ret,level+1);
    }
};