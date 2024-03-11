//791. Custom Sort String
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string customSortString(string order, string s) {
        string ans="";
        unordered_map<char,int>mp;
        for(int i=0;i<s.length();i++)
            mp[s[i]]++;

        for(int i=0;i<order.length();i++){
            auto it=mp.find(order[i]);
            if(it!=mp.end()){
                int round=it->second;
                while(round){
                    ans+=it->first;
                    round--;
                }
                it->second=-1;
            }
        }

        for(int i=0;i<s.length();i++){
            if(mp[s[i]]!=-1)
                ans+=s[i];
        }

        return ans;
    }
};