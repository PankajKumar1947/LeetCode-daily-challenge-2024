//1704. Determine if String Halves Are Alike

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int countVowels(string s ,int start, int end){
        int cnt=0;
        for(int i=start;i<end;i++){
            if(s[i]=='a' || s[i]=='A' ||
                s[i]=='e' || s[i]=='E' ||
                s[i]=='i' || s[i]=='I' ||
                s[i]=='o' || s[i]=='O' ||
                s[i]=='u' || s[i]=='U'
                )
                    cnt++;
        }
        return cnt;
    }
public:
    bool halvesAreAlike(string s) {
        int start=0;
        int end=s.length();
        return countVowels(s,0,end/2)==countVowels(s,end/2,end);
    }
};