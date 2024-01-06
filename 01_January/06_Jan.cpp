//1235. Maximum Profit in Job Scheduling
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=startTime.size();
        vector<vector<int>>ds;
        for(int i=0;i<n;i++)
            ds.push_back({startTime[i],endTime[i],profit[i]});
        sort(startTime.begin(),startTime.end());
        sort(ds.begin(),ds.end());//sorted on the basis of startTime

        vector<int> dp(n+1,-1);
        dp[n]=0;

        for(int ind=n-1;ind>=0;ind--){
            int nextInd=lower_bound(startTime.begin(),startTime.end(),ds[ind][1])-startTime.begin();    
            int pick=ds[ind][2]+dp[nextInd];
            int notPick=dp[ind+1];

            dp[ind]= max(pick,notPick);
        }
        return dp[0];
    }
};