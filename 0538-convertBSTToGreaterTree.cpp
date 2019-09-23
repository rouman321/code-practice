/*
LeetCode 538. Convert BST to Greater Tree
easy
time	69.77%
space	57.14%
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
    TreeNode* convertBST(TreeNode* root) {
        int add = 0;
        stack<TreeNode*> s;
        TreeNode* cur = root;
        while(!s.empty()||cur!=0){
            while(cur!=0){
                s.push(cur);
                cur = cur->right;
            }
            cur = s.top();
            s.pop();
            int tmp = cur->val;
            cur->val += add;
            add += tmp;
            cur = cur->left;
        }
        return root;
    }
};