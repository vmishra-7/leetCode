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
    int N, M;
    cin >> N >> M;
    vector<int> inputA, inputB;
    for(int i = 0; i < N; i++) {
    	int X;
    	cin >> X;
    	inputA.push_back(X);
	}
	for(int i = 0; i < M; i++) {
    	int X;
    	cin >> X;
    	inputB.push_back(X);
	}
	vector<int> output;
	int i = N - 1, j = M - 1;
	int sum = 0;
	while(i >= 0 && j >= 0) {
		sum += (inputA[i] + inputB[j]);
		output.push_back(sum % 10);
		sum /= 10;
		i--;
		j--;
	}
	while(i >= 0) {
		sum += (inputA[i]);
		output.push_back(sum % 10);
		sum /= 10;
		i--;
	}
	while(j >= 0) {
		sum += inputB[j];
		output.push_back(sum % 10);
		sum /= 10;
		j--;
	}
	if(sum) {
		output.push_back(sum);
	}
	for(int i = output.size() - 1; i >= 0; i--) {
		cout << output[i] << " ";
	}
	cout << '\n';
}
