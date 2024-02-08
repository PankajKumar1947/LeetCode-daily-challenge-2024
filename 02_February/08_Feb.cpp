//279. Perfect Squares
#include<bits/stdc++.h>
using namespace std;

//Recursion -> Time Limit exceeded.
class Solution {
    int findAns(int ind,int n,vector<int>& pfS){
        //base case
        if(ind==0){
            if(n>=pfS[ind] && n%pfS[ind]==0)
                return n/pfS[ind];
            return 0;
        }

        int pick=INT_MAX;
        if(n-pfS[ind]>=0)
            pick=1+findAns(ind,n-pfS[ind],pfS);
        int notPick=findAns(ind-1,n,pfS);
        return min(pick,notPick);
    }
public:
    int numSquares(int n) {
        vector<int> pfS;
        for(int i=1;i*i<=n;i++){
            int sq=i*i;
            pfS.push_back(sq);
        }

        return findAns(pfS.size()-1,n,pfS);


    }
};

//Memoisation
class Solution {
    int findAns(int ind,int n,vector<int>& pfS,vector<vector<int>> &dp){
        //base case
        if(ind==0){
            if(n>=pfS[ind] && n%pfS[ind]==0)
                return n/pfS[ind];
            return 0;
        }

        if(dp[ind][n]!=-1)
            return dp[ind][n];

        int pick=INT_MAX;
        if(n-pfS[ind]>=0)
            pick=1+findAns(ind,n-pfS[ind],pfS,dp);
        int notPick=findAns(ind-1,n,pfS,dp);
        return dp[ind][n]= min(pick,notPick);
    }
public:
    int numSquares(int n) {
        vector<int> pfS;
        for(int i=1;i*i<=n;i++){
            int sq=i*i;
            pfS.push_back(sq);
        }

        vector<vector<int>>dp(pfS.size()+1,vector<int>(n+1,-1));

        return findAns(pfS.size()-1,n,pfS,dp);


    }
};