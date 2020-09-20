// Q Link -> https://leetcode.com/problems/add-two-numbers/
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
class Solution 
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode * curr=new ListNode(0);
        ListNode * ans=curr;
        
        ListNode *p=l1;
        ListNode *q=l2;
        
        int x,y,sum;
        int carry=0;
        while(p!=NULL||q!=NULL)
        {
            int x=(p!=NULL)?p->val:0;
            int y=(q!=NULL)?q->val:0;
            
            sum=x+y+carry;
            curr->next=new ListNode(sum%10);
            carry=sum/10;
            if(p!=NULL) p=p->next;
            if(q!=NULL) q=q->next;
            curr=curr->next;
        }
        if(carry>0)
        {    curr->next=new ListNode(carry);
            
        }
        
        return ans->next;
        
    }
};
