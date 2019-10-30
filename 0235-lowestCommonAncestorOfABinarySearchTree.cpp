/*
LeetCode 235. Lowest Common Ancestor of a Binary Search Tree
easy
time:	36ms
space:	25.7mb
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int l = min(p->val,q->val);
        int r = max(p->val,q->val);
        TreeNode* cur = root;
        while(cur->val<l||cur->val>r){
            if(cur->val>r){
                cur = cur->left;
            }
            else{
                cur = cur->right;
            }
        }
        return cur;
    }
};