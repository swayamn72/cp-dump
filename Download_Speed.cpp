#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
ll bfs(ll source, ll sink, vector<vector<ll>>&adj, vector<vector<ll>>&capacity, vector<ll>&parent){
    fill(parent.begin(),parent.end(),-1);
    parent[source] = -2;
    queue<pair<ll,ll>> q;
    q.push({source,LLONG_MAX});
    while(!q.empty()){
        auto [curr,currflow] = q.front(); q.pop();
        for(auto a : adj[curr]){
            if(parent[a]==-1 && capacity[curr][a] > 0){
                parent[a] = curr;
                ll newflow = min(currflow, capacity[curr][a]);
                if(a==sink) return newflow;
                q.push({a,newflow});
            }
        }
    }
    return 0;
}
ll maxflow(ll n, ll source, ll sink, vector<vector<ll>>&adj, vector<vector<ll>>&capacity){
    ll totalflow = 0;
    vector<ll> parent(n);
    ll newflow;
    while((newflow = bfs(source,sink,adj,capacity,parent))){
        totalflow += newflow;
        ll curr = sink;
        while(curr!=source){
            ll prev = parent[curr];
            capacity[prev][curr] -= newflow;
            capacity[curr][prev] += newflow;
            curr = prev;
        }
    }
    return totalflow;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll n,m; cin >> n >> m;
    vector<vector<ll>> adj(n);
    vector<vector<ll>> capacity(n, vector<ll>(n,0));
    while(m--){
        ll u,v,c; cin >> u >> v >> c;
        u--; v--;
        if(capacity[u][v]==0 && capacity[v][u]==0){
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        capacity[u][v] += c;
    }
    cout << maxflow(n,0,n-1,adj,capacity);
}