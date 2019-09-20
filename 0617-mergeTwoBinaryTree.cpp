/*
Given two binary trees and imagine that when you put one of them to cover the other
, some nodes of the two trees are overlapped while the others are not.

You need to merge them into a new binary tree. The merge rule is that if two nodes
overlap, then sum node values up as the new value of the merged node. Otherwise,
the NOT null node will be used as the node of new tree.
*/
#include "../LCInput/treeVector.h"

/**
 * Definition for a binary tree node.
 * struct Node {
 *     int val;
 *     Node *left;
 *     Node *right;
 *     Node(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    Node* mergeTrees(Node* t1, Node* t2) {
        Node* head;
        head = nodeTour(t1,t2);
        return head;
    }

    Node* nodeTour(Node* t1,Node* t2)
    {
        if(t1 == 0&&t2 == 0)
        {
            return 0;
        }
        else
        {
            Node* node = new Node(0);
            if(t1 == 0)
            {
                node->val = t2->val;
                node->left = nodeTour(0,t2->left);
                node->right = nodeTour(0,t2->right);
            }
            else if(t2 == 0)
            {
                node->val = t1->val;
                node->left = nodeTour(t1->left,0);
                node->right = nodeTour(t1->right,0);
            }
            else
            {
                node->val = t1->val+t2->val;
                node->left = nodeTour(t1->left,t2->left);
                node->right = nodeTour(t1->right,t2->right);
            }
            return node;
        }
        return 0;
    }
};

int main()
{
    vector<Node*> in;
    in = binaryInput("in.txt");
    Solution s;
    print(in[0]);
    cout<<endl;
    print(in[1]);
    cout<<endl;
    Node* head = s.mergeTrees(in[0],in[1]);
    print(head);
    return 0;
}
