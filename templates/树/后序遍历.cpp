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
 * 
 * https://www.bilibili.com/video/BV18i4y1Z7am/?vd_source=b5092550b66226a8a4ffab5161b03f6a
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(root==nullptr)return{};
        vector<int> res;
        TreeNode* node=root;
        TreeNode* prev=root;
        stack<TreeNode*> s;
        while(node!=nullptr||!s.empty())
        {
            while(node!=nullptr)
            {
                s.push(node);
                node=node->left;
            }
            node=s.top();
            if(node->right!=nullptr&&prev!=node->right)
            {
                node=node->right;
            }else{
                prev=node;
                res.push_back(node->val);
                node=nullptr;
                s.pop();
            }
        }
        return res;
    }
};