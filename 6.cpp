//--------- F. LCS ---------//

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
 
int dp[3001][3001];
 
int main() {
 
    string s1, s2;
    cin >> s1 >> s2;    
 
    int n = s1.size(), m = s2.size();        
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            dp[i][j] = 0;
        }
    }        
 
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }     

    // for(int i = 0; i <= n; i++) {
    //     for(int j = 0; j <= m; j++) {
    //         cout << dp[i][j] << " ";
    //     } cout << endl;
    // }
     
    string ans = "";
    int val = dp[n][m];    
    for(int i = n; i >= 0; i--) {
        bool flag = false;
        for(int j = m; j >= 0; j--) {            
            if(dp[i][j - 1] != dp[i][j] && dp[i - 1][j] != dp[i][j]) {
                if(val == dp[i][j] && flag == false) {
                    ans += s1[i - 1];
                    val = dp[i - 1][j - 1];
                    flag = true;
                }
            }            
        }        
    }
 
    reverse(ans.begin(), ans.end());
    cout << ans;
 
    return 0;
}