//--------- A. FROG 1 ---------//

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
 
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
 
    int dp[n] = {0};
 
    dp[0] = 0;
    dp[1] = abs(v[1] - v[0]);
 
    for(int i = 2; i < n; i++) {
        dp[i] = min(dp[i - 1] + abs(v[i] - v[i - 1]), dp[i - 2] + abs(v[i] - v[i - 2]));        
    }
 
    cout << dp[n - 1];
 
    return 0;
}