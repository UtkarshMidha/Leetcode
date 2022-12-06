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
    // ListNode* oddEvenList(ListNode* head) {
    //  vector<int> a,b;
    //     ListNode *temp=head;
    //     int i=0;
    //     while(temp){
    //         if(i++ % 2==0)
    //             a.push_back(temp->val);
    //         else
    //             b.push_back(temp->val);
    //         temp=temp->next;
    //     }
    //     temp=head;
    //     for(int i=0;i<a.size();i++){
    //         temp->val=a[i];
    //         temp=temp->next;
    //     }
    //     for(int i=0;i<b.size();i++){
    //         temp->val=b[i];
    //         temp=temp->next;
    //     }
    //     return head;
    // }
    ListNode* oddEvenList(ListNode* head) {
          if(head == NULL || head->next == NULL)
        return head;
    ListNode *odd = head;
    ListNode *even_head = head->next;
    ListNode *even = even_head;
    
    while(even != NULL && even->next != NULL)
    {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = even_head;
    return head;
} 
};
