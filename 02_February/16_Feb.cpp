//1481. Least Number of Unique Integers after K Removals
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        for(auto it:arr){
            mp[it]++;
        }

        vector<int> count;
        for(auto it:mp){
            count.push_back(it.second);
        }
        sort(count.begin(),count.end());

        int ans=0;
        for(int i=0;i<count.size();i++){
            if(k>0){
                k=k-count[i];
                if(k<0)
                    ans++;
            }
        
            else
                ans++;
        }

        return ans;
    }
};