//1750. Minimum Length of String After Deleting Similar Ends
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumLength(string s) {
        int low=0,high=s.length()-1;
        while(low<high){
            char ch=s[low];
            bool check=false;
            while(low<=high && s[high]==ch){
                check=true;
                high--;
            }

            if(check){
                while(low<=high && s[low]==ch){
                    low++;
                }
            }
            else
                return high-low+1;
        }
        return high-low+1;
    }
};