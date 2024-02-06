//49. Group Anagrams
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> anagramGroups;

        //key: word, value: vector of same word after sorting.
        for(const string& str : strs){
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());
            anagramGroups[sortedStr].push_back(str);
        }

        //Map to vector
        for(const auto& group : anagramGroups) {
            ans.push_back(group.second);
        }

        return ans;
    }
};