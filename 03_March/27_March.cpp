//713. Subarray Product Less Than K
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int left=0,right=0;
        int product=1,ans=0;

        if(k<=1)
            return 0;
        
        while(right<nums.size()){
            product*=nums[right];
            while(product>=k){
                product/=nums[left];
                left++;
            }
            ans+=1+right-left;
            right++;
        }
        return ans;
    }
};