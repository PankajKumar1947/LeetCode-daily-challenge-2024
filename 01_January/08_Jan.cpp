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

//938. Range Sum of BST
class Solution {
    void preorder(TreeNode* root , int& ans, int low, int high){
        if(root==NULL)
            return ;
        if(root->val >=low && root->val<=high)
            ans+=root->val;
        preorder(root->left,ans,low,high);
        preorder(root->right,ans,low,high);
    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int ans=0;
        preorder(root,ans,low,high);
        return ans;
    }
};