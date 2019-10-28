/*
LeetCode 652. Find Duplicate Subtrees
medium
time:	78.07%
space:	33.33%
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
    string traverse(TreeNode* root, unordered_set<string>& m, unordered_set<string>& record, vector<TreeNode*>& ret){
        string cur = to_string(root->val);
        if(root->left!=NULL){
            cur += ","+traverse(root->left,m,record,ret);
            if(root->right==NULL){
                cur += ",#";
            }
        }
        if(root->right!=NULL){
            if(root->left==NULL){
                cur += ",#";
            }
            cur += ","+traverse(root->right,m,record,ret);
        }
        if(m.find(cur)!=m.end()){
            if(record.find(cur)==record.end()){
                ret.push_back(root);
            }
            record.insert(cur);
        }
        else{
            m.insert(cur);
        }
        // cout<<cur<<endl;
        return cur;
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_set<string> m;
        vector<TreeNode*> ret;
        unordered_set<string> record;
        if(root==NULL){
            return ret;
        }
        traverse(root,m,record,ret);
        return ret;
    }
};