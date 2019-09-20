/*
A binary tree is univalued if every node in the tree has the same value.

Return true if and only if the given tree is univalued.
*/
#include "../LCInput/treeVector.h"

class Solution {
public:
    bool isEqual(TreeNode* root,int val)
    {
        if(root == 0)
        {
            return true;
        }
        if(root->val != val)
        {
            return false;
        }
        return isEqual(root->right,val)&&isEqual(root->left,val);
    }

    bool isUnivalTree(TreeNode* root) {
        if(root == 0)
        {
            return true;
        }
        int val = root->val;
        return isEqual(root,val);
    }
};

int main()
{
    TreeNode* root = singleInput("in.txt");
    Solution s;
    if(s.isUnivalTree(root))
    {
        cout<<"true"<<endl;
    }
    else
    {
        cout<<"false"<<endl;
    }
    return 0;
}
