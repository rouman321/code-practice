/*
LeetCode 958. Check Completeness of a Binary Tree
medium
time:	100%
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
    bool isCompleteTree(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        vector<TreeNode*> cur;
        vector<TreeNode*> next;
        cur.push_back(root);
        int pos = -1;
        while(cur.size()!=0){
            int curP = -1;
            for(int i = 0;i < cur.size();i++){
                if(cur[i]->left!=NULL){
                    next.push_back(cur[i]->left);
                    if(curP!=-1){
                        return false;
                    }
                }
                else{
                    curP = next.size();
                }
                if(cur[i]->right!=NULL){
                    next.push_back(cur[i]->right);
                    if(curP!=-1){
                        return false;
                    }
                }
                else{
                    curP = next.size();
                }
            }
            if(next.size()!=0&&pos!=-1){
                return false;
            }
            pos = curP;
            cur = next;
            next.clear();
        }
        return true;
    }
};