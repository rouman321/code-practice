/*
LeetCode 257. Binary Tree Paths
easy
time:	76.33%
space:	42.1%
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
    void addArrow(string& s){
        s = "->"+s;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ret;
        if(root==NULL){
            return ret;
        }
        vector<string> n = binaryTreePaths(root->left);
        for(int i = 0;i < n.size();i++){
            ret.push_back(n[i]);
        }
        n = binaryTreePaths(root->right);
        for(int i = 0;i < n.size();i++){
            ret.push_back(n[i]);
        }
        if(ret.size()==0){
            ret.push_back(to_string(root->val));
        }
        else
            for(int i = 0;i < ret.size();i++){
                addArrow(ret[i]);
                ret[i] = to_string(root->val)+ret[i];
            }
        return ret;
    }
};