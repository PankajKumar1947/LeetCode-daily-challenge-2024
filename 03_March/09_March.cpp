//2540. Minimum Common Value
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        for(int i=0;i<nums1.size();i++){
            int low=0;
            int high=nums2.size()-1;
            while(low<=high){
                int mid=(low+high)/2;
                if(nums2[mid]==nums1[i])
                    return nums1[i];
                if(nums2[mid]>nums1[i])
                    high=mid-1;
                else
                    low=mid+1;
            }
        }
        return -1;
    }
};