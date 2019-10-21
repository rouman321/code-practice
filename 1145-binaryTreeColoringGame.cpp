/*
LeetCode 1145. Binary Tree Coloring Game
medium
time:	29.87%
space:	100%
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
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        unordered_map<int,vector<int>> m;
        traverse(root,m);
        vector<int> tuple = m[x];
        for(int i = 0;i < 2;i++){
            if(tuple[i]>n/2){
                return true;
            }
        }
        if((tuple[0]+tuple[1])+1<=n/2){
            return true;
        }
        return false;
    }
    int traverse(TreeNode* root, unordered_map<int,vector<int>>& m){
        m[root->val] = vector<int>(2,0);
        if(root->left==root->right){
            return 1;
        }
        if(root->left!=0){
            m[root->val][0] = traverse(root->left,m);
        }
        if(root->right!=0){
            m[root->val][1] = traverse(root->right,m);
        }
        return m[root->val][0]+m[root->val][1]+1;
    }
};