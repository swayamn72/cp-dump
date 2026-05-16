#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vi arr(n); for(auto &x : arr) cin >> x;
        vector<vector<ll>> adj(n);
        vector<ll> degree(n,0);
        for(ll i=0; i<n-1; i++){
            ll u,v; cin >> u >> v;
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++; degree[v]++;
        }
        priority_queue<pair<ll,ll>> pq;
        for(int i=0; i<n; i++){
            if(degree[i]>1) pq.push({arr[i], degree[i]-1});
        }    
        ll sum = accumulate(arr.begin(),arr.end(),0LL);
        vi res(n-1); res[0] = sum;
        for(ll i=1; i<n-1; i++){
            if(pq.empty()){
                res[i] = sum;
                continue;
            }
            auto [w,v] = pq.top();
            pq.pop();
            sum += w;
            v--;
            if(v!=0) pq.push({w,v});
            res[i] = sum;
        }
        for(auto a : res) cout << a << " ";
        cout << "\n";
    }
}