/*
530. Minimum Absolute Difference in BST
Given a binary search tree with non-negative values, find the minimum absolute
difference between values of any two nodes.
*/
#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    int dif(int a,int b)
    {
        if(a > b)
        {
            return a-b;
        }
        return b-a;
    }
    void getNum(vector<int>& cmp,TreeNode* node)
    {
        if(node->left != 0)
        {
            getNum(cmp,node->left);
        }
        if(node->right != 0)
        {
            getNum(cmp,node->right);
        }
        cmp.push_back(node->val);
    }
    int getMinimumDifference(TreeNode* root) {
        int minDif = -1;
        if(root == 0)
        {
            return 0;
        }
        if(root->right == 0&&root->left == 0)
        {
            return 0;
        }
        vector<int> vals;
        getNum(vals,root);
        int i,j;
        for(i = 0;i < vals.size();i++)
        {
            for(j = i+1;j < vals.size();j++)
            {
                if(minDif == -1||minDif > dif(vals[i],vals[j]))
                {
                    minDif = dif(vals[i],vals[j]);
                }
            }
        }
        return minDif;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

TreeNode* stringToTreeNode(string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size()) {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode* root = new TreeNode(stoi(item));
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (true) {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

int main() {
    ifstream input;
    input.open("in.txt");
    string line;
    while (getline(input, line)) {
        TreeNode* root = stringToTreeNode(line);

        int ret = Solution().getMinimumDifference(root);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
