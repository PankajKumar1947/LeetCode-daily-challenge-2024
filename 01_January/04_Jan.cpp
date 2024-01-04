//2870. Minimum Number of Operations to Make Array Empty
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int>mpp;//mpp to store the count
        for(int i=0;i<nums.size();i++)
            mpp[nums[i]]++;

        int ans=0;
        for(auto it:mpp){
            if(it.second==1)
                return -1;//not possible to empty the array
            if(it.second%3==0){
                ans+=it.second/3;
            }
            else if(it.second%3==1 || it.second%3==2){
                ans+=it.second/3+1;
            }
        }
        return ans;
    }
};