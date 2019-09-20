/*
Given the root of a binary tree with N nodes, each node in the tree has node.val
coins, and there are N coins total.

In one move, we may choose two adjacent nodes and move one coin from one node to
another.  (The move may be from parent to child, or from child to parent.)

Return the number of moves required to make every node have exactly one coin.
*/
#include "../LCInput/treeVector.h"

class Solution {
public:
    int distribute(TreeNode* root)
    {
        if(root == 0)
        {
            return 0;
        }
        int take = 0;
        take = distribute(root->right)+distribute(root->left);
        int ret = root->val+take-1;
        cnt += abs(ret);
        return ret;
    }
    int distributeCoins(TreeNode* root) {
        cnt = 0;
        distribute(root);
        return cnt;
    }
private:
    int cnt;
};

int main()
{
    TreeNode* root = singleInput("in.txt");
    Solution s;
    cout<<s.distributeCoins(root)<<endl;
    return 0;
}
