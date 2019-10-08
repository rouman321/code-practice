/*
LeetCode 199. Binary Tree Right Side View
medium
time:	100%
space:	94.59%
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        if(root==NULL){
            return ret;
        }
        traverse(root,ret,0);
        return ret;
    }
    
    void traverse(TreeNode* root, vector<int>& ret, int level){
        if(ret.size()<=level){
            ret.push_back(0);
        }
        ret[level] = root->val;
        if(root->left!=NULL){
            traverse(root->left,ret,level+1);
        }
        if(root->right!=NULL){
            traverse(root->right,ret,level+1);
        }
    }
};