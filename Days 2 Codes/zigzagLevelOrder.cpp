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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL) {
            return {};
        }
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        s1.push(NULL);
        s1.push(root);
     // s2.push(NULL);
        int level = 0;
        vector<vector<int>> output;
        vector<int> temp;
        while(!s1.empty() || !s2.empty()) {
            TreeNode* front;
            if(level % 2 == 0) {
              front = s1.top();
              s1.pop();
            }
            else{
              front = s2.top();
              s2.pop();
            }
            if(front == NULL) {
                if(!s1.empty() || !s2.empty())
                 output.push_back(temp);
                temp.clear();
                level++;
            }
            if(front != NULL){
              temp.push_back(front -> val);

              if(level % 2 == 0) {
                if(s2.empty()) {
                  s2.push(NULL);
                }
                if(front -> left != NULL){
                    s2.push(front -> left);
                }
                if(front -> right != NULL){
                  s2.push(front -> right);
                }
              }
              else{
                if(s1.empty()) {
                  s1.push(NULL);
                }
                if(front -> right != NULL){
                  s1.push(front -> right);
                }
                if(front -> left != NULL){
                    s1.push(front -> left);
                }
              }
            }
        }
        return output;
    }
};
