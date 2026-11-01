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
        ll k; cin >> k;
        vector<vector<pair<ll,ll>>> arr(k);
        ll single = 0;
        for(ll i=0; i<k; i++){
            ll n; cin >> n;
            if(n==1) single++;
            for(ll j=0; j<n-1; j++){
                ll u,v; cin >> u >> v;
                arr[i].push_back({u,v});
            }
        }
        if(single==k){
            for(ll i=2; i<=k; i++){
                cout << 1 << " " << 1 << " " << i << " " << 1 << "\n";
            }
            continue;
        }
        ll small=-1, idx=-1;
        for(ll i=0; i<k; i++){
            if(arr[i].size()==0) continue;
            vi one,two;
            ll n = arr[i].size()+1;
            vector<vi> adj(n+1);
            for(auto [a,b] : arr[i]){
                adj[a].push_back(b);
                adj[b].push_back(a);
            }
            auto dfs = [&](auto &&self, ll u, ll p)->bool{
                bool childtaken = false;
                for(auto v : adj[u]){
                    if(v==p) continue;
                    if(self(self,v,u)) childtaken = true;
                }
                if(!childtaken){
                    one.push_back(u);
                    return true;   
                }
                two.push_back(u);
                return false;
            };
            dfs(dfs,1,0);
            if(two.size()>0){
                small = two[0];
                idx = i;
                break;
            }
        }
        for(ll i=0; i<k; i++){
            if(idx==i) continue;
            ll n = arr[i].size()+1;
            vector<vi> adj(n+1);
            for(pair<ll,ll> edge : arr[i]){
                adj[edge.first].push_back(edge.second);
                adj[edge.second].push_back(edge.first);
            }
            
            vi one, two;
            auto dfs2 = [&](auto &&self, ll u, ll p) -> bool {
                bool child_in_one = false;
                for(ll v : adj[u]){
                    if(v==p) continue;
                    if(self(self, v, u)) child_in_one = true;
                }
                if(!child_in_one){
                    one.push_back(u);
                    return true;
                } else {
                    two.push_back(u);
                    return false;
                }
            };
            dfs2(dfs2, 1, 0);
            ll val = one[0];
            cout << idx+1 << " " << small << " " << i+1 << " " << val << "\n";
        }

    }
}