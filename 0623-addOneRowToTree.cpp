/*
LeetCode 623. Add One Row to Tree
medium
time:	88.08%
space:	80%
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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(d==1){
            TreeNode* n = new TreeNode(v);
            n->left = root;
            return n;
        }
        if(root==NULL){
            return root;
        }
        solve(root,v,d,1);
        return root;
    }
    
    void solve(TreeNode* root, int v, int d, int level){
        if(level==d-1){
            TreeNode* l = new TreeNode(v);
            TreeNode* r = new TreeNode(v);
            l->left = root->left;
            r->right = root->right;
            root->left = l;
            root->right = r;
            return;
        }
        if(root->left!=NULL){
            solve(root->left,v,d,level+1);
        }
        if(root->right!=NULL){
            solve(root->right,v,d,level+1);
        }
    }
};