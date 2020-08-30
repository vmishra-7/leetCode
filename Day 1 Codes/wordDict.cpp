#include <bits/stdc++.h>
using namespace std;
bool check(string S1, string S2) {
    int j = 0, i = 0;
    while(i < S1.size() && j < S2.size()) {
        if(S1[i] == S2[j]) {
            i++;
        }
        j++;
    }
    if(i == S1.size()) {
        return true;
    } return false;
}
int main() {
	//code
	int T;
	cin >> T;
	while(T--) {
	    int N;
	    cin >> N;
	    vector<string> dict;
	    for(int i = 0; i < N; i++) {
	        string str;
	        cin >> str;
	        dict.push_back(str);
	    }
	    string input;
	    cin >> input;
	    string output = "";
	    for(int i =0; i < N; i++) {
	        if(dict[i].size() > output.size()) {
	            if(check(dict[i], input)) {
	                output = dict[i];
	            }
	        }
	    }
	    cout << output << '\n';
	}
	return 0;
}
