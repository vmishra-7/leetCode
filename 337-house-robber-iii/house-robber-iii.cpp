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
    int rob(TreeNode* root, bool robbed, map<pair<TreeNode*, bool>, int> &DP) {
        if(root == NULL) {
            return 0;
        }
        pair<TreeNode*, bool> temp = make_pair(root, robbed);
        if(DP.count(temp) > 0) {
            return DP[temp];
        }
        if(robbed) {
            return DP[temp] = rob(root -> left, false, DP) + rob(root -> right, false, DP);
        }
        int robInc = rob(root -> left, true, DP) + rob(root -> right, true, DP) + root -> val;
        int robExc = rob(root -> left, false, DP) + rob(root -> right, false, DP);
        return DP[temp] = max(robInc, robExc);
    }
    int rob(TreeNode* root) {
        map<pair<TreeNode*, bool>, int> DP;
        return rob(root, false, DP);
    }
};