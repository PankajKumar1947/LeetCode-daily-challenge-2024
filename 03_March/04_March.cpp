//948. Bag of Tokens
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int score=0;
        int ans=0;
        int start=0,end=tokens.size()-1;
        while(start<=end){
            if(tokens[start]<=power){
                power-=tokens[start];
                score+=1;
                start++;
                ans=max(ans,score);
            }
            else if(score>0){
                power+=tokens[end];
                end--;
                score-=1;
            }
            else
                break;
            
        }
        return ans;
    }
};