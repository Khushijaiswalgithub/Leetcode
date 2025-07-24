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
    ListNode* partition(ListNode* head, int x) {
        ListNode* small=new ListNode(-1);
        ListNode* spoint=small;
        ListNode* large=new ListNode(-1);
        ListNode* lpoint=large;
        ListNode* temp=head;
        while(temp!=NULL){
            if(temp->val<x){
                spoint->next=temp;
                spoint=spoint->next;

            }
            else{
                lpoint->next=temp;
                lpoint=lpoint->next;
            }
            temp=temp->next;
        }
        spoint->next=large->next;
        lpoint->next=NULL;
        return small->next;
        
    }
};