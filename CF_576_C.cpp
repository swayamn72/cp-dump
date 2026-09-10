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
    // cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<pair<ll,ll>> arr(n);
        for(auto &[u,v] : arr) cin >> u >> v;
        ll b = 1001;
        vector<vector<vi>> v(1001);
        for(ll i=0; i<n; i++){
            auto [x,y] = arr[i];
            ll b = x/1001;
            v[b].push_back({y,x,i+1});
        }
        bool up = true;
        vi res;
        for(auto &a : v){
            if(a.empty()) continue;
            if(up) sort(a.begin(),a.end());
            else sort(a.rbegin(),a.rend());
            up = !up;
            for(auto &b : a) res.push_back(b[2]);
        }
        for(auto a : res) cout << a << " ";
    }
} 