//2966. Divide Array Into Arrays With Max Difference
#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool check(vector<int>&nums,int i,int j,int k){
        if(nums[i+1]-nums[i]>k)
            return false;
        if(nums[i+2]-nums[i+1]>k)
            return false;
        if(nums[i+2]-nums[i]>k)
            return false;
        return true;
    }
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n=nums.size();
        if(n%3!=0)
            return {};
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size();i=i+3){
            if(check(nums,i,i+2,k)==true)
                ans.push_back({nums[i],nums[i+1],nums[i+2]});
            else
                return {};
            
        }
        return ans;
        
        
    }
};