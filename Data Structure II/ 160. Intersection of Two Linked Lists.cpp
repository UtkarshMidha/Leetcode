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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		// unordered_map<ListNode*, int> m;
		// while(headA != NULL){
		// 	m[headA]++;
		// 	headA = headA -> next;
		// }
		// while(headB != NULL){
		// 	if(m[headB] > 0){
		// 		return headB;
		// 	}
		// 	headB = headB -> next;
		// }
		// return NULL;
        
        int n=0,m=0;
        ListNode* ptr1 = headA;
		ListNode* ptr2 = headB;
		while(ptr1 != NULL){
			n++;
			ptr1 = ptr1 -> next;
		}
		while(ptr2 != NULL){
			m++;
			ptr2 = ptr2 -> next;
		}
        
        int diff=abs(n-m);
        if(n>m){
            while(diff){
                diff--;
                headA=headA->next;
            }
        }
        else{
            while(diff){
                diff--;
                headB=headB->next;
            }
        }
        
        while(headA!=NULL and headB!=NULL){
            if(headA==headB)
                return headB;
            headA = headA -> next;
			headB = headB -> next;
        }
        return NULL;           
	    }
};
