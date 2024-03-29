//442. Find All Duplicates in an Array
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            int num=abs(nums[i]);
            int ind=num-1;
            if(nums[ind]<0)
                ans.push_back(num);
            nums[ind]=nums[ind]*-1;
        }
        return ans;
    }
};