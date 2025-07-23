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
    void reverse(ListNode* node){
        ListNode* temp=node;
        ListNode* prev=NULL;
        while(temp!=NULL){
            ListNode* front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;

        }
    }
    ListNode* f(ListNode* temp,int k){
        k--;
        while(temp!=NULL && k>0){
            k--;
            temp=temp->next;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* prev=NULL;
        while(temp!=NULL){
            ListNode* kthnode=f(temp,k);
            if(kthnode==NULL){
                prev->next=temp;
                break;
            }
            else{
                ListNode* nextnode=kthnode->next;
                kthnode->next=NULL;
                reverse(temp);
                if(temp==head){
                    head=kthnode;
                }
                else{
                    prev->next=kthnode;
                }
                prev=temp;
                temp=nextnode;

            }
        }
        return head;
    }
};