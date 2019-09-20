/*
Given an integer array with no duplicates. A maximum tree building on this array is
defined as follow:

The root is the maximum number in the array.
The left subtree is the maximum tree constructed from left part subarray divided by
the maximum number.
The right subtree is the maximum tree constructed from right part subarray divided
by the maximum number.

Construct the maximum tree by the given array and output the root node of this tree
.
*/
#include "../LCInput/treeVector.h"

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* root = new TreeNode(0);
        construct(root,nums,0,nums.size()-1);
        return root;

    }
    void construct(TreeNode* root,vector<int> nums,int l,int r)
    {
        int val = nums[l];
        int pos = l;
        for(int i = l;i <= r;i++)
        {
            if(val < nums[i])
            {
                val = nums[i];
                pos = i;
            }
        }
        root->val = val;
        if(pos != l)
        {
            root->left = new TreeNode(0);
            construct(root->left,nums,l,pos-1);
        }
        if(pos != r)
        {
            root->right = new TreeNode(0);
            construct(root->right,nums,pos+1,r);
        }
    }
};

int main()
{
    vector<int> nums = numVectorInput("in.txt");
    Solution s;
    TreeNode* ans = s.constructMaximumBinaryTree(nums);
    print(ans);
    return 0;
}
