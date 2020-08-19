#include<bits/stdc++.h>
#pragma gcc optimize("ofast")
using namespace std;
typedef long long int lli;
#define mod 1000000007
#define fLoop for(lli i = 0; i < N; i++)
void pyramidFirst(int N) {
    for (int i = 0; i < N; i++) {  
        for (int j = 0; j <= i; j++) {  
            cout << "* "; 
        }
        cout << '\n'; 
    }
    cout << '\n';
}
void pyramidSec(int N) { 
    int K = 2 * N - 2; 
    for (int i = 0; i < N; i++) { 
        for (int j = 0; j < K; j++) 
            cout << " "; 
        K -= 2; 
        for (int j = 0; j <= i; j++) { 
            cout << "* "; 
        } 
        cout << '\n'; 
    } 
    cout << '\n';
}
void pyramidTraingale(int N) { 
    int k = N - 1; 
    for (int i = 0; i < N; i++) { 
        for (int j = 0; j < k; j++) 
            cout << " "; 
        k--; 
        for (int j = 0; j <= i; j++) { 
            cout << "* "; 
        } 
        cout << endl; 
    } 
    cout << '\n';
}
void solidRhombus(int rows) { 
    for (int i = 1; i <= rows; i++) { 
        for (int j = 1; j <= rows - i; j++) 
            cout << " ";  
        for (int j = 1; j <= rows; j++) 
            cout << "*"; 
        cout << '\n'; 
    }
    cout << '\n';
}
void hollowRhombus(int rows) { 
    for (int i = 1; i <= rows; i++) { 
        for (int j = 1; j <= rows - i; j++) 
            cout << " "; 
        if (i==1 || i==rows) {
            for (int j = 1; j <= rows; j++) 
                cout << "*"; 
		} 
        else {
        	for (int j = 1; j <= rows; j++) {
                if (j == 1 || j == rows) 
                    cout << "*";   
                else
                    cout << " ";
            }
		}
        cout << '\n'; 
    }
    cout << '\n';
}
void swastika(int row, int col) { 
	for (int i = 0; i < row; i++) { 
    	for (int j = 0; j < col; j++) { 
            if (i < row / 2) { 
                if (j < col / 2) { 
        			if (j == 0) 
            			cout << "*";
					else
          			  cout << " " << " "; 
        		} else if (j == col / 2) 
        			cout << " *"; 
				else {
					if (i == 0) 
            			cout << " *"; 
        		} 
    		} else if (i == row / 2) 
        		cout << "* "; 
    		else { 
       			 if (j == col / 2 || j == col - 1) 
       				 cout << "* "; 
        		else if (i == row - 1) { 
       				 if (j <= col / 2 || j == col - 1) 
            			cout << "* "; 
        			else
            			cout << " " << " "; 
        		}  
        		else
        			cout << " " << " "; 
    		} 
    } 
    cout << '\n'; 
	}
	cout << '\n';
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    pyramidFirst(N);
    pyramidSec(N);
    pyramidTraingale(N);
    solidRhombus(N);
    hollowRhombus(N);
    if(N % 2 != 0)
    	swastika(N, N);
}
