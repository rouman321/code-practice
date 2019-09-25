/*
LeetCode 993. Cousins in Binary Tree
easy
time:	74.25%
space:	86.67%
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
    bool isCousins(TreeNode* root, int x, int y) {
        infox = make_pair(0,0);
        infoy = make_pair(0,0);
        cnt = 0;
        traverse(root,0,x,y,0);
        return infox.first==infoy.first&&infox.second!=infoy.second;
    }
    
    void traverse(TreeNode* root, int level, int x, int y, int parent){
        if(cnt==2){
            return;
        }
        if(root->val == x){
            infox.first = level;
            infox.second = parent;
            cnt++;
        }
        if(root->val == y){
            infoy.first = level;
            infoy.second = parent;
            cnt++;
        }
        if(root->left){
            traverse(root->left,level+1,x,y,root->val);
        }
        if(root->right){
            traverse(root->right,level+1,x,y,root->val);
        }
    }
private:
    pair<int,int> infox;
    pair<int,int> infoy;
    int cnt;
};