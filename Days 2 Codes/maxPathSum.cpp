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
    pair<int, int> maxPathSumHelper(TreeNode *root) {
        pair<int, int> ans;
        if(root == NULL) {
            ans.first = INT_MIN;
            ans.second = INT_MIN;
            return ans;
        }
        pair<int, int> left = maxPathSumHelper(root -> left);
        pair<int, int> right = maxPathSumHelper(root -> right);
        ans.second = root -> val + max(0, max(left.second, right.second));
        int leftSum = max(0, left.second);
        int rightSum = max(0, right.second);
        ans.first = max(root -> val + leftSum + rightSum, max(ans.second, max(left.second, max(right.second, max(left.first, right.first)))));
        return ans;
    }
    int maxPathSum(TreeNode* root) {
        return maxPathSumHelper(root).first;
    }
};
