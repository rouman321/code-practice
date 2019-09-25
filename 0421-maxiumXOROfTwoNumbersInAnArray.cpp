/*
LeetCode 421. Maximum XOR of Two Numbers in an Array
medium
time:	75.64%
*/
class Solution {
public:
    struct TreeNode{
        TreeNode *next[2];
        TreeNode(){
            memset(next,0,2*sizeof(TreeNode*));
        };
    };
    
    int findMaximumXOR(vector<int>& nums) {
        int i;
        int j;
        int z;
        TreeNode* root = new TreeNode;
        TreeNode* cur;
        for(i = 0;i < nums.size();i++)
        {
            cur = root;
            for(j = 31;j >= 0;j--)
            {
                z = (nums[i]>>j)%2;
                if(cur->next[z] == 0)
                {
                    cur->next[z] = new TreeNode;
                }
                cur = cur->next[z];
            }
        }
        
        int ans = 0;
        int temp = 0;
        for(i = 0;i < nums.size();i++)
        {
            cur = root;
            temp = 0;
            for(j = 31;j >= 0;j--)
            {
                z = ((nums[i]>>j)+1)%2;
                temp = temp << 1;
                if(cur->next[z] != 0)
                {
                    temp += 1;
                    cur = cur->next[z];
                }
                else
                {
                    cur = cur->next[(z+1)%2];
                }
            }
            if(temp > ans)
            {
                ans = temp;
            }
        }
        
        return ans;
    }
};