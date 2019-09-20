/*
Given the root node of a binary search tree (BST) and a value. You need to find the
node in the BST that the node's value equals the given value. Return the subtree
rooted with that node. If such node doesn't exist, you should return NULL.

For example,

Given the tree:
        4
       / \
      2   7
     / \
    1   3

And the value to search: 2
You should return this subtree:

      2
     / \
    1   3
In the example above, if we want to search the value 5, since there is no node with
value 5, we should return NULL.

Note that an empty tree is represented by NULL, therefore you would see the
expected output (serialized tree format) as [], not null.
*/
#include "../LCInput/treeVector.h"

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root != 0)
        {
            if(root->val == val)
            {
                return root;
            }
            if(root->val < val)
            {
                root = root->right;
            }
            else
            {
                root = root->left;
            }
        }
        return 0;
    }
};

int main()
{
    ifstream in;
    in.open("in.txt");
    vector<int> nums;
    vector<int> nullIndex;
    string str;
    getline(in,str);
    int i;
    for(i = 0;i < str.size();i++)
    {
        if(isNum(str[i]))
        {
            int tmp = 0;
            while(isNum(str[i]))
            {
                tmp *= 10;
                tmp += str[i]-'0';
                i++;
            }
            nums.push_back(tmp);
        }
        else if(str[i] == 'n')
        {
            nullIndex.push_back(nums.size());
            nums.push_back(0);
        }
    }
    TreeNode* root = NULL;
    root = constructTree(nums,nullIndex,0);
    getline(in,str);
    int val = 0;
    for(int i = 0;i < str.size();i++)
    {
        val *= 10;
        val += str[i]-'0';
    }
    Solution s;
    printNumTree(s.searchBST(root,val));
    return 0;
}
