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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k == 0) return head;
        
        ListNode* temp=head;
        int len=findlength(temp);
        k=k%len;
        ListNode* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }
    tail->next = head;


        int stepsToNewTail = len - k;
    ListNode* newTail = head;
    for (int i = 1; i < stepsToNewTail; i++) {
        newTail = newTail->next;
    }

    
    ListNode* newHead = newTail->next;
    newTail->next = NULL;

    return newHead;
    }
};