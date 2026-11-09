#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
const ll mod = 1e9+7;
struct BinaryLift{
    ll n,root,l,timer;
    vi tin,tout,depth;
    vector<vector<ll>> up;
    BinaryLift(ll n, ll root, vector<vector<ll>>&adj){
        this->n = n;
        this->root = root;
        timer = 0;
        l = ceil(log2(n));
        tin.resize(n);
        tout.resize(n);
        depth.resize(n);
        up.assign(n,vector<ll>(l+1));
        dfs(root,root,0,adj);
    }
    void dfs(ll u, ll p, ll d, vector<vector<ll>>&adj){
        tin[u] = timer++;
        depth[u] = d;
        up[u][0] = p;
        for(ll i=1; i<=l; i++){
            up[u][i] = up[up[u][i-1]][i-1];
        }
        for(auto v : adj[u]){
            if(v==p) continue;
            dfs(v,u,d+1,adj);
        }
        tout[u] = timer++;
    }
    bool isancestor(ll u, ll v){
        return (tin[u]<=tin[v] && tout[u]>=tout[v]);
    }
    ll get(ll u, ll v){
        if(isancestor(u,v)) return u;
        if(isancestor(v,u)) return v;
        for(ll i=l; i>=0; i--){
            if(!isancestor(up[u][i],v)) u = up[u][i];
        }
        return up[u][0];
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("zyaxxxx.in", "r", stdin);
    // freopen("zyaxxxx.out", "w", stdout);
    ll t=1; 
    cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<vi> adj(n);
        for(ll i=0; i<n-1; i++){
            ll u,v; cin >> u >> v;
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }        
        if(n%2==0){
            cout << n+1 << "\n";
            continue;
        }
        // n, n+1, n+2
        ll res = n;
        BinaryLift bl(n,0,adj);
        auto check = [&](ll k)->pair<ll,ll>{
            vi dp(n,0);
            vi color(n,0); // 0-white, 1-grey, 2-black
            ll black = 0, grey = 0;
            for(ll i=1; i<=n; i++){
                if((k-i)>=1 && (k-i)<=n && (i!=k-i)){
                    ll u = i-1, v = k-i-1;
                    ll lca = bl.get(u, v);
                    dp[u]++; dp[v]++;
                    color[u] = 2; color[v] = 2;
                    dp[lca]--;
                    if(lca!=0) dp[bl.up[lca][0]]-=1;
                }
            }            
            
            auto dfs = [&](auto &&self, ll u, ll p)->ll{
                ll curr = dp[u];
                for(auto v : adj[u]){
                    if(v==p) continue;
                    curr += self(self,v,u);
                }
                if(curr>0 && color[u]!=2) color[u] = 1;
                return curr;
            };
            dfs(dfs,0,-1);
            for(ll i=0; i<n; i++){
                if(color[i]==2) black++;
                else if(color[i]==1) grey++;
            }
            return {black,grey};
        };
        pair<ll,ll> p = check(n);
        pair<ll,ll> p2 = check(n+1);
        if(p2.first>p.first || (p.first==p2.first && p2.second>p.second)){
            p = p2; res = n+1;
        } 
        pair<ll,ll> p3 = check(n+2);
        if(p3.first>p.first || (p.first==p3.first && p3.second>p.second)){
            p = p3; res = n+2;
        } 
        cout << res << "\n";
    }
}