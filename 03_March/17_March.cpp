//57. Insert Interval
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int start=newInterval[0],end=newInterval[1];
        for(int i=0;i<intervals.size();i++){
            if(intervals[i][1]<newInterval[0])
                ans.push_back({intervals[i][0],intervals[i][1]});
            else if(intervals[i][0]>newInterval[1]){
                break;
            }
            else{
                start=min(start,min(intervals[i][0],newInterval[0]));
                end=max(intervals[i][1],newInterval[1]);
            }
        }
       
        ans.push_back({start,end});
        
        for(int i=0;i<intervals.size();i++){
            if(intervals[i][0]>newInterval[1])
                ans.push_back({intervals[i][0],intervals[i][1]});
        }

        return ans;
    }
};