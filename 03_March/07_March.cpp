//876. Middle of the Linked List
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
    ListNode* middleNode(ListNode* head) {
        ListNode* result=new ListNode(0);
        ListNode* ptr=result;
        int count=0,count2=0;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            count++;
            temp=temp->next;
        }
        int middle=(count+2)/2;
        temp=head;
        while(temp!=NULL)
        {
            count2++;
            if(count2>=middle)
            {
                ptr->next= new ListNode(temp->val);
                ptr=ptr->next;
            }
            temp=temp->next;
        }
        return result->next;
    }
};