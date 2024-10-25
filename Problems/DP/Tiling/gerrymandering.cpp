/*
 * Author: Gabriel Nakamoto (gabriel@nakamoto.ca)
 * Date: Fri 25 Oct 2024 15:38:00 EDT
 *
 * Problem: Gerrymandering (https://codeforces.com/contest/2022/problem/C)
 * Type: Dynamic Programming
 *
*/

#include <bits/stdc++.h>

const long long inf = 2e9;

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin>>t;
    while(t--){
        int n;
        string s[2];
        cin>>n>>s[0]>>s[1];
        vector<vector<int>> dp(n+1, vector<int>(4, -inf));
        int vot[2][n+1];

        for(int i=1; i<=n; ++i){
            vot[0][i] = (s[0][i-1] == 'A');
            vot[1][i] = (s[1][i-1] == 'A');
        }

        dp[0][0]=0;
        dp[0][3]=0;
        for(int i=1; i<=n; ++i){
            dp[i][0]=dp[i-1][3];
            if(i-2>=0){
                dp[i][1]=max(dp[i][1],dp[i-2][3]+(vot[0][i-1]+vot[1][i-1]+vot[0][i]>=2));
                dp[i][2]=max(dp[i][2],dp[i-2][3]+(vot[0][i-1]+vot[1][i-1]+vot[1][i]>=2));
            }
            if(i-3>=0){
                dp[i][1]=max(dp[i][1],dp[i-3][1]+(vot[1][i-3]+vot[1][i-2]+vot[1][i-1]>=2)+(vot[0][i-2]+vot[0][i-1]+vot[0][i]>=2));
                dp[i][2]=max(dp[i][2],dp[i-3][2]+(vot[0][i-3]+vot[0][i-2]+vot[0][i-1]>=2)+(vot[1][i-2]+vot[1][i-1]+vot[1][i]>=2));
                dp[i][3]=max(dp[i][3],dp[i-3][3]+(vot[0][i-2]+vot[0][i-1]+vot[0][i]>=2)+(vot[1][i-2]+vot[1][i-1]+vot[1][i]>=2));
            }
            dp[i][3]=max(dp[i][3],dp[i-1][1]+(vot[1][i-1]+vot[0][i]+vot[1][i]>=2));
            dp[i][3]=max(dp[i][3],dp[i-1][2]+(vot[0][i-1]+vot[0][i]+vot[1][i]>=2));
        }
        cout<<dp[n][3]<<'\n';
    }

    return 0;
}
