#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        if(n==1){
            vi arr(n); for(auto &x : arr) cin >> x;
            if(n==1){
                cout << "YES" << "\n";
                continue;
            }
        }
        vi parent(n-1); 
        for(auto &x : parent){
            cin >> x;
            x--;
        } 
        if(n==2){
            vi arr(n); for(auto &x : arr) cin >> x;
            cout << "YES" << "\n";
            continue;
        }
        vi arr(n); for(auto &x : arr) cin >> x;
        vector<vector<ll>> adj(n);
        for(ll i=0; i<n-1; i++){
            ll node = i+1;
            ll p = parent[i];
            adj[p].push_back(node);
        }
        auto dfs = [&](auto &&self, ll u)->pair<ll,ll>{
            if(adj[u].empty()){
                return {arr[u],arr[u]};
            }
            vector<pair<ll,ll>> childrange;
            for(auto v : adj[u]){
                pair<ll,ll> p = self(self,v);
                if(p.first==-1) return {-1,-1};
                childrange.push_back(p);
            }
            ll k = childrange.size();
            ll drops = 0;
            ll minv = LLONG_MAX, maxv = LLONG_MIN;
            for(ll i=0; i<k; i++){
                ll curr = childrange[i].second;
                ll nextl = childrange[(i+1)%k].first;
                if(curr+1!=nextl){
                    drops++;
                }
                minv = min(minv,childrange[i].first);
                maxv = max(maxv,childrange[i].second);
            }
            if(drops==1){
                return {minv,maxv};
            }else{
                return {-1,-1};
            }
        };
        pair<ll,ll> res = dfs(dfs,0);
        
        cout << (res.first==-1 ? "NO" : "YES") << "\n";
        
    }
}