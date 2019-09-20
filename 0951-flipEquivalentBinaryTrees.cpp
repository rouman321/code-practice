/*
For a binary tree T, we can define a flip operation as follows: choose any node,
and swap the left and right child subtrees.

A binary tree X is flip equivalent to a binary tree Y if and only if we can make X
equal to Y after some number of flip operations.

Write a function that determines whether two binary trees are flip equivalent. The
trees are given by root nodes root1 and root2.
*/
#include "../LCInput/treeVector.h"

class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(root1 == 0||root2 == 0)
        {
            return root1 == root2;
        }
        if(root1->val != root2->val)
        {
            return false;
        }
        if(flipEquiv(root1->left,root2->left))
        {
            return flipEquiv(root1->right,root2->right);
        }
        else if(flipEquiv(root1->left,root2->right))
        {
            return flipEquiv(root1->right,root2->left);
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    vector<TreeNode*> roots = multiLineInput("in.txt");
    Solution s;
    if(s.flipEquiv(roots[0],roots[1]))
    {
        cout<<"true"<<endl;
    }
    else
    {
        cout<<"false"<<endl;
    }
    return 0;
}
