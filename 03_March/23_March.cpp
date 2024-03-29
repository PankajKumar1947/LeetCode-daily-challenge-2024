//143. Reorder List
#include<bits/stdc++.h>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    void reorderList(ListNode* head) {
       vector<int>ans;
       ListNode* temp=head;
       while(temp){
           ans.push_back(temp->val);
           temp=temp->next;
       } 
       int start=0;
       int end=ans.size()-1;
       temp=head;
       int i=0;
       while(temp){
           if(i%2==0){
               temp->val=ans[start];
               start++;
           }
           if(i%2!=0){
               temp->val=ans[end];
               end--;
           }
           temp=temp->next;
           i++;
       }
    }
};