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
    ListNode *detectCycle(ListNode *head) 
    {
        ListNode * h,*t;
        h=head;
        t=head;
        while(t!=NULL&&h!=NULL&&h->next!=NULL)
        {
        h=h->next->next;
            t=t->next;
            if(h==t)
            {
                
                
                t=head;
                h=h;
                while(h!=t)
                {
                    h=h->next;
                    t=t->next;
                }
                
                return h;
            }
            
        }
        
        return NULL;
    }
};
