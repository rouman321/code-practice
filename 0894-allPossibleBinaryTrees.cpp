/*
A full binary tree is a binary tree where each node has exactly 0 or 2 children.

Return a list of all possible full binary trees with N nodes.  Each element of the
answer is the root node of one possible tree.

Each node of each tree in the answer must have node.val = 0.

You may return the final list of trees in any order.
*/
#include "../LCInput/treeVector.h"

class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int N) {
        vector<TreeNode*> ret;
        if(N == 1)
        {
            ret.push_back(new TreeNode(0));
        }
        else
        {
            for(int i = 1;i < N-1;i+=2)
            {
                vector<TreeNode*> left = allPossibleFBT(i);
                vector<TreeNode*> right = allPossibleFBT(N-i-1);
                for(int j = 0;j < left.size();j++)
                {
                    for(int m = 0;m < right.size();m++)
                    {
                        TreeNode* root = new TreeNode(0);
                        root->left = left[j];
                        root->right = right[m];
                        ret.push_back(root);
                    }
                }
            }
        }
        return ret;
    }
};

int main()
{
    int N = numInput("in.txt");
    Solution s;
    vector<TreeNode*> ans = s.allPossibleFBT(N);
    for(int i = 0;i < ans.size();i++)
    {
        printNumTree(ans[i]);
    }
    return 0;
}
