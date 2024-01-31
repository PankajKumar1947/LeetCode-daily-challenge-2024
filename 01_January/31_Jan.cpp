//739. Daily Temperatures
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        vector<int> ans;
        int lastInd=-1;
        for(int i=0;i<temp.size();i++){
            if(lastInd!=-1 && temp[i]<temp[lastInd] && temp[i]>=temp[i-1]){
                if(i==temp.size()-1)
                    ans.push_back(0);
                else
                    ans.push_back(lastInd-i);
                continue;
            }
            int j=i+1;
            for(j=i+1;j<temp.size();j++){
                if(temp[j]>temp[i]){
                    ans.push_back(j-i);
                    lastInd=j;
                    break;
                }
            }
            if(j==temp.size()){
                ans.push_back(0);
                lastInd=-1;
            }
        }
        return ans;
    }
};