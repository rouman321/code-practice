/*
Given the root node of a binary search tree, return the sum of values of all nodes
with value between L and R (inclusive).

The binary search tree is guaranteed to have unique values.
*/
#include <iostream>
#include "../LCInput/treeVector.h"

class Solution {
public:
    int rangeSumBST(Node* root, int L, int R) {
        int ret = 0;
        if(root == 0)
        {
            return ret;
        }
        if(root->val <= R&&root->val >= L)
        {
            ret += root->val;
        }
        ret += rangeSumBST(root->right,L,R)+rangeSumBST(root->left,L,R);
        return ret;
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
    Node* head = NULL;
    head = constructTree(nums,nullIndex,0);
    nums.clear();
    int L = 0;
    getline(in,str);
    for(i = 0;i < str.size();i++)
    {
        L *= 10;
        L += str[i]-'0';
    }
    int R = 0;
    getline(in,str);
    for(i = 0;i < str.size();i++)
    {
        R *= 10;
        R += str[i]-'0';
    }
    Solution s;
    cout<<s.rangeSumBST(head,L,R)<<endl;
    return 0;
}
