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
   bool help(TreeNode* root, int ninf, int pinf) {
        if(root == NULL) {
            return true;
        }
    
        if((root -> val <= ninf) || root -> val >= pinf) {
            return false;
        }
        
        return (help(root -> left, ninf, root -> val) && help(root -> right, root -> val, pinf));
        
    }
    
    bool isValidBST(TreeNode* root) {
        
        if((root == NULL) || (root -> left == NULL && root -> right == NULL))
            return true;      
        return help(root, INT_MIN, INT_MAX);
    }
};
