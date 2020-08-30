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
    pair<int, int> diameterOfBinaryTreeHelper(TreeNode* root) {
        pair<int, int> P;
        if(root == NULL) {
            P.first = 0;
            P.second = 0;
            return P;
        }
        pair<int, int> left = diameterOfBinaryTreeHelper(root -> left);
        pair<int, int> right = diameterOfBinaryTreeHelper(root -> right);
        P.second = 1 + max(left.second, right.second);
        P.first = max(left.second + right.second, max(left.first, right.first));
        return P;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return diameterOfBinaryTreeHelper(root).first;
    }
};
