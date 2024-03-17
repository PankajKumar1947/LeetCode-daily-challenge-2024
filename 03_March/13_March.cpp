//2485. Find the Pivot Integer
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int pivotInteger(int n) {
        if (n==1)
            return 1;
        int sum_till_n = (n * (n+1)) / 2;
        for (int i=2;i<n;++i) {
            int sum_till_i = (i*(i+1))/2;
            if (sum_till_i == sum_till_n-sum_till_i+i)
                return i;
        }
        return -1;
    }
};