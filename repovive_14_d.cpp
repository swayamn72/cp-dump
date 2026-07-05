#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
ll mod = 998244353;
ll binexp(ll a, ll b){
    ll res = 1;
    while(b>0){
        if(b&1) res = (res*a)%mod;
        a = (a*a)%mod;
        b>>=1;
    }
    return res;
}
ll modinverse(ll n){
    return binexp(n,mod-2);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        ll n,m; cin >> n >> m;
        vector<vector<ll>> adj(n);
        while(m--){
            ll u,v; cin >> u >> v;
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vi dist(n);
        queue<ll> q; q.push(n-1);
        ll size = 1;
        ll curr = 0;
        vector<bool> vis(n,false);
        vis[n-1] = true;
        while(!q.empty()){
            ll node = q.front(); q.pop();
            dist[node] = curr;
            size--;
            for(auto v : adj[node]){
                if(vis[v]) continue;
                q.push(v);
                vis[v] = true;
            }
            if(size==0){
                curr++;
                size = q.size();
            }
        }
        
        ll d1 = dist[0];
        sort(dist.begin(),dist.end());
        ll sl = 0;
        for(ll l=1; l<=n; l++){
            sl += dist[l-1];

            ll cnum = n + sl;
            ll cden = l;

            bool ok = (l*dist[l-1] < cnum);

            if(l<n){
                if(cnum > l*dist[l]){
                    ok = false;
                }
            }
            if(ok){
                if(d1 * cden <= cnum) {
                    cout << d1 % mod << "\n";
                }else{
                    ll ans = (cnum % mod) * modinverse(cden) % mod;
                    cout << ans << "\n";
                }
                break;
            }
        }
    }
}