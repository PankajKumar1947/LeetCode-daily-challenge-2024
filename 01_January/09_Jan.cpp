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

//872. Leaf-Similar Trees
class Solution {
    void inorder(TreeNode* root, vector<int>& vt){
        if(root==NULL)
            return;
        inorder(root->left,vt);
        if(root->left==NULL && root->right==NULL)
            vt.push_back(root->val);
        inorder(root->right,vt);

    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>v1,v2;
        inorder(root1,v1);
        inorder(root2,v2);
        return v1==v2;
    }
};