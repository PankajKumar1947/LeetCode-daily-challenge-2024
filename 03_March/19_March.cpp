//621. Task Scheduler
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int freq[26]={0};
        for(int i=0;i<tasks.size();i++){
            freq[tasks[i]-'A']++;
        }
        sort(begin(freq),end(freq));

        //traverse from back
        int temp1=freq[25]-1;
        int temp2=temp1*n;

        for(int i=24;i>=0;i--){
            temp2-=min(temp1,freq[i]);
        }

        return temp2<0 ? tasks.size() : tasks.size()+temp2;
    }
};