//--------- H. GRID 1 ---------//

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M ((int)1e9 + 7)

string toBinary(int n) {
    string r;
    while(n != 0){
        r = (n % 2 == 0 ? "0" : "1" ) + r;
        n /= 2;
    }
    return r;
}

ll dp[1001][1001];

int main() {

    ll h, w;
    cin >> h >> w;
    
    for(int i = 0; i <= h; i++) {
        for(int j = 0; j <= w; j++) {
            dp[i][j] = 0;
        }
    }

    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            char x;
            cin >> x;
            if(x == '#') {
                dp[i][j] = -1;
            }
        }
    }

    // Base case
    if(dp[h - 2][w - 1] != -1) dp[h - 2][w - 1] = 1;
    if(dp[h - 1][w - 2] != -1) dp[h - 1][w - 2] = 1; 

    for(int i = h - 1; i >= 0; i--) {
        for(int j = w - 1; j >= 0; j--) {
            if(dp[i][j] == 0) {
                if(dp[i + 1][j] == -1 && dp[i][j + 1] != -1) {
                    dp[i][j] = dp[i][j + 1] % M;
                } else if(dp[i][j + 1] == -1 && dp[i + 1][j] != -1) {
                    dp[i][j] = dp[i + 1][j] % M;
                } else if(dp[i][j + 1] == -1 && dp[i + 1][j] == -1) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = ((dp[i + 1][j] % M) + (dp[i][j + 1] % M)) % M;
                }
            }
        }
    }

    cout << dp[0][0] << endl;

    return 0;
}