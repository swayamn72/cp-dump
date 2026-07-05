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
        vector<vector<ll>> adj(n);
        vi degree(n,0);
        for(ll i=0; i<n-1; i++){
            ll u,v; cin >> u >> v; u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }     
        if(n<=4){
            cout << n-2 << "\n";
            continue;
        } 
        multiset<ll> s; 
        ll res = 0; 
        for(auto a : degree) s.insert(a);
        for(ll i=0; i<n; i++){
            ll curr = degree[i];
            s.erase(s.find(curr));
            vi list;
            for(auto a : adj[i]){
                ll deg = degree[a];
                s.erase(s.find(deg));
                s.insert(deg-1);
                list.push_back(deg);
            }
            auto it = s.end(); it--;
            ll val = *it;
            res = max(res,curr+val-1);
            for(auto a : list){
                s.insert(a);
                s.erase(s.find(a-1));
            }
            s.insert(curr);
        }
        cout << res << "\n";
    }
}