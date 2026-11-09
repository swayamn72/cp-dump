#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
const ll mod = 1e9+7;
struct Basis{
    ll b[60] = {0}; ll v[60] = {0};
    ll sz = 0;
    void insert(ll x){
        for(ll i=59; i>=0; i--){
            if((x>>i)&1LL){
                if(!b[i]){
                    b[i] = x; sz++;
                    return;
                }
                x^=b[i];
            }
        }
    }
    void reduce(){
        for(ll i=59; i>=0; i--){
            if(b[i]){
                for(ll j=59; j>i; j--){
                    if(b[j] && ((b[j]>>i)&1LL)){
                        b[j] ^= b[i];
                    }
                }
            }
        }
        ll idx = 0;
        for(ll i=0; i<=59; i++){
            if(b[i]){
                v[idx++] = b[i];
            }
        }
    }
    ll kth(ll k){
        ll total = (1LL << sz);
        if(k > total) return -1;
        k--; ll res = 0;
        for(ll i=0; i<sz; i++){
            if((k>>i)&1LL){
                res ^= v[i];
            }
        }
        return res;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("zyaxxxx.in", "r", stdin);
    // freopen("zyaxxxx.out", "w", stdout);
    ll t=1; 
    // cin >> t;
    while(t--){
        ll n,m; cin >> n >> m;
        vector<vector<pair<ll,ll>>> adj(n);
        for(ll i=0; i<m; i++){
            ll u,v,w; cin >> u >> v >> w;
            u--; v--;
            adj[u].push_back({w,v});
            adj[v].push_back({w,u});
        }        
        Basis basis;
        vector<bool> vis(n,false);
        vi arr(n,0);
        auto dfs = [&](auto &&self, ll u)->void{
            vis[u] = true;
            for(auto [w,v] : adj[u]){
                if(!vis[v]){
                    arr[v] = arr[u]^w;
                    self(self,v);
                }else{
                    basis.insert(arr[u]^arr[v]^w);
                }
            }
        };
        dfs(dfs,0);
        ll res = 0;
        for(ll i=59; i>=0; i--){
            if((res^basis.b[i])>res){
                res ^= basis.b[i];
            }
        }
        cout << res << "\n";
    }
}