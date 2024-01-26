//576. Out of Boundary Paths
#include<bits/stdc++.h>
using namespace std;

class Solution {
    int mod=1e9+7;
    int recur(int m,int n, int maxMove,int startRow,int startCol,vector<vector<vector<int>>>&dp){
        //base case
        if(maxMove<0)
            return 0;
        if(startRow==-1 || startCol==-1 || startRow==m || startCol==n)
            return 1;
        
        if(dp[maxMove][startRow][startCol]!=-1)
            return dp[maxMove][startRow][startCol]%mod;

        //find ans
        int top=recur(m,n,maxMove-1,startRow-1,startCol,dp)%mod;
        int left=recur(m,n,maxMove-1,startRow,startCol-1,dp)%mod;
        int bottom=recur(m,n,maxMove-1,startRow+1,startCol,dp)%mod;
        int right=recur(m,n,maxMove-1,startRow,startCol+1,dp)%mod;

        return dp[maxMove][startRow][startCol]=((top+left)%mod+(bottom+right)%mod)%mod;
    }
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>>dp(maxMove+1,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return recur(m,n,maxMove,startRow,startColumn,dp);
    }
};