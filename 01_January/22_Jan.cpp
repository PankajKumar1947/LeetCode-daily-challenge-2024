//645. Set Mismatch
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
                ans.push_back(nums[i]);
                break;
            }
        }
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]!=i+1 && nums[i+1]!=i+1){
                ans.push_back(i+1);
                break;
            }
        }
        if(ans.size()==1)
            ans.push_back(nums.size());

        return ans;
    }
};