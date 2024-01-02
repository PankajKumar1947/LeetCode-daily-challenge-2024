//2610. Convert an Array Into a 2D Array With Conditions
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int maxi=0;
        unordered_map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
            maxi=max(maxi,mpp[nums[i]]);
        }

        vector<vector<int>>ans(maxi);
        for(auto it:mpp){
            ans[0].push_back(it.first);
            if(it.second>1){
                for(int i=1;i<it.second;i++){
                    ans[i].push_back(it.first);
                }
            }
        }

        return ans;
    }
};