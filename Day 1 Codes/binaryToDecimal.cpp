#include<bits/stdc++.h>
#pragma gcc optimize("ofast")
using namespace std;
typedef long long int lli;
#define mod 1000000007
#define fLoop for(lli i = 0; i < N; i++)
lli binaryToDecimal(string input) {
	lli base = 1, output = 0;
	for(int i = input.size() - 1; i >= 0; i--) {
		int bitN = input[i] - '0';
		if(bitN) {
			output += base;
		}
		base *= 2;
	}
	return output;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string input;
    cin >> input;
    cout << binaryToDecimal(input) << '\n';
}
