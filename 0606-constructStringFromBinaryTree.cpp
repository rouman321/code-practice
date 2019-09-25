/*
LeetCode 606. Construct String from Binary Tree
easy
time	50.07%
space	100%
*/
class Solution {
public:
    string tree2str(TreeNode* t) {
        string ret = "";
        if(t==NULL){
            return ret;
        }
        inorder(t,ret);
        return ret;
    }
    
    void inorder(TreeNode* root, string& ret){
        ret += toString(root->val);
        if(root->left!=NULL){
            ret += "(";
            inorder(root->left,ret);
            ret += ")";
        }
        if(root->left==NULL&&root->right!=NULL){
            ret += "()";
        }
        if(root->right!=NULL){
            ret += "(";
            inorder(root->right,ret);
            ret += ")";
        }
    }
    
    string toString(int n){
        string ret = "";
        if(n==0){
            return "0";
        }
        string sign = "";
        if(n<0){
            sign = "-";
            n *= -1;
        }
        while(n>0){
            char tmp = n%10+'0';
            ret = tmp+ret;
            n /= 10;
        }
        return sign+ret;
    }
};