/*
LeetCode 725. Split Linked List in Parts
medium
time:	51.9%
space:	9.09%
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*> ret(k,NULL);
        int len = 0;
        ListNode* cur = root;
        while(cur!=NULL){
            len++;
            cur = cur->next;
        }
        int size = len/k;
        int larger = len%k;
        cur = root;
        for(int i = 0;i < k;i++){
            int curSize = size;
            if(larger>0){
                curSize++;
                larger--;
            }
            ListNode* c;
            while(curSize>0){
                if(ret[i]==NULL){
                    ret[i] = new ListNode(cur->val);
                    c = ret[i];
                }
                else{
                    c->next = new ListNode(cur->val);
                    c = c->next;
                }
                curSize--;
                cur = cur->next;
            }
        }
        return ret;
    }
};