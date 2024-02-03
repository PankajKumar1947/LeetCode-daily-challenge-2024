//1043. Partition Array for Maximum Sum
#include<bits/stdc++.h>
using namespace std;

//memoisation
class Solution {
    int recur(int ind,int k,vector<int>&arr,vector<int>&dp){
        int n=arr.size();
        //base case
        if(ind>=n)
            return 0;
        
        if(dp[ind]!=-1)
            return dp[ind];

        int maxi=0,pick=0;
        for(int i=ind;i<min(ind+k,n);i++){
            maxi=max(maxi,arr[i]);
            pick=max(pick,(i-ind+1)*maxi+recur(i+1,k,arr,dp));
        }
        return dp[ind]= pick;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int>dp(arr.size()+1,-1);
        return recur(0,k,arr,dp);
    }
};

//Tabulation
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>dp(arr.size()+1,0);

        for(int ind=n-1;ind>=0;ind--){
            int maxi=arr[ind],pick=0;
            for(int i=ind;i<min(ind+k,n);i++){
                maxi=max(maxi,arr[i]);
                pick=max(pick,(i-ind+1)*maxi+dp[i+1]);
            }
            dp[ind]= pick;
        }

        return dp[0];
    }
};