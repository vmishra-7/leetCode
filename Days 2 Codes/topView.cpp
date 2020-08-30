// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

void topView(struct Node *root);


int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n,i,k;
        cin>>n;
        i=n;

        Node* root=NULL;
        queue <Node*> q;
        while(i>0)
        {
            int a,b;
            char c;
            cin>> a >> b >> c;
            if(!root){
                root = new Node(a);
                q.push(root);
            }
            Node* pick = q.front();
            q.pop();

            if(c == 'L'){
                pick->left = new Node(b);
                q.push( pick->left );
            }
            cin>> a >> b >> c;
            if(c == 'R'){
                pick->right = new Node(b);
                q.push( pick->right );
            }
            i-=2;
        }
//        inorder(root);
//        cout<<endl;
        topView(root);
        cout << endl;
    }
    return 0;
}




// } Driver Code Ends


//Structure of binary tree
/*struct Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/
// function should print the topView of the binary tree
#include<map>
void topView(struct Node *root, map<int, pair<int, int> > &M, int hD, int D) {
    if(root == NULL) {
        return;
    }
    if(M.count(hD) == 0) {
        pair<int, int> P;
        M[hD] = {root-> data, D};
    } else {
        pair<int, int> P = M[hD];
        if(P.second > D) {
            M[hD] = {root -> data, D};
        }
    }
    topView(root -> left, M, hD - 1, D + 1);
    topView(root -> right, M, hD + 1, D + 1);
}
void topView(struct Node *root) {
    map<int, pair<int, int>> M;
    topView(root, M, 0 , 0);
    map<int, pair<int, int>> :: iterator it;
    for(it = M.begin(); it != M.end(); it++) {
        cout << it -> second.first << " ";
    }
    //Your code here
}


