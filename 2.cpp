//--------- FROG 2 ---------//

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
 
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
 
    int dp[n] = {0};
 
    dp[0] = 0;
    dp[1] = abs(v[1] - v[0]);
 
    for(int i = 2; i < n; i++) {        
        if(i + 1 <= k) {
            dp[i] = dp[i - 1] + abs(v[i] - v[i - 1]);
            for(int j = 0; j < i; j++) {                
                dp[i] = min(dp[j] + abs(v[i] - v[j]), dp[i]);
            }
        } else {
            dp[i] = dp[i - 1] + abs(v[i] - v[i - 1]);
            for(int j = i - k; j < i; j++) {
                dp[i] = min(dp[j] + abs(v[i] - v[j]), dp[i]);                   
            }
        }
    }
 
    // for(int i = 0; i < n; i++) {
    //     cout << dp[i] << " ";
    // }
    cout << dp[n - 1];
 
    return 0;
}