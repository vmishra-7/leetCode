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
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL) {
            return {};
        }
        queue<TreeNode*> Q;
        Q.push(root);
        Q.push(NULL);
        vector<int> output;
        map<int, int> M;
        int i = 0;
        while(!Q.empty()) {
            TreeNode* front = Q.front();
            Q.pop();
            if(front == NULL) {
                i++;
                if(!Q.empty()) {
                    Q.push(NULL);
                }
            }
            if(front != NULL) {
                M[i] = front -> val;
                if(front -> left != NULL) {
                    Q.push(front -> left);
                }
                if(front -> right != NULL) {
                    Q.push(front -> right);
                }
            }
        }
        map<int, int> :: iterator it;
        for(it = M.begin(); it != M.end(); it++) {
            output.push_back(it -> second);
        }
        return output;
    }
};
