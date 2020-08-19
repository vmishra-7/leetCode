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
    int N;
    cin >> N;
    int *input = new int[N];
    for(int i = 0; i < N; i++) {
    	cin >> input[i];
	}
	for(int i = 0; i < N; i++) {
		if(i != input[input[i]]) {
			cout << "False";
			return 0;
		}
	}
	cout << "True";
	return 0;
}
