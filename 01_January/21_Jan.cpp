//198. House Robber
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        vector<int> dp(nums.size(),-1);
        dp[0]=nums[0];
        dp[1]=nums[1];

        for(int i=2;i<nums.size();i++){
            int first=nums[i]+dp[i-2];
            int second=0;
            if(i>2)
                second=nums[i]+dp[i-3];
            
            dp[i]=max(first,second);
        }
        return max(dp[nums.size()-2],dp[nums.size()-1]);

        
    }
};