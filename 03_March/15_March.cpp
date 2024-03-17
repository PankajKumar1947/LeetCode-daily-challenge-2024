//238. Product of Array Except Self
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefMul,suffMul(n,1);
        prefMul.push_back(nums[0]);
        for(int i=1;i<n;i++){
            prefMul.push_back(nums[i]*prefMul[i-1]);
        }
        suffMul[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            suffMul[i]=suffMul[i+1]*nums[i];
        }

        vector<int> ans(n,0);
        ans[0]=suffMul[1];
        ans[n-1]=prefMul[n-2];
        for(int i=1;i<n-1;i++){
            ans[i]=prefMul[i-1]*suffMul[i+1];
        }
        
        return ans;
    }
};