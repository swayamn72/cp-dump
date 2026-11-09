#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
const ll mod = 1e9+7;
struct Fenwick {
    int n;
    vi tree;
    Fenwick(int n) : n(n), tree(n + 1, 0) {}
    
    void add(int i, ll delta) {
        for (; i <= n; i += i & -i) tree[i] += delta;
    }
    
    ll query(int i) {
        ll sum = 0;
        for (; i > 0; i -= i & -i) sum += tree[i];
        return sum;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("promote.in", "r", stdin);
    freopen("promote.out", "w", stdout);
    ll t=1; 
    // cin >> t;
    while(t--){
        ll n; cin >> n;
        vi arr(n); for(auto &x : arr) cin >> x;
        vector<vi> adj(n);
        vi sortedarr = arr;
        sort(sortedarr.begin(),sortedarr.end());
        for(ll i=1; i<n; i++){
            ll p; cin >> p; p--;
            adj[p].push_back(i);
        }
        Fenwick ft(n);
        vi res(n);
        auto dfs = [&](auto &&self, ll u, ll p)->void{
            ll rank = lower_bound(sortedarr.begin(),sortedarr.end(),arr[u]) - sortedarr.begin() + 1;
            ll before = ft.query(n) - ft.query(rank);
            for(auto v : adj[u]){
                if(v==p) continue;
                self(self,v,u);
            }
            ll after = ft.query(n) - ft.query(rank);
            res[u] = after - before;
            ft.add(rank,1);
        };
        dfs(dfs,0,-1);
        for(auto a : res) cout << a << "\n";
    }
}