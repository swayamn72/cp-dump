#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
const ll mod = 1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1; 
    cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<vi> adj(n);
        map<pair<ll,ll>,ll> edgeno;
        for(ll i=0; i<n-1; i++){
            ll u,v; cin >> u >> v;
            if(v<u) swap(u,v); u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
            edgeno[{u,v}] = i+1;
        }
        vi parent(n);
        vi size(n);
        auto dfs = [&](auto &&self, ll u, ll p)->ll{
            parent[u] = p;
            ll s = 1;
            for(auto v : adj[u]){
                if(v==p) continue;
                s += self(self,v,u);
            }
            return size[u] = s;
        };
        dfs(dfs,0,-1);
        // for(auto a : size) cout << a << " ";
        // cout << "\n";
        vi res;
        set<pair<ll,ll>> resset;
        map<ll,vi> mp;
        for(ll i=0; i<n; i++) mp[size[i]].push_back(i);

        ll idx = 3;
        while(idx<=n){
            for(auto a : mp[idx]){
                if(parent[a]==-1) continue;
                ll b = parent[a];
                if(a>b) swap(a,b);
                resset.insert({a,b});
                res.push_back(edgeno[{a,b}]);
            }
            idx+=3;
        }
        bool flag = true;
        vector<bool> vis(n,false);

        
        
        auto dfs2 = [&](auto &&self, ll u, ll p)->ll{
            vis[u] = true;
            ll s = 1;
            for(auto v : adj[u]){
                if(v==p) continue;
                if(vis[v]) continue;
                ll a = u, b = v;
                if(a>b) swap(a,b);
                if(resset.count({a,b})) continue;
                s += self(self,v,u);
            }
            return s;
        };
        for(ll i=0; i<n; i++){
            if(vis[i]) continue;
            ll s = dfs2(dfs2,i,-1);
            if(s!=3){
                flag = false;
                break;
            }
        }

        if(!flag){
            cout << -1 << "\n";
            continue;
        }

        cout << res.size() << "\n";
        for(auto a : res) cout << a << " ";
        cout << "\n";
    }
}