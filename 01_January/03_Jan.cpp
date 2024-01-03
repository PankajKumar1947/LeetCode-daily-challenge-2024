//2125. Number of Laser Beams in a Bank
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans=0;
        int prevCnt=0;
        for(int i=0;i<bank.size();i++){
            int cntOne=0;
            for(int j=0;j<bank[i].size();j++){
                if(bank[i][j]=='1')
                    cntOne++;
            }
            ans+=cntOne*prevCnt;
            if(cntOne!=0)
                prevCnt=cntOne;
        }
        return ans;
    }
};