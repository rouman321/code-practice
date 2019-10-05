/*
LeetCode 1214. Two Sum BSTs
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
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        vector<int> l;
        vector<int> r;
        stack<TreeNode*> s;
        TreeNode* cur = root1;
        while(!s.empty()||cur!=NULL){
            while(cur!=NULL){
                s.push(cur);
                cur = cur->left;
            }
            cur = s.top();
            s.pop();
            l.push_back(cur->val);
            cur = cur->right;
        }
        cur = root2;
        while(!s.empty()||cur!=NULL){
            while(cur!=NULL){
                s.push(cur);
                cur = cur->left;
            }
            cur = s.top();
            s.pop();
            r.push_back(cur->val);
            cur = cur->right;
        }
        int li = 0;
        int ri = r.size()-1;
        while(li<l.size()&&ri>=0){
            if(l[li]+r[ri]==target){
                return true;
            }
            else if(l[li]+r[ri]>target){
                ri--;
            }
            else{
                li++;
            }
        }
        return false;
    }
};