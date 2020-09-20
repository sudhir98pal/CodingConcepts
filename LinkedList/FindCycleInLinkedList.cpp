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
    bool hasCycle(ListNode *head) 
    {
        ListNode * h=head;// hare
        ListNode * t=head; //tortoise;
        while(h)
        {
            h=h->next;
            if(h)
            {
                h=h->next;
                t=t->next;
            }
            if(h==t) return true;
        }
        
        return false;
        
    }
};
