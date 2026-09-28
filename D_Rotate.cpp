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
        ll n,k; cin >> n >> k; k++;
        vi p(n); for(auto &x : p){cin >> x; x--;} 
        vi q(n); for(auto &x : q){cin >> x; x--;} 
        vi qq(n);
        // p = {2,3,1,5,4}
        for(ll i=0; i<n; i++){
            qq[p[i]] = q[i];
        }
        // for(auto a : qq) cout << a << " ";
        // cout << "\n";

        vi cycle(n);
        vector<bool> vis(n,false);
        auto dfs = [&](auto &&self, ll u, ll &sz, vi &vv, vi &order, ll o)->void{
            sz++;
            order[u] = o;
            vis[u] = true;
            vv.push_back(u);
            ll v = p[u];
            if(!vis[v]) self(self,v,sz,vv,order,o+1);
            cycle[u] = sz;
        };
        vi dist(n);
        for(ll i=0; i<n; i++){
            if(!vis[i]){
                vi vv; ll sz = 0; vi order;
                dfs(dfs,i,sz,vv,order,0);
                set<ll> st;
                for(auto a : vv) st.insert(a);
                for(auto a : vv){
                    if(!st.count(qq[a])){
                        dist[a] = -1;
                        continue;
                    }
                    // ll s = order[a], d = order[qq[a]];
                    // if(s<=d){
                    //     dist[a] = d-s;
                    // }else{
                    //     dist[a] = cycle[a] - s + d;
                    // }
                }
            }
        }
        for(auto a : dist) cout << a << " ";
        cout << "\n";
        // for(auto a : cycle) cout << a << " ";
        // cout << "\n";
    }
}