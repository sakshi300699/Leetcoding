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
        ListNode* tempA = headA;
        ListNode* tempB = headB;
        set<ListNode*> st;
        while(tempA!=NULL){

            st.insert(tempA);
            tempA = tempA->next;
        }
        
        while(tempB!=NULL){
            if(st.find(tempB)!=st.end()){
                return tempB;
            }
            tempB=tempB->next;
        }
        
        return NULL;
    }
};
