//--------- D. KNAPSACK 1 ---------//

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

    ll n, W;
    cin >> n >> W;
    vector<ll> v, w;
    for(int i = 0; i < n; i++) {
        ll vi, wi;
        cin >> wi >> vi;
        w.push_back(wi);
        v.push_back(vi);        
    } 

    ll dp[n + 1][W + 1];

    for(ll i = 0; i < n + 1; i++) {
        for(ll j = 0; j < W + 1; j++) {
            dp[i][j] = 0;
        }
    }    

    for(ll i = 1; i <= n; i++) {
        for(ll j = 1; j <= W; j++) {            
            if(w[i - 1] <= j) {
                dp[i][j] = max(dp[i - 1][j], v[i - 1] + dp[i - 1][j - w[i - 1]]);                
                // cout << w[i - 1] << " ";
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << dp[n][W];

    return 0;
}