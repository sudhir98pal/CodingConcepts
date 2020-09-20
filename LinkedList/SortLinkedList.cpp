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
    void split(ListNode ** a,ListNode** b,ListNode ** head)
    {
    
        ListNode* f=*head;
        ListNode* s=*head;
        
       f=f->next; // this is an important step;
        while(f)
        {
            f=f->next;
            if(f)
            {
                s=s->next;
                f=f->next;
            }
        }
        
        
        *a=*head;
        *b=s->next;
        s->next=NULL;
        
    }
    
    ListNode* merge(ListNode *f,ListNode* s)
    {
      
      
        ListNode* temp=new  ListNode(0);
        ListNode* h=temp;
        
        
        while(f&&s)
        {
            if(f->val<=s->val)
            {
                temp->next=f;
               
                 f=f->next;
            }
            else
            {
                 temp->next=s;
        
                  s=s->next;
            }
            temp=temp->next;
        }
            
           while(f)
        {
           
        temp->next=f;
         temp=temp->next;
               f=f->next;
        }
           while(s)
        {
            
            temp->next=s;
            temp=temp->next;
               s=s->next;
        }
        
        return h->next;

    }
    void mergesort(ListNode **head)
    {
        
        ListNode *h=*head;
        ListNode *a,*b;
        
        if(!h||!h->next)
        {
            // no need to sort list size 0 or 1 as they are already sorted;
            return;
        }

        
        split(&a,&b,&h);
        // split the list in two part first in a second in b
        
      
        mergesort(&a);
        
        mergesort(&b);
        
        *head=merge(a,b);
        // then megre a and b int original list;

    }
    
public:
    ListNode* sortList(ListNode* head) 
    {
        mergesort(&head);
        return head;
    }
};
