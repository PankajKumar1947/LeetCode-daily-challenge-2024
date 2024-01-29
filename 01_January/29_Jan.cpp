//232. Implement Queue using Stacks
#include<bits/stdc++.h>
using namespace std;

class MyQueue {
    //st1-> push and st2-> pop
    stack<int> st1,st2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
        int t=st2.top();
        st2.pop();

        //push back into the st1
        while(!st2.empty()){
            st1.push(st2.top());
            st2.pop();
        }
        return t;
    }
    
    int peek() {
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
        int tp =st2.top();

        //push back into the stackl
        while(!st2.empty()){
            st1.push(st2.top());
            st2.pop();
        }
        return tp;
    }
    
    bool empty() {
        return st1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */