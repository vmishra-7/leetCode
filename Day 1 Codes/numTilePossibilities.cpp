class Solution {
public:
    void numTilePossibilities(string tiles, int index, set<string> &S, string temp, bool *visited) {
        if(index == tiles.size()) {
            return;
        }
        for(int i = 0; i < tiles.size(); i++) {
            if(visited[i] == false) {
                visited[i] = true;
                 S.insert(temp + tiles[i]);
                numTilePossibilities(tiles, index + 1, S, temp + tiles[i], visited);
                visited[i] = false;
            }
        }
    }
    int numTilePossibilities(string tiles) {
        set<string> S;
        bool *visited = new bool[tiles.size()];
        for(int i = 0; i < tiles.size(); i++) {
            visited[i] = false;
        }
        numTilePossibilities(tiles, 0, S, "", visited);
        return S.size();
    }
};
