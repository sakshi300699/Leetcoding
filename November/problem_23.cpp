class Solution {
public:
    int rob(TreeNode* root) {
        return root ? max(root->val + (root->left ? rob(root->left->left) + rob(root->left->right) : 0) + (root->right ? rob(root->right->left) + rob(root->right->right) : 0), rob(root->left) + rob(root->right)) : 0;
    }
};
