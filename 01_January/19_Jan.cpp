//931. Minimum Falling Path Sum
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>>dp(matrix.size(),vector<int>(n,-1));
        
        for(int j=0;j<n;j++){
            dp[0][j]=matrix[0][j];
        }

        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                int up=matrix[i][j]+dp[i-1][j];
                int leftUp=1e9;
                int rightUp=1e9;
                if(j-1>=0)
                    leftUp=matrix[i][j]+dp[i-1][j-1];
                if(j+1<n)
                    rightUp=matrix[i][j]+dp[i-1][j+1];
                dp[i][j]=min(up,min(leftUp,rightUp));
            }
        }

        //finding mini
        int mini=dp[n-1][0];
        for(int j=1;j<n;j++){
            mini=min(dp[n-1][j],mini);
        }
        return mini;
    }
};