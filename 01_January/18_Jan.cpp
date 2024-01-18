//70. Climbing Stairs
#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
    int dp(int n, vector<int> &dP){
        if(n==1 || n==0)
            return 1;
        if(dP[n]!=-1)
            return dP[n];
        return dP[n]=dp(n-1,dP)+dp(n-2,dP);
    }
public:
    int climbStairs(int n) {
        vector<int> dP(n+1,-1);
        return dp(n,dP);
    }
};