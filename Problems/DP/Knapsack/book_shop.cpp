#include <bits/stdc++.h>

using namespace std;

int w[1001], v[1001];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, x;
    cin>>n>>x;
    for(int i=1; i<=n; ++i)
        cin>>w[i];
    for(int i=1; i<=n; ++i)
        cin>>v[i];

    vector<vector<int>> dp(n+1,vector<int>(x+1));

    for(int i=0; i<=x; ++i)
        dp[0][i]=0;
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=x; ++j){
            dp[i][j]=dp[i-1][j];
            if(w[i]<=j) dp[i][j]=max(dp[i][j],dp[i-1][j-w[i]]+v[i]);
        }
    }

    cout<<dp[n][x];

    return 0;
}

