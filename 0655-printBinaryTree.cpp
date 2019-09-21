/*
LeetCode 655. Print Binary Tree
medium
time:   70.69%
space:  88.89%
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
    vector<vector<string>> printTree(TreeNode* root) {
        int depth = 0;
        vector<vector<TreeNode*>> trans;
        vector<TreeNode*> cur;
        cur.push_back(root);
        trans.push_back(cur);
        bool flag = true;
        while(flag){
            flag = false;
            vector<TreeNode*> tmp;
            for(int i = 0;i < cur.size();i++){
                if(cur[i]==NULL){
                    tmp.push_back(NULL);
                    tmp.push_back(NULL);
                    continue;
                }
                if(cur[i]->left!=0){
                    flag = true;
                    tmp.push_back(cur[i]->left);
                }
                else{
                    tmp.push_back(NULL);
                }
                if(cur[i]->right!=0){
                    flag = true;
                    tmp.push_back(cur[i]->right);
                }
                else{
                    tmp.push_back(NULL);
                }
            }
            trans.push_back(tmp);
            cur = tmp;
            depth++;
        }
        vector<string> width(times(depth)-1,"");
        vector<vector<string>> ret(depth,width);
        int offset = 2;
        for(int i = 0;i < depth-1;i++){
            vector<TreeNode*> tmp = trans[depth-2-i];
            for(int ind = 0;ind < tmp.size();ind++){
                if(tmp[ind]==NULL){
                    continue;
                }
                if(tmp[ind]->left!=0){
                    int val = tmp[ind]->left->val;
                    ret[depth-1-i][ind*(offset*2)+offset/2-1] += toString(val);
                }
                if(tmp[ind]->right!=0){
                    int val = tmp[ind]->right->val;
                    ret[depth-1-i][ind*(offset*2)+offset*3/2-1] += toString(val);
                }
            }
            offset *= 2;
        }
        ret[0][times(depth-1)-1] += toString(root->val);
        return ret;
    }
    
    int times(int n){
        int ret = 1;
        for(int i = 0;i < n;i++){
            ret *= 2;
        }
        return ret;
    }
    
    string toString(int n){
        string ret = "";
        bool flag = false;
        if(n==0){
            return "0";
        }
        if(n<0){
            flag = true;
            n *= -1;
        }
        while(n>0){
            char tmp = '0'+n%10;
            ret = tmp+ret;
            n /= 10;
        }
        if(flag){
            ret = "-"+ret;
        }
        return ret;
    }
};