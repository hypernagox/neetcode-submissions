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
public:
    vector<TreeNode*> cand;
    void GO(TreeNode* root, vector<int>& v)
    {
        if(!root)return;
        GO(root->left, v);
        GO(root->right, v);
        v.emplace_back(root->val);
    }
    void GO(TreeNode* root, const int target)
    {
        if(!root)return;
        if(root->val == target)
        {
            cand.emplace_back(root);
        }
        GO(root->left, target);
        GO(root->right, target);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        vector<int> v1,v2;
        v1.reserve(101);v2.reserve(101);
        GO(subRoot,v2);
        GO(root,subRoot->val);
        for(const auto r : cand)
        {
            GO(r, v1);
            if(v1 == v2)return true;
            v1.clear();
        }
        return false;
    }
};
