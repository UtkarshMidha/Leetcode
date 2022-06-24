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
        ListNode *fast = head, *slow = head;
        // iterate first n nodes using fast
	    while(n--) fast = fast -> next;      
    // if fast is already null, it means we have to delete head itself. So, just return next of head
	    if(!fast) return head -> next;       
	    while(fast -> next)                  // iterate till fast reaches the last node of list
		fast = fast -> next, slow = slow -> next;            
	    slow -> next = slow -> next -> next; // remove the nth node from last
	    return head;
            
            
    }
};
