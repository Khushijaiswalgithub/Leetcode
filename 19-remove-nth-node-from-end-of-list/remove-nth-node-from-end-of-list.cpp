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
    int findlength(ListNode* temp){
        int k=0;
        while(temp!=NULL){
            k++;
            temp=temp->next;
        }
        return k;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* temp=head;
        int len=findlength(temp);
        
        temp=dummy;
        for (int i = 0; i < len - n; i++) {
           temp = temp->next;
        }
        ListNode* nodedelete=temp->next;
        if(nodedelete!=NULL ){
          temp->next=nodedelete->next;
        }
        return dummy->next;
    }
};