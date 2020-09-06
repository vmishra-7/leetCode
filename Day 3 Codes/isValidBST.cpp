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
   bool isBST(TreeNode *root, TreeNode *maxV, TreeNode* minV) {
       if(root == NULL) {
           return true;
       }
       if((maxV != NULL && root -> val <= maxV -> val) || (minV != NULL && root -> val >= minV -> val)) {
           return false;
       }
       return isBST(root -> left, maxV, root) && isBST(root -> right, root, minV);
    }
    bool isValidBST(TreeNode* root) {
        if(root == NULL) {
            return true;
        }
        return isBST(root, NULL, NULL);
    }
};
