/*
LeetCode 144. Binary Tree Preorder Traversal
medium
interative approach
time:   100%
space:  100%
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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> preNode;
        TreeNode* cur = root;
        vector<int> ret;
        if(root==0){
            return ret;
        }
        while(!preNode.empty()||cur!=0){
            while(cur!=0){
                ret.push_back(cur->val);
                preNode.push(cur);
                cur = cur->left;
            }
            cur = preNode.top();
            preNode.pop();
            cur = cur->right;
        }
        return ret;
    }
};