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
    ListNode* deleteDuplicates(ListNode* head) {
        unordered_map<int,int>mp;
        ListNode* temp=head;
        while(temp!=NULL){
            mp[temp->val]++;
            temp=temp->next;
        }
        temp=head;
        vector<int>vec;
        for(auto it:mp){
            if(it.second==1){
                vec.push_back(it.first);
            }
        }
        sort(vec.begin(),vec.end());
        if(vec.size()==0) return NULL;
        ListNode* node=new ListNode(vec[0]);
        ListNode* dummy = new ListNode(0);
        dummy->next = node;
        for(int i=1;i<vec.size();i++){
            node->next=new ListNode(vec[i]);
            node=node->next;

        }
        return dummy->next;
        
    }
};