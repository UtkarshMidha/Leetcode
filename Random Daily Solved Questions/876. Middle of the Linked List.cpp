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
    ListNode* middleNode(ListNode* head) {
        ListNode *h1=head,*h2=head;
        while(h1->next and h1->next->next){
          h1=h1->next->next;
            h2=h2->next;
        }
    
    if(h1->next)
        return h2->next;
    return h2;
    }
};
