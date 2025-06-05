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
 * 输入：root = [1,2,3,4,5,null,8,null,null,6,7,9]

输出：[1,2,4,5,6,7,3,8,9]
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root)return {};
        stack<TreeNode*> s;
        vector<int> res;
        s.push(root);
        while(!s.empty())
        {
            TreeNode* node=s.top();
            s.pop();
            res.push_back(node->val);
            if(node->right)
            {
                s.push(node->right);
            }
            if(node->left)
            {
                s.push(node->left);
            }
        }
        return res;
    }
};