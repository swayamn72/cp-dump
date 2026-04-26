#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,m; cin >> n >> m;
    vector<vector<ll>> adj(n);
    while(m--){
        ll a,b; cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    ll start = 0; ll end = n-1;
    vi parent(n, -1);
    vector<bool> vis(n, false);
    queue<ll> q;
    q.push(0); vis[0] = true;
    bool foundpath = false;
    while(!q.empty()){
        ll node = q.front(); q.pop();
        if(node==end){
            foundpath = true;
            break;
        }
        for(auto a : adj[node]){
            if(!vis[a]){
                vis[a] = true;
                parent[a] = node;
                q.push(a);
            }
        }
    } 
    if(!foundpath){
        cout << "IMPOSSIBLE";
        return 0;
    }
    vi ans;
    for(ll curr = n-1; curr != -1; curr = parent[curr]){
        ans.push_back(curr);
    }
    reverse(ans.begin(),ans.end());
    cout << ans.size() << "\n";
    for(auto a : ans) cout << a+1 << " ";
}