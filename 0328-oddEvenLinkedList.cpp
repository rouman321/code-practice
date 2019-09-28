/*
LeetCode 328. Odd Even Linked List
medium
time:	77.22%
space:	77.14%
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
    public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL) return nullptr;
        if(head->next==NULL) return head;
        ListNode* first=head;
        ListNode* second=head->next;
        ListNode* temp=second;
        
        while(second->next!=NULL&&first->next!=NULL){
            first->next=first->next->next;
            second->next=second->next->next;
            if(first->next!=NULL)
                first=first->next;
            if(second->next!=NULL)
                second=second->next;
        }
        first->next=temp;
        return head;
    }
};