//1657. Determine if Two Strings Are Close

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.length()!=word2.length())
            return false;

        unordered_map<char,int>mpp1,mpp2;
        set<char> st1,st2;
        for(int i=0;i<word1.length();i++){
            mpp1[word1[i]]++;
            st1.insert(word1[i]);
        }
        for(int i=0;i<word2.length();i++){
            mpp2[word2[i]]++;
            st2.insert(word2[i]);
        }

        //now find the required
        if(st1!=st2)
            return false;

        vector<int> freq1,freq2;
        for(auto it: mpp1){
            freq1.push_back(it.second);
        }
        for(auto it: mpp2){
            freq2.push_back(it.second);
        }

        sort(freq1.begin(),freq1.end());
        sort(freq2.begin(),freq2.end());
        
        return freq1==freq2;
    }
};