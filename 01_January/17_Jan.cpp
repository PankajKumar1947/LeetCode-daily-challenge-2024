//1207. Unique Number of Occurrences
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mpp;
        for(int i=0;i<arr.size();i++){
            mpp[arr[i]]++;
        }
        //now find the answer
        unordered_map<int,int>cnt;
        for(auto it:mpp){
            if(cnt[it.second]>=1)
                return false;
            cnt[it.second]++;
        }

        return true;
    } 
};