/*
LeetCode 145. Binary Tree Postorder Traversal
hard
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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> ret;
        unordered_set<TreeNode*> read;
        TreeNode* cur = root;
        while(cur!=NULL){
            s.push(cur);
            cur = cur->left;
        }
        if(s.empty()){
            return ret;
        }
        cur = s.top();
        s.pop();
        while(cur!=NULL){
            if(read.find(cur)!=read.end()||cur->right==NULL){
                ret.push_back(cur->val);
            }
            else{
                read.insert(cur);
                s.push(cur);
                cur = cur->right;
                while(cur!=NULL){
                    s.push(cur);
                    cur = cur->left;
                }
            }
            if(s.empty()){
                break;
            }
            cur = s.top();
            s.pop();
        }
        return ret;
    }
};