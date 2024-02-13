//2108. Find First Palindromic String in the Array
#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool checkPalind(string str,int start,int end){
        if(start>=end)
            return true;
        return str[start]==str[end] && checkPalind(str,start+1,end-1);
    }
public:
    string firstPalindrome(vector<string>& words) {
        for(int i=0;i<words.size();i++){
            if(checkPalind(words[i],0,words[i].size()-1))
                return words[i];
        }
        return "";
    }
};