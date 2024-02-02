//1291. Sequential Digits
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>init;

        for(int start=1;start<=9;start++){
            int initial=start;
            for(int i=start+1;i<=9;i++){
                initial=initial*10+i;
                if(initial>=low && initial<=high)
                    init.push_back(initial);
                else if(initial>high)
                    break;     
                
            }
        }

        sort(init.begin(),init.end());

        return init;
    }
};