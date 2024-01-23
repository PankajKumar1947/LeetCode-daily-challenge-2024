//1239. Maximum Length of a Concatenated String with Unique Characters
#include<bits/stdc++.h>
using namespace std;

//Recursion
class Solution {
    bool hasDup(string s1,string s2){
        unordered_map<char,int> count;
        for(int i=0;i<s1.length();i++){
            count[s1[i]]++;
        }

        //now check for char in s2
        for(int i=0;i<s2.length();i++){
            if(count[s2[i]]>=1)
                return false;
            count[s2[i]]++;
        }
        return true;
    }
    int recur(int ind,string temp,vector<string>&arr){
        if(ind>=arr.size())
            return temp.length();
        
        int pick=0;
        int notPick=0;
        if(hasDup(temp,arr[ind])){
            pick=recur(ind+1,temp+arr[ind],arr);
            notPick=recur(ind+1,temp,arr);
        }
        else
            notPick=recur(ind+1,temp,arr);

        return max(pick,notPick);

    }
public:
    int maxLength(vector<string>& arr) {
        string temp="";
        return recur(0,temp,arr);
    }
};

//Memoisation
class Solution {
    bool hasDup(string s1,string s2){
        unordered_map<char,int> count;
        for(int i=0;i<s1.length();i++){
            count[s1[i]]++;
        }

        //now check for char in s2
        for(int i=0;i<s2.length();i++){
            if(count[s2[i]]>=1)
                return false;
            //if chars of s2 doesn't exist in count map.
            count[s2[i]]++;
        }
        return true;
    }
    int recur(int ind,string temp,vector<string>&arr,unordered_map<string,int>&dp){
        if(ind>=arr.size())
            return temp.length();
        
        if(dp.find(temp)!=dp.end())
            return dp[temp];
        int pick=0;
        int notPick=0;
        if(hasDup(temp,arr[ind])){
            pick=recur(ind+1,temp+arr[ind],arr,dp);
            notPick=recur(ind+1,temp,arr,dp);
        }
        else
            notPick=recur(ind+1,temp,arr,dp);

        return dp[temp]= max(pick,notPick);

    }
public:
    int maxLength(vector<string>& arr) {
        string temp="";
        unordered_map<string,int>dp;
        return recur(0,temp,arr,dp);
    }
};