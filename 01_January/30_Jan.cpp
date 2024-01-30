//150. Evaluate Reverse Polish Notation
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
       stack<int> st;
       for(auto it:tokens){
           if(it=="+" || it=="-" || it=="*" || it=="/"){
               //perform the operation
               int top1=st.top();
               st.pop();
               int top2=st.top();
               st.pop();

               if(it=="+")
                    st.push(top2+top1);
                else if(it=="-")
                    st.push(top2-top1);
                else if(it=="/")
                    st.push(top2/top1);
                else
                    st.push(top2*top1);
           }
           else
            st.push(stoi(it));
       } 
       return st.top();
    }
};