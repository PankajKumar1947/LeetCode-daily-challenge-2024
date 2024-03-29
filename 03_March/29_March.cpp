//2962. Count Subarrays Where Max Element Appears at Least K Times
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans=0;
        int maxi=INT_MIN;
        for(auto it:nums)
            maxi=max(it,maxi);

        int maxiFreq=0;
        int left=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==maxi)
                maxiFreq++;
            while(maxiFreq>=k){
                if(nums[left]==maxi)
                    maxiFreq--;
                left++;
            }
            ans+=left;
        }
        return ans;
    }
};