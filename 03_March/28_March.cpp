//2958. Length of Longest Subarray With at Most K Frequency
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int ans=0;
        unordered_map<int,int>mpp;
        int j=0;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
            while(mpp[nums[i]]>k){
                mpp[nums[j]]--;
                j++;
            }
            ans=max(ans,i-j+1);
        }
        return ans;
    }
};