//446. Arithmetic Slices II - Subsequence
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        unordered_map<long,int>dp[n];
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<i;j++){
                long diff=(long)nums[i]-nums[j];
                
                auto it =dp[j].find(diff);
                int countAtJ=0;//count at j for difference=diff
                if(it!=end(dp[j]))
                    countAtJ=it->second;

                dp[i][diff]+=countAtJ+1;

                ans+=countAtJ;
            }
        }
        return ans;
    }
};