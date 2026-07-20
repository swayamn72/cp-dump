#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        ll n,m; cin >> n >> m;
        vector<vector<ll>> d(2,vector<ll>(n,0));
        vector<vector<pair<ll,ll>>> adj(n);
        for(ll i=0; i<m; i++){
            ll a,b,c; cin >> a >> b >> c;
            a--; b--; c--;
            adj[b].push_back({c,a});
            adj[c].push_back({b,a});
            d[a][b]++;
            d[a][c]++;
        }        
        queue<ll> q;
        vector<bool> vis(n,false);
        for(ll i=0; i<n; i++){
            if(d[0][i]==0 || d[1][i]==0){
                q.push(i);
                vis[i] = true;
            }
        }
        vector<pair<ll,ll>> order;
        while(!q.empty()){
            ll node = q.front(); q.pop();
            ll sign = (d[0][node]==0) ? -1 : 1;
            order.push_back({node,sign});
            for(auto [v,o] : adj[node]){
                d[o][v]--;
                if(!vis[v]&&(d[0][v]==0 || d[1][v]==0)){
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
        if(order.size()<n){
            cout << "NO" << "\n";
            continue;
        }
        reverse(order.begin(),order.end());
        vi res(n);
        ll temp = 1;
        for(auto [v,o] : order){
            res[v] = temp++;
            if(o==-1) res[v] = -res[v];
        }
        cout << "YES" << "\n";
        for(auto a : res) cout << a << " ";
        cout << "\n";
    }
}