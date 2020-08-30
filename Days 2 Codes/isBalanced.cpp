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
    pair<bool, int> isBalancedHelper(TreeNode* root) {
        pair<bool, int> P;
        if(root == NULL) {
            P.first = true;
            P.second = 0;
            return P;
        }
        pair<bool, int> left = isBalancedHelper(root -> left);
        pair<bool, int> right = isBalancedHelper(root -> right);
        P.first = false;
        if(left.first && right.first && abs(left.second - right.second) <= 1) {
            P.first = true;;
        }
        P.second = 1 + max(left.second, right.second);
        return P;
    }
    bool isBalanced(TreeNode* root) {
        return isBalancedHelper(root).first;
    }
};
