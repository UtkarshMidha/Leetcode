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
    ListNode* reverseList(ListNode* head) {
    //     vector<int>mp;
    //     ListNode *temp=head;
    //     while(temp){
    //         mp.push_back(temp->val);
    //         temp=temp->next;
    //     }
    //     temp=head;
    //     for(int i=mp.size()-1;i>=0;i--)
    //     {head->val=mp[i];
    //     head=head->next;}
    //     return temp;
    // 
    
    ListNode* cur = NULL;
        while (head) {
            ListNode* next = head -> next;
            head -> next = cur;
            cur = head;
            head = next;
        }
        return cur;
    
    }
};
