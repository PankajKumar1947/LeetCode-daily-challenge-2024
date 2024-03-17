//525. Contiguous Array
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum=0,res=0,n=nums.size();
        unordered_map<int,int>mp;
        mp[0]=-1;
        for(int i=0;i<n;i++){
            sum+=nums[i]?1:-1;
            if(mp.count(sum))res=max(res,i-mp[sum]);
            else mp[sum]=i;
        }
        return res;
    }
};