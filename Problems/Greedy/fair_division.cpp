/*
 * Author: Gabriel Nakamoto (gabriel@nakamoto.ca)
 * Date: Fri 25 Oct 2024 15:59:36 EDT
 *
 * Problem: Fair Division (https://codeforces.com/problemset/problem/1472/B)
 * Type: Greedy
 *
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int ones=0, twos=0;
        for(int i=0; i<n; ++i){
            int x;
            cin>>x;
            if(x==1) ones++;
            else twos++;
        }
        cout << ((ones%2==0 && ones > 0 ) || (twos%2==0 && ones == 0) ?"YES":"NO") << '\n';
    }

    return 0;
}
