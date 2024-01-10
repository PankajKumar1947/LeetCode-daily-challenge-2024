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

//2385. Amount of Time for Binary Tree to Be Infected
class Solution {
    //converting tree to graph
    void build_Graph(TreeNode* root, vector<vector<int>>&adj){
        if(root==NULL)
            return ;
        
        int curr=root->val;
        //left
        if(root->left){
            int leftVal=root->left->val;
            adj[leftVal].push_back(curr);
            adj[curr].push_back(leftVal);
            build_Graph(root->left,adj);
        }
        //right
        if(root->right){
            int rightVal=root->right->val;
            adj[rightVal].push_back(curr);
            adj[curr].push_back(rightVal);
            build_Graph(root->right,adj);
        }
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        vector<vector<int>> adj(100001);
        build_Graph(root,adj);

        //bfs traversal
        int vis[100001]={0};
        vis[start]=1;

        queue<pair<int,int>>q;
        q.push({start,0});

        int ans=0;
        while(!q.empty()){
            auto [node,dd]=q.front();
            ans=max(ans,dd);
            q.pop();

            for(auto it:adj[node]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push({it,dd+1});
                }
            }
           
        }

        return ans;      
    }
};