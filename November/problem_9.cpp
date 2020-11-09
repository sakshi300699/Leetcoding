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
    int maxAncestorDiff(TreeNode* root) {
         int res = 0;
    stack<int> minval, maxval;
    // end
    
    stack<TreeNode *> st;
    TreeNode *last = nullptr;
    while (root != nullptr || !st.empty()) 
    {
        if (root != nullptr)
        {
            // addition to iterative postorder traversal
            if (minval.empty()) {
                minval.push(root->val);
            } else {
                minval.push(min(root->val, minval.top()));
            }
            if (maxval.empty()) {
                maxval.push(root->val);
            } else {
                maxval.push(max(root->val, maxval.top()));
            }
            // end
            st.push(root);
            root = root->left;
        } 
        else
        {
            TreeNode *curr = st.top();
            if (curr->right && curr->right != last)
            {
                root = curr->right;
            }
            else
            {
                // addition to iterative postorder traversal
                int currmin = minval.top();
                minval.pop();
                int currmax = maxval.top();
                maxval.pop();
                res = max(res, currmax - currmin);
                // end
                last = curr;
                st.pop();
            }
        }
    }
    
    return res;
    }
};
