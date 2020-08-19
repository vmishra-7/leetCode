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
    lli count = 0, temp = N;
    while(temp != 0) {
    	temp /= 10;
    	count++;
	}
	int output = 0;
	temp = N;
	while(temp != 0) {
		output += pow(temp % 10, count);
		temp /= 10;
	}
	if(output == N) {
		cout << N << " is an armstrong number!" << '\n';
	} else {
		cout << N << " is not an armstrong number" << '\n';
	}
}
	
