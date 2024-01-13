//1347. Minimum Number of Steps to Make Two Strings Anagram
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int> countS;
        unordered_map<char,int>countT;
        for(int i=0;i<s.length();i++){
            countS[s[i]]++;
        }
        for(int i=0;i<t.length();i++){
            countT[t[i]]++;
        }

        //now find the ans
        int ans=0;
        for(auto it:countT){
            if(it.second> countS[it.first])
                ans+=it.second-countS[it.first];
        }

        return ans;
    }
};