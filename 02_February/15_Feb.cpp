//2971. Find Polygon With the Largest Perimeter
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        long long prefSum=0;
        for(auto it: nums){
            prefSum+=it;
        }
        
        for(int i=nums.size()-1;i>=2;i--){
            prefSum-=nums[i];
            if(prefSum>nums[i]){
                return prefSum+nums[i];
            }
        }
        return -1;
    }   
};