//1669. Merge In Between Linked Lists
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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* temp=list1;
        int k=b-a+2;
        while(--a){
            temp=temp->next;
        }
        ListNode* temp2=temp;
        while(k--){
            temp2=temp2->next;
        }
        temp->next=list2;
        ListNode* temp3=list2;
        while(temp3->next){
            temp3=temp3->next;
        }
        temp3->next=temp2;
      
        
        return list1 ;
    }
};