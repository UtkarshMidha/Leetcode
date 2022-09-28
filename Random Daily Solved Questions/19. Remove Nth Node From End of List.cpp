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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
     ListNode *curr=head,*h=head,*temp;
        while(n--){
            curr=curr->next;
        }
        if(!curr) return head->next;
        
        
        while(curr->next){
            curr=curr->next;
            h=h->next;
        }
        temp=h->next;
        h->next=h->next->next;
        delete temp;
        return head;
    }
};
