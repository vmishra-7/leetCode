#include<bits/stdc++.h>
#pragma gcc optimize("ofast")
using namespace std;
typedef long long int lli;
#define mod 1000000007
#define fLoop for(lli i = 0; i < N; i++)
int minSwaps(int *input, int N, int K) {
	int low = 0, high = 0;
	int count = 0; 
	for (int i = 0; i < N; i++) {
		if (input[i] <= K) {
			low++;
		}
	}
	for (int i = 0; i < low; i++) {
		if (input[i] > K) {
			++high;
		}
	}
	int output = high; 
	for (int i = 0, j = low; j < N; i++, j++) { 
		if (input[i] > K) 
			high--; 
		if (input[j] > K) 
			high++; 
		output = min(output, high); 
	} 
	return output; 
	
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, K;
    cin >> N >> K;
    int *input = new int[N];
    for(int i = 0; i < N; i++) {
    	cin >> input[i];
	}
	cout << minSwaps(input, N, K) << '\n';
}
