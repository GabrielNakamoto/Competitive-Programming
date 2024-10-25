/*
 * Author: Gabriel Nakamoto (gabriel@nakamoto.ca)
 * Date: Fri 25 Oct 2024 16:09:08 EDT
 *
 * Problem: Knapsack 1 (https://atcoder.jp/contests/dp/tasks/dp_d)
 * Type: Dynamic Programming
 *
*/

#include <bits/stdc++.h>

using namespace std;

const int inf=2e9;
const int mxN=100+10;
const int mxW=1e5+10;

long long dp[mxW][mxN];
array<int, 2> a[mxN];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, W;
    cin>>n>>W;

    for(int i=1; i<=n; ++i)
        cin>>a[i][0]>>a[i][1];

    for(int i=0; i<W; ++i)
        dp[i][0]=0;
    for(int i=0; i<W; ++i)
        for(int j=1; j<=n; ++j)
            dp[i][j]=-inf;

    for(int i=1; i<=n; ++i){
        for(int w=0; w<=W; ++w){
            if(w - a[i][0]>=0) dp[w][i]=dp[w-a[i][0]][i-1] + a[i][1];
            dp[w][i]=max(dp[w][i],dp[w][i-1]);
        }
    }
    cout<<dp[W][n];

    return 0;
}
