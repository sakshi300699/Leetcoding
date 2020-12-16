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
    void traverse(TreeNode* root, vector<int> &s) {
        if (root == nullptr) {
            return;
        }
        traverse(root->left, s);
        s.push_back(root->val);
        traverse(root->right, s);
    }
    bool isValidBST(TreeNode* root) {
        vector <int> s;
        traverse(root, s);
        return (unique(s.begin(), s.end()) == s.end()) && is_sorted(s.begin(), s.end());
    }
};
