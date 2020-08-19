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
    lli N, sum = 0;
    cin >> N;
    lli *input = new lli[N];
    for(lli i = 0; i < N; i++) {
    	cin >> input[i];
    	sum += input[i];
	}
	lli tempSum = 0;
	for(lli i = 0; i < N; i++) {
		sum -= input[i];
		if(sum == tempSum) {
			cout << i << '\n';
			return 0;
		}
		tempSum += input[i];
	}
	return -1;
}
