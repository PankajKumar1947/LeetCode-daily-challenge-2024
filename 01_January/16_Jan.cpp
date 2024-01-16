//380. Insert Delete GetRandom O(1)
#include<bits/stdc++.h>
using namespace std;

class RandomizedSet {
    unordered_map<int,int>hashSet;//key=elem and value=index
    vector<int>nums;
public:
    RandomizedSet() {

    }
    
    bool insert(int val) {
        if(hashSet.find(val)!=hashSet.end())
            return false;
        nums.push_back(val);
        hashSet[val]=nums.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(hashSet.find(val)==hashSet.end())
            return false;
        
        int idx=hashSet[val];
        int lastElement=nums.back();
        nums.back()=val;

        nums[idx]=lastElement;
        hashSet[lastElement]=idx;

        nums.pop_back();
        hashSet.erase(val);
        return true;
    }
    
    int getRandom() {
        int n=nums.size();
        int randomIndex=rand()%n;
        return nums[randomIndex];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */