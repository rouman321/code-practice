/*
LeetCode 107. Binary Tree Level Order Traversal II
easy
time:	66.4%
space:	10.81%
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ret;
        if(root==NULL){
            return ret;
        }
        traverse(root,ret,0);
        return ret;
    }
    
    void traverse(TreeNode* root, vector<vector<int>>& ret, int level){
        if(level>=ret.size()){
            ret.insert(ret.begin(),vector<int>());
        }
        ret[ret.size()-1-level].push_back(root->val);
        if(root->left!=0){
            traverse(root->left,ret,level+1);
        }
        if(root->right!=0){
            traverse(root->right,ret,level+1);
        }
    }
};