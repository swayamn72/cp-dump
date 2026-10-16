#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
const ll mod = 1e9+7;
const ll logg = 20;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1; 
    // cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<vi> adj(n+1);
        for(ll i=0; i<n; i++){
            ll a; cin >> a;
            adj[a].push_back(i+1);
        }

        vector<vi> up(n+1, vi(logg,0));
        vi depth(n+1,0);
        vi tin(n+1,0), tout(n+1,0);
        vector<vi> depthtin(n+1);

        ll timer = 1;
        auto dfs = [&](auto &&self, ll u, ll p, ll d)->void{
            tin[u] = timer++;
            depth[u] = d;
            depthtin[d].push_back(tin[u]);
            up[u][0] = p;
            for(ll i=1; i<logg; i++){
                up[u][i] = up[up[u][i-1]][i-1];
            }
            for(auto v : adj[u]){
                if(v==p) continue;
                self(self,v,u,d+1);
            }
            tout[u] = timer-1;
        };
        dfs(dfs,0,0,0);

        auto getancestor = [&](ll u, ll p)->ll{
            for(ll i=0; i<logg; i++){
                if(p&(1LL<<i)){
                    u = up[u][i];
                }
            }
            return u;
        };

        ll m; cin >> m;
        while(m--){
            ll v,p; cin >> v >> p;
            ll u = getancestor(v, p);
            if(u==0){
                cout << 0 << " ";
            }else{
                ll d = depth[v];
                auto it1 = lower_bound(depthtin[d].begin(),depthtin[d].end(),tin[u]);
                auto it2 = upper_bound(depthtin[d].begin(),depthtin[d].end(),tout[u]);
                cout << it2-it1-1 << " ";
            }
        }
    }
}