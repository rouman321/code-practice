/*
LeetCode 445. Add Two Numbers II
medium
time:	44.08%
space:	51.85%
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1 = 0;
        ListNode* cur1 = l1;
        while(cur1!=NULL){
            cur1 = cur1->next;
            len1++;
        }
        int len2 = 0;
        cur1 = l2;
        while(cur1!=0){
            cur1 = cur1->next;
            len2++;
        }
        stack<int> s;
        cur1 = l1;
        ListNode* cur2 = l2;
        while(len1>len2){
            s.push(cur1->val);
            cur1 = cur1->next;
            len1--;
        }
        while(len2>len1){
            s.push(cur2->val);
            cur2 = cur2->next;
            len2--;
        }
        while(cur1!=NULL){
            s.push(cur1->val+cur2->val);
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        int pass = 0;
        cur1 = NULL;
        while(!s.empty()){
            int tmp = s.top();
            s.pop();
            tmp += pass;
            pass = 0;
            if(tmp>=10){
                pass = tmp/10;
                tmp %= 10;
            }
            ListNode* cur = new ListNode(tmp);
            if(cur1){
                cur->next = cur1;
            }
            cur1 = cur;
        }
        if(pass==0){
            return cur1;
        }
        ListNode* ret = new ListNode(pass);
        ret->next = cur1;
        return ret;
    }
};