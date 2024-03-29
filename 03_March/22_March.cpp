//234. Palindrome Linked List
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
    bool isPalindrome(ListNode* head) {
        vector<int> ans;
        ListNode* temp=head;
        while(temp){
            ans.push_back(temp->val);
            temp=temp->next;
        }
        temp=head;
        reverse(ans.begin(),ans.end());
        int i=0;
        while(temp){
            if(temp->val!=ans[i])
                return false;
                i++;
                temp=temp->next;
        }
        return true;
    }
};