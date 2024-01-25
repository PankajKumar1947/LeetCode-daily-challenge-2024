//1143. Longest Common Subsequence
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size();
        int n=text2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        vector<int>prev(n+1,0),cur(n+1,0);

        //base case
        for(int j=0;j<=n;j++){
            prev[j]=0;
        }

        for(int ind1=1;ind1<=m;ind1++){
            for(int ind2=1;ind2<=n;ind2++){
                if(text1[ind1-1]==text2[ind2-1])
                    cur[ind2]=1+prev[ind2-1];
                else
                     cur[ind2] = max(prev[ind2],cur[ind2-1]);
            }
            prev=cur;
        }
        return prev[n];
    }
};