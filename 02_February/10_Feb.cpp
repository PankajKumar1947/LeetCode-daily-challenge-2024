//647. Palindromic Substrings
#include<bits/stdc++.h>
using namespace std;

class Solution {
    int palid(string s,int st,int end,vector<vector<int>>&dp){
        if(st>end)
            return 1;
        if(dp[st][end]!=-1)
            return dp[st][end];
        return dp[st][end]= s[st]!=s[end] ? 0 : palid(s,st+1,end-1,dp);
    }
public:
    int countSubstrings(string s) {
        int ans=0;
        vector<vector<int>>dp(s.length(),vector<int>(s.length(),-1));
        for(int i=0;i<s.length();i++){
            for(int j=i;j<s.length();j++){
                ans+=palid(s,i,j,dp);
            }
        }
        return ans;
    }
};