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
    ListNode *detectCycle(ListNode *head) {
        if ( head == NULL || head -> next == NULL )
             return NULL;   
     ListNode *slow=head,*fast=head,*entry=head;
        while(fast->next and fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow == fast) {
                while(slow != entry) {
                    
                    slow = slow -> next;
                    entry = entry -> next;
                }
                return entry;
            }
        }
       return NULL;
    }
};
// Distance traveled by slow when they meet: L1+L2
// Distance traveled by fast when they meet: L1+L2+x+L2, where x is the remaining length of the cycle (meeting point to start of the cycle).

// 2(L1+L2) = L1+L2+x+L2
// 2L1 + 2L2 = L1+2L2+x
// => x = L1
