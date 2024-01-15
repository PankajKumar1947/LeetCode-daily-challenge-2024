//2225. Find Players With Zero or One Losses
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans(2);
        unordered_map<int,int>win,loss;
        for(int i=0;i<matches.size();i++){
            win[matches[i][0]]++;
            loss[matches[i][1]]++;
        }

        //win
        for(auto it:win){
            if(loss[it.first]==0)
                ans[0].push_back(it.first);
        }

        for(auto it: loss){
            if(it.second==1)
                ans[1].push_back(it.first);
        }
        for(int i=0;i<2;i++){
            sort(ans[i].begin(),ans[i].end());
        }

        return ans;
    }
};