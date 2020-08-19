#include<bits/stdc++.h>
#pragma gcc optimize("ofast")
using namespace std;
typedef long long int lli;
#define mod 1000000007
#define fLoop for(lli i = 0; i < N; i++)
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli N, K;
    cin >> N >> K;
    lli *input = new lli[N];
    for(int i = 0; i < N; i++) {
    	cin >> input[i];
	}
	queue<int> Q;
	for(int i = 0; i < K; i++) {
		if(input[i] < 0) {
			Q.push(i);
		}
	}
	vector<int> output;
	for(int i = K; i < N; i++) {
		if(!Q.empty()) {
			output.push_back(input[Q.front()]);
		} else {
			output.push_back(0);
		}
		while(!Q.empty() && Q.front() <= i - K) {
			Q.pop();
		}
		if(input[i] < 0) {
			Q.push(i);
		}
	}
	if(!Q.empty()) {
		output.push_back(input[Q.front()]);
	} else {
		output.push_back(0);
	}
	for(int i = 0; i < output.size(); i++) {
		cout << output[i] << " ";
	}
	cout << '\n';
}
