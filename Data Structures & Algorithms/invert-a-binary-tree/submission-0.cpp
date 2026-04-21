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
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return NULL;
        if (root->left) {
            TreeNode* leftcpy = root->left;
            root->left = root->right;
            root->right = leftcpy;
            if (root->right) {
                invertTree(root->right);
            }
            if (root->left) {
                invertTree(root->left);
            }
            return root;
        }
        if (root->right) {
            TreeNode* rightcpy = root->right;
            root->right = root->left;
            root->left = rightcpy;
            if (root->right) {
                invertTree(root->right);
            }
            if (root->left) {
                invertTree(root->left);
            }
            return root;
        }

        return root;
    }
};
