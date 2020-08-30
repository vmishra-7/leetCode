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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int preS, int preE, int inS, int inE) {
        if(preS > preE) {
            return NULL;
        }
        TreeNode* newNode = new TreeNode(preorder[preS]);
        int rootIndex = 0;
        for(int i = inS; i <= inE; i++) {
            if(preorder[preS] == inorder[i]) {
                rootIndex = i;
                break;
            }
        }
        int leftPreEi = preS + rootIndex - inS;
        newNode -> left = buildTree(preorder, inorder, preS + 1, leftPreEi, inS, rootIndex - 1);
        newNode -> right = buildTree(preorder, inorder, leftPreEi + 1, preE, rootIndex + 1, inE);
        return newNode;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
};
