/*
 * Author: Gabriel Nakamoto (gabriel@nakamoto.ca)
 * Date: Fri 25 Oct 2024 12:43:55 EDT
 *
 * Problem: Tri-Tiling (https://open.kattis.com/problems/tritiling)
 * Type: Dynamic Programming
 *
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    while(n != -1){
        cin>>n;

        if(n % 2 != 0){
            cout << 0 << '\n';
            continue;
        }

        vector<vector<int>> dp(n+1, vector<int>(8));
        dp[0][7]=1;

        for(int i=1; i<=n; ++i){
            dp[i][0] = dp[i - 1][7];
            dp[i][1] = dp[i - 1][6];
            dp[i][2] = dp[i - 1][5];
            dp[i][3] = dp[i - 1][7] + dp[i - 1][4];
            dp[i][4] = dp[i - 1][3];
            dp[i][5] = dp[i - 1][2];
            dp[i][6] = dp[i - 1][7] + dp[i - 1][1];
            dp[i][7] = dp[i - 1][6] + dp[i - 1][3] + dp[i - 1][0];
        }

        cout << dp[n][7] << '\n';
    }

    return 0;
}
