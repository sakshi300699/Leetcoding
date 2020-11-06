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
    ListNode* insertionSortList(ListNode* head) {
     if(head==NULL||head->next==NULL)
            return head;
        ListNode* lc=head;
        head=head->next;
        lc->next=NULL;
        while(head){
            ListNode*t=lc;
            ListNode*prev=NULL;
            while(t&&t!=head&&t->val<head->val){
                prev=t;
                t=t->next;
            }
            ListNode*nx=head->next;
            
            //last
            if(t==NULL){
                
                prev->next=head;
                head->next=NULL;
            
            }
            //first
            else if(t==lc){
                head->next=lc;
                lc=head;            
            }            
            //middle
            else{             
                prev->next=head;
                head->next=t;
            }                            
                head=nx;//=> head->next
        }
        return lc;   
    }
};
