/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 * 
 * 
 * 输入：root = [3,9,20,null,null,15,7]
   输出：[[3],[9,20],[15,7]]
 * 
 * 
 * 
 */
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
#include<bits/stdc++.h>
#include<iostream>
#include<vector>
class Solution {
public://层序遍历
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)return{};
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            vector<int> tmp;
            int count=q.size();
            for(int i=0;i<count;i++)
            {
                TreeNode* node=q.front();
                q.pop();
                tmp.emplace_back(node->val);
                if(node->left)
                {
                    q.push(node->left);
                }
                if(node->right)
                {
                    q.push(node->right);
                }
            }
            res.emplace_back(move(tmp));
        }
        return res;
    }
};