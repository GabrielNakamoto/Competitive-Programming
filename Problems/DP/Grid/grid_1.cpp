/*
 * Author: Gabriel Nakamoto (gabriel@nakamoto.ca)
 * Date: Sat 26 Oct 2024 08:25:21 EDT
 *
 * Problem: Grid 1 (https://atcoder.jp/contests/dp/tasks/dp_h)
 * Type: Dynamic Programming
 *
*/


#include <bits/stdc++.h>

using namespace std;

const int mod=1e9+7;

bool is_wall(int i, int j, vector<string> &a){ return a[i][j] == '#'; }

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m;
    cin>>n>>m;

    vector<vector<int>> dp(n,vector<int>(m));
    vector<string> a(n);
    for(int i=0; i<n; ++i)
        cin>>a[i];

    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            if(is_wall(i,j,a)) continue;
            if(!i&&!j)dp[i][j]=1;
            else if(!i&&j) dp[i][j]=dp[i][j-1];
            else if(!j&&i) dp[i][j]=dp[i-1][j];
            else dp[i][j]=dp[i-1][j]+dp[i][j-1];
            dp[i][j]%=(int)mod;
        }
    }
    cout<<dp[n-1][m-1];

    return 0;
}
