/*
 * Author: Gabriel Nakamoto (gabriel@nakamoto.ca)
 * Date: Fri 25 Oct 2024 20:23:07 EDT
 *
 * Problem: Frog 2 (https://atcoder.jp/contests/dp/tasks/dp_b)
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

    int n, k;
    cin>>n>>k;

    vector<int> h(n);
    vector<int> dp(n, inf);

    for(int i=0; i<n; ++i)
        cin>>h[i];

    dp[0]=0;
    for(int i=0; i<n; ++i){
        for(int j=1; j<=k; ++j){
            int idx=i+j;
            if(idx < n){
                dp[idx] = min(dp[idx], dp[i] + abs(h[idx]-h[i]));
            }
        }
    }
    cout<<dp[n-1];

    return 0;
}
