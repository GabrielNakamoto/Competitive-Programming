#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int mxN=1e5;

int n, m, k, q, a, b, c, w;

vector<ar<int, 2> > adj[mxN];
priority_queue<ar<ll, 2> > pq;
ll d[mxN];

void dijkstra(int s){
    memset(d, 0x3f, sizeof(d));
    pq.push({0,s}); d[s]=0;

    while(pq.size()){
        ar<ll, 2> u=pq.top(); pq.pop();
        if(d[u[1]]>-u[0]) continue;

        for(ar<int, 2> v : adj[u[1]]){
            if(d[v[1]]>d[u[1]]+v[0]){
                d[v[1]]=d[u[1]]+v[0];
                pq.push({-d[v[1]],v[1]});
            }
        }
    }

}

void u_edge(int a, int b, int w){
    adj[a].push_back({w,b});
    adj[b].push_back({w,a});
}

void d_edge(int a, int b, int w){
    adj[a].push_back({w,b});
}

int main(){

    return 0;
}
