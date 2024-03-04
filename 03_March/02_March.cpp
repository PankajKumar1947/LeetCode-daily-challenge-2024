//977. Squares of a Sorted Array
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            int val=nums[i]*nums[i];
            if(ans.size()==0)
                ans.push_back(val);
            else{
                int j=0;
                for(j=0;j<ans.size();j++){
                    if(ans[j]>val)
                        break;
                }
                ans.insert(ans.begin()+j,val);
            }
        }

        return ans;
    }
};