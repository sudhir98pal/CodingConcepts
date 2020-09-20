/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) 
    {
        
        ListNode * curr=head;
        ListNode *mnext=NULL;
        ListNode * prev=NULL;
        while(curr!=NULL)
        {
            
            mnext=curr->next;
            curr->next=prev;
            prev=curr;
            curr=mnext;
        }
        return prev;
    }
};
