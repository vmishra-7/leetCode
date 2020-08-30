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
    void flatten(TreeNode* root, TreeNode *&prev) {
        if(root == NULL) {
            return;
        }
        TreeNode* rightRoot = root -> right;
        if(prev == NULL) {
            prev = root;
        } else {
            prev -> left = NULL;
            prev -> right = root;
            prev = root;
        }
        flatten(root -> left, prev);
        flatten(rightRoot, prev);
    }
    void flatten(TreeNode* root) {
        TreeNode *prev = NULL;
        flatten(root, prev);
    }
};
