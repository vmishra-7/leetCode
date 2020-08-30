/* The structure of a BST Node is as follows:

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// Return the root of the modified BST after deleting the node with value X
Node *deleteNode(Node *root,  int X) {
    if(root == NULL) {
        return root;
    }
    if(root -> data > X) {
        root -> left = deleteNode(root -> left, X);
        return root;
    } else if(root -> data < X) {
        root -> right = deleteNode(root -> right, X);
        return root;
    } else {
        if(root -> left == NULL && root -> right == NULL) {
            return NULL;
        }
        if(root -> left != NULL && root -> right == NULL) {
            return root -> left;
        }
        if(root -> left == NULL && root -> right != NULL) {
            return root -> right;
        }
        Node *rightMin = root -> right;
        while(rightMin -> left != NULL) {
            rightMin = rightMin -> left;
        }
        root -> data = rightMin -> data;
        root -> right = deleteNode(root -> right, rightMin -> data);
        return root;
    }
    // your code goes here
}
