//451. Sort Characters By Frequency
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;//store count of character
        vector<pair<int,char>> mp2;//store char and their counts
        
        for(int i=0;i<s.length();i++)
            mp[s[i]]++;

        for(auto it:mp)
            mp2.push_back({it.second,it.first});

        sort(mp2.begin(),mp2.end());

        string ans="";
        for(int i=mp2.size()-1;i>=0;i--){
            ans.insert(ans.length(),mp2[i].first,mp2[i].second);
        }
    
        return ans;
    }
};