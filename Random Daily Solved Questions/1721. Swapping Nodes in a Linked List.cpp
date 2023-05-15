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
    ListNode* swapNodes(ListNode* head, int k) {
        int count=0;
        ListNode *curr=head,*p1=head,*p2=head,*p3=head,*p4=head;
        
        while(curr){
            count++;
            curr=curr->next;
        }
        int back=count-k;
        if(count==1) return head;

        while(--k){
            p1=p1->next;
        }
        
        
        while(back--){
            p3=p3->next;
        }
        swap(p1->val,p3->val);
        
        

        return head;
    }
};
