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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int,vector<int>,greater<int>> pq;
        int n=lists.size();
        for(int i=0;i<n;i++){
            ListNode *temp=lists[i];
            while(temp!=NULL){
                pq.push(temp->val);
                temp=temp->next;
            }
        }
        ListNode* start=new ListNode(-1);
        ListNode* x=start;
        while(!pq.empty()){
            ListNode* y=new ListNode(pq.top());
            x->next=y;
            x=x->next;
            pq.pop();


         }
       
        return start->next;
    }
};