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
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == NULL) {
            return {};
        }
        stack<TreeNode*> Q;
        vector<int> output;
        Q.push(root);
        while(!Q.empty()) {
            TreeNode* front = Q.top();
            while(front -> left != NULL) {
                TreeNode *curr = front;
                Q.push(front -> left);
                front = front -> left;
                curr -> left = NULL;
            }
            output.push_back(front -> val);
            Q.pop();
            if(front -> right != NULL) {
                Q.push(front -> right);
            }
        }
        return output;
    }
};
