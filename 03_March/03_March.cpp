//19. Remove Nth Node From End of List
#include<bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count=0;
        if(head->next==NULL)
          return NULL;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            temp=temp->next;
            count++;
        }
        temp=head;
        int noLoops=count-n-1;
        if(n==count)
            return head->next;
            
        while(noLoops)
        {
            temp=temp->next;
            noLoops--;
        }
        temp->next=temp->next->next;
        return head;
    }
};