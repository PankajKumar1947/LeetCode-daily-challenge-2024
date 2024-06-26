//452. Minimum Number of Arrows to Burst Balloons
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int ans=1;
        int end=points[0][1];
        for(int i=1;i<points.size();i++){
            if(points[i][0]>end){
                ans++;
                end=points[i][1];
            }
            else
                end=min(end,points[i][1]);
        }
        return ans;
    }
};