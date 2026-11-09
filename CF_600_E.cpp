#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
const ll mod = 1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("zyaxxxx.in", "r", stdin);
    // freopen("zyaxxxx.out", "w", stdout);
    ll t=1; 
    // cin >> t;
    while(t--){
        ll n; cin >> n;
        vi c(n); for(auto &x : c) cin >> x;
        vector<vi> adj(n);
        for(ll i=0; i<n-1; i++){
            ll u,v; cin >> u >> v;
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }        
        vi res(n);
        vector<map<ll,ll>> arr(n);
        vi maxf(n,0), sumf(n,0);
        auto add = [&](ll u, ll color, ll count){
            arr[u][color] += count;
            ll f = arr[u][color];
            if(f>maxf[u]){
                maxf[u] = f;
                sumf[u] = color;
            }else if(f==maxf[u]){
                sumf[u] += color;
            }
        };
        auto dfs = [&](auto &&self, ll u, ll p)->ll{
            for(auto v : adj[u]){
                if(v==p) continue;
                self(self,v,u);
                if(arr[v].size()>arr[u].size()){
                    swap(arr[u],arr[v]);
                    swap(maxf[u],maxf[v]);
                    swap(sumf[u],sumf[v]);
                }
                for(auto a : arr[v]) add(u,a.first,a.second);
            }
            add(u,c[u],1);
            return res[u] = sumf[u];
        };
        dfs(dfs,0,-1);
        for(auto a : res) cout << a << " ";
    }
}