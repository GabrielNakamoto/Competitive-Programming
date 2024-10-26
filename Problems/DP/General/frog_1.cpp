/*
 * Author: Gabriel Nakamoto (gabriel@nakamoto.ca)
 * Date: Fri 25 Oct 2024 20:00:58 EDT
 *
 * Problem: Frog 1 (https://atcoder.jp/contests/dp/tasks/dp_a)
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

    vector<int> h(n);
    vector<int> dp(n, inf);

    for(int i=0; i<n; ++i)
        cin>>h[i];

    dp[0]=0;
    for(int i=0; i<n; ++i){
        for(int j : {i + 1, i + 2}){
            if(j < n){
                dp[j] = min(dp[j], dp[i] + abs(h[j]-h[i]));
            }
        }
    }
    cout<<dp[n-1];

    return 0;
}
