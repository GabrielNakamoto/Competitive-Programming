/*
 * Author: Gabriel Nakamoto (gabriel@nakamoto.ca)
 * Date: Fri 25 Oct 2024 20:38:54 EDT
 *
 * Problem: Vacation (https://atcoder.jp/contests/dp/tasks/dp_c)
 * Type: Dynamic Programming
 *
*/

#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int mxN=1e5+1;
const int inf=1e9 + 5;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin>>n;

    vector<vector<int>> dp(3, vector<int>(n));
    vector<vector<int>> h(3,vector<int>(n));
    for(int i=0; i<n; ++i)
        cin>>h[0][i]>>h[1][i]>>h[2][i];

    for(int i=0; i<n; ++i){
        int a=h[0][i], b=h[1][i], c=h[2][i];
        if(i==0){
            dp[0][i]=a;
            dp[1][i]=b;
            dp[2][i]=c;
        } else {
            dp[0][i]=max(dp[1][i-1],dp[2][i-1])+a;
            dp[1][i]=max(dp[0][i-1],dp[2][i-1])+b;
            dp[2][i]=max(dp[1][i-1],dp[0][i-1])+c;
        }
    }
    int ans=0;
    for(int i=0; i<3; ++i)
        ans=max(ans,dp[i][n-1]);
    cout<<ans;

    return 0;
}
