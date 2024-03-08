//3005. Count Elements With Maximum Frequency
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int maxi=0;
        unordered_map<int,int>mpp;
        for(auto it:nums){
            mpp[it]++;
            maxi=max(maxi,mpp[it]);
        }
       int ans=0;
       for(auto it:mpp){
           if(it.second==maxi)
            ans+=it.second;
       }

       return ans;
    }
};