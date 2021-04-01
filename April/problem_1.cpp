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
    bool isPalindrome(ListNode* head) {
        string s ="";
        
        while(head->next!=NULL){
            s = s + (char)head->val;
            head=head->next;
        }
        
        string r = s;
        sort(s.begin(),s.end());
        sort(r.begin(),r.end());
        
        if(r==s)
            return true;
        
        
            return false;
    }
};
