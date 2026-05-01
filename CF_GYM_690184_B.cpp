#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,m,s; cin >> n >> m >> s;
    vector<vector<ll>> adj(n);
    while(m--){
        ll u,v; cin >> u >> v; u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<ll> dist(n,LLONG_MAX);
    set<ll> st;
    for(ll i=0; i<n; i++) st.insert(i);
    st.erase(s-1);
    queue<ll> q; q.push(s-1);
    dist[s-1] = 0;
    vector<bool> edge(n,false);
    while(!q.empty()){
        ll node = q.front(); q.pop();
        for(auto a : adj[node]) edge[a] = true;

        vector<ll> v;
        for(auto a : st){
            if(!edge[a]){
                dist[a] = dist[node]+1;
                q.push(a);
                v.push_back(a);
            }
        }
        for(auto a : v) st.erase(a);
        for(auto a : adj[node]){
            edge[a] = false;
        }
    }
    for(auto &a : dist) if(a==LLONG_MAX) a = -1;
    for(ll i=0; i<n; i++){
        if(i==s-1) continue;
        cout << dist[i] << " ";
    }
}