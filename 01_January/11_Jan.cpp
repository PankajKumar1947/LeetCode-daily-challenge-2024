#include<bits/stdc++.h>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//1026. Maximum Difference Between Node and Ancestor
class Solution {
    void findAns(TreeNode* root, int mini, int maxi,int &ans){
        if(root==NULL)
            return ;
        
        ans=max(ans,max(abs(root->val-mini),abs(root->val-maxi)));
        mini=min(mini,root->val);
        maxi=max(maxi,root->val);

        findAns(root->left,mini,maxi,ans);
        findAns(root->right,mini,maxi,ans);
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        int mini=root->val;
        int maxi=root->val;
        int ans=INT_MIN;

        findAns(root,mini,maxi,ans);
        return ans;
    }
};