#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
ll mod = 1e9+7;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1; 
    cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<vi> adj(n);
        vi deg(n);
        ll center = -1;
        for(ll i=0; i<n-1; i++){
            ll u,v; cin >> u >> v;
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
            deg[u]++;
            deg[v]++;
        }
        for(ll i=0; i<n; i++){
            if(deg[i]==n-1){
                center = i;
                break;
            }
        }
        vi res(n,-1);
        if(center!=-1){
            res[center] = 1;
            vi leaves; 
            leaves.push_back(2);
            for(ll i=5; i<=2*n; i+=2) leaves.push_back(i);
            ll ptr = 0;
            for(ll i=0; i<n; i++){
                if(i!=center) res[i] = leaves[ptr++];
            }
            for(auto a : res) cout << a << " ";
            cout << "\n";
            continue;
        }
        vi color(n,-1);
        vi l,r;
        auto dfs = [&](auto &&self, ll u, ll p, ll c)->void{
            color[u] = c;
            if(c==0) l.push_back(u);
            else r.push_back(u);
            for(auto v : adj[u]){
                if(v==p) continue;
                self(self,v,u,1-c);
            }
        };
        dfs(dfs,0,-1,0);
        ll nonadjl = -1, nonadjr = -1;
        for(auto u : l){
            if(adj[u].size() < r.size()){
                nonadjl = u;
                set<ll> neighbours(adj[u].begin(),adj[u].end());
                for(auto v : r){
                    if(!neighbours.count(v)){
                        nonadjr = v;
                        break;
                    }
                }
                break;
            }
        }
        ll left = 2*l.size();
        ll right = left+2;
        res[nonadjl] = left;
        res[nonadjr] = right;

        ll curr = 2;
        for(auto a : l){
            if(a==nonadjl) continue;
            res[a] = curr;
            curr += 2;
        }
        curr = right+2;
        for(auto a : r){
            if(a==nonadjr) continue;
            res[a] = curr;
            curr += 2;
        }
        for(auto a : res) cout << a << " "; 
        cout << "\n";
    }
} 