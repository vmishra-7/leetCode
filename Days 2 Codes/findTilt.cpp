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
    int output = 0;
    int findTiltHelper(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        int leftSum = findTiltHelper(root -> left);
        int rightSum = findTiltHelper(root -> right);
        output += abs(leftSum - rightSum);
        return leftSum + rightSum + root -> val;
    }
    int findTilt(TreeNode* root) {
        findTiltHelper(root);
        return output;
    }
};
