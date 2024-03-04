#include<bits/stdc++.h>
using namespace std;

//2864. Maximum Odd Binary Number
class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int cntOne=0,cntZero=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='0')
                cntZero++;
            else
                cntOne++;
        }

        string ans="";
        while(cntOne!=1){
            ans+="1";
            cntOne--;
        }
        while(cntZero){
            ans+="0";
            cntZero--;
        }
        ans+="1";

        return ans;
    }
};