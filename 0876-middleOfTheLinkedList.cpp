/*
Given a non-empty, singly linked list with head node head, return a middle node of
linked list.

If there are two middle nodes, return the second middle node.
*/
#include "../LCInput/ListNode.h"

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int cnt = 0;
        ListNode* cur = head;
        while(cur->next != 0)
        {
            cnt++;
            cur = cur->next;
        }
        cout<<cnt<<endl;
        cnt++;
        cnt /= 2;
        cur = head;
        for(int i = 0;i < cnt;i++)
        {
            cur = cur->next;
        }
        return cur;
    }
};

int main()
{
    ListNode* head = numList("in.txt");
    Solution s;
    printNumList(s.middleNode(head));
    return 0;
}
