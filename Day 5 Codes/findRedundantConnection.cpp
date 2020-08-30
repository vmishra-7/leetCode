class Solution {
public:
    int unionFind(int *parent, int X) {
        if(X == parent[X]) {
            return X;
        }
        int Y =  unionFind(parent, parent[X]);
	    parent[X] = Y;
	    return Y;
    }
    void makeUnion(int *parent, int *rank, int X, int Y) {
        int xP = unionFind(parent, X), yP = unionFind(parent, Y);
        if(xP == yP) {
            return;
        }
        if(rank[xP] > rank[yP]) {
            parent[yP] = xP;
        } else {
            parent[xP] = yP;
        }
        if(rank[xP] == rank[yP]) {
            rank[yP]++;
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int *parent = new int[1001];
        int *rank = new int[1001];
        for(int i = 0; i < 1001; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
        for(int i = 0; i < edges.size(); i++) {
            int parentI = unionFind(parent, edges[i][0]);
            int parentJ = unionFind(parent, edges[i][1]);
          //  cout << parentI << " " << parentJ << '\n';
            if(parentI == parentJ) {
                vector<int> output;
                output.push_back(edges[i][0]);
                output.push_back(edges[i][1]);
                return output;
            }
           // parent[parentI] = parentJ;
            makeUnion(parent, rank, edges[i][0], edges[i][1]);
        }
        return {};
    }
};
