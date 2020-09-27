
class Trie {
    public :
    vector<Trie*> children;
    bool isWord;
    Trie() {
        for(int i = 0; i < 26; i++) {
            children.push_back(NULL);
        }
        isWord = false;
    }
};
class trieFunction {
    public :
    void addWords(Trie *root, string word) {
        Trie *cur = root;
        for(int i = 0; i < word.size(); i++) {
            int index = word[i] - 'a';
            if(cur -> children[index] == NULL) {
                cur -> children[index] = new Trie();
            }
            cur = cur -> children[index];
        }
        cur -> isWord = true;
    }
    void WS(vector<vector<char>>& board, Trie *root, int i, int j, int N, int M, set<string> &output, string temp) {
        int index = board[i][j] - 'a';
        if(root -> children[index] == NULL) {
            return;
        }
        root = root -> children[index];
        temp += board[i][j];
        if(root -> isWord) {
            output.insert(temp);
        }
        char ch = board[i][j];
        board[i][j] = '*';
        if(i - 1 >= 0 && board[i - 1][j] != '*') {
            WS(board, root, i - 1, j, N, M, output, temp);
        }
        if(i + 1 < N && board[i + 1][j] != '*') {
            WS(board, root, i + 1, j, N, M, output, temp);
        }
        if(j - 1 >= 0 && board[i][j - 1] != '*') {
            WS(board, root, i, j - 1, N, M, output, temp);
        }
        if(j + 1 < M && board[i][j + 1] != '*') {
            WS(board, root, i, j + 1, N, M, output, temp);
        }
        board[i][j] = ch;
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie *root = new Trie();
        trieFunction tF;
        for(int i = 0; i < words.size(); i++) {
            tF.addWords(root, words[i]);
        }
        vector<string> output;
        set<string> tempOutput;
        int N = board.size();
        int M = board[0].size();
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                tF.WS(board, root, i, j, N, M, tempOutput, "");
            }
        }
        for(auto it : tempOutput) {
            output.push_back(it);
        }
        return output;
    }
};
