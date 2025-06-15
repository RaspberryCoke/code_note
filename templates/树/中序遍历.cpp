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
 */
class Solution {
public:// inorder
    vector<int> inorderTraversal(TreeNode* root) {
        if(root==nullptr)return {};
        stack<TreeNode*> s;
        vector<int> res;
        auto node=root;
        while(node!=nullptr||!s.empty())
        {
            while(node!=nullptr)
            {
                s.push(node);
                node=node->left;
            }
            node=s.top();
            s.pop();
            res.push_back(node->val);
            node=node->right;
        }
        return res;
    }
};