/*
LeetCode 173. Binary Search Tree Iterator
medium
time:	66.11%
space:	100%
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        cur = root;
        while(cur!=NULL){
            m.push(cur);
            cur = cur->left;
        }
        if(m.empty())
            return;
        cur = m.top();
        m.pop();
    }
    
    /** @return the next smallest number */
    int next() {
        int ret = cur->val;
        cur = cur->right;
        while(cur!=NULL){
            m.push(cur);
            cur = cur->left;
        }
        if(!m.empty()){
            cur = m.top();
            m.pop();
        }
        return ret;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return cur!=NULL;
    }
private:
    stack<TreeNode*> m;
    TreeNode* cur;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */