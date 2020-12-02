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
    int maxDepth(TreeNode* root) {
         if(root == NULL)
            return 0;
        int maxDLeft = maxDepth(root->left);
        int maxDRight = maxDepth(root->right);
        return (maxDLeft >= maxDRight? maxDLeft : maxDRight) + 1;
    }
};
