#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

    ll t; cin >> t;
    while(t--){
        ll n,x; cin >> n >> x; x--;
        vector<vector<ll>> adj(n); 
        for(ll i=0; i<n-1; i++){
            ll u,v; cin >> u >> v;
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        if(adj[x].size()<=1){
            cout << "Ayush" << "\n";
            continue;
        }
        if(n%2==0) cout << "Ayush" << "\n";
        else cout << "Ashish" << "\n";
    }
}