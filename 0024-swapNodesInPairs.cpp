/*
LeetCode 24. Swap Nodes in Pairs
medium
time:	4ms
space:	8.7mb
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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL||head->next==NULL){
            return head;
        }
        ListNode* cur = head;
        ListNode* pre = NULL;
        while(cur!=NULL){
            ListNode* next = cur->next;
            if(cur->next==NULL){
                break;
            }
            if(pre==NULL){
                head = next;
            }
            else{
                pre->next = next;
            }
            cur->next = next->next;
            next->next = cur;
            pre = cur;
            cur = cur->next;
        }
        return head;
    }
};