//2149. Rearrange Array Elements by Sign
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos;
        vector<int> neg;
        vector<int> modifiedArray;

        for(int i=0;i<nums.size();i++){
            if(nums[i]>0)
              pos.push_back(nums[i]);
            if(nums[i]<0)
               neg.push_back(nums[i]);
        }
        for(int i=0;i<pos.size();i++){
            modifiedArray.push_back(pos[i]);
            modifiedArray.push_back(neg[i]);
        }
        return modifiedArray;
    }
};