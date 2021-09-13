//--------- C. VACATION ---------//

#include <bits/stdc++.h>
using namespace std;
#define ll long long

string toBinary(int n) {
    string r;
    while(n != 0){
        r = (n % 2 == 0 ? "0" : "1" ) + r;
        n /= 2;
    }
    return r;
}

int main() {

    int n, a1, b1, c1;
    cin >> n >> a1 >> b1 >> c1;

    int dp[n][3] = {{0}};            

    // BASE CASE
    dp[0][0] = a1;
    dp[0][1] = b1;
    dp[0][2] = c1;
    
    for(int i = 1; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;    

        dp[i][0] += max(dp[i - 1][1] + a, dp[i - 1][2] + a);
        dp[i][1] += max(dp[i - 1][0] + b, dp[i - 1][2] + b);
        dp[i][2] += max(dp[i - 1][0] + c, dp[i - 1][1] + c);
    }

    cout << max(max(dp[n - 1][0], dp[n - 1][1]), dp[n - 1][2]);

    return 0;
}