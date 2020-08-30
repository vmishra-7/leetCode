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
    int depth(TreeNode* root, int x, TreeNode *&parentX) {
        if(root == NULL) {
            return -1;
        }
        if(root -> val == x) {
            return 0;
        }
        int levelLeft = depth(root -> left, x, parentX);
        if(levelLeft !=  -1) {
            if(levelLeft == 0) {
                parentX = root;
            }
            return levelLeft + 1;
        }
        levelLeft = depth(root -> right, x, parentX);
        if(levelLeft !=  -1) {
            if(levelLeft == 0) {
                parentX = root;
            }
            return levelLeft + 1;
        }
        return -1;
    }
    bool isCousins(TreeNode* root, int x, int y) {
        TreeNode* parentX = NULL;
        TreeNode* parentY = NULL;
        if(depth(root, x, parentX) == depth(root, y, parentY) && parentX != parentY) {
            return true;
        } return false;
    }
};
