//169. Majority Element
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mpp;
        for(auto it:nums){
            mpp[it]++;
            if(mpp[it]>nums.size()/2)
                return it;
        }
        return -1;
    }
};