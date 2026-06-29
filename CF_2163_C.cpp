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
        ll n; cin >> n;
        vector<vector<ll>> grid(n, vector<ll>(n));
        for(ll i=0; i<n; i++) cin >> grid[0][i];
        for(ll i=0; i<n; i++) cin >> grid[1][i];
        
        vi minpath(n), maxpath(n);
        minpath[0] = grid[0][0];
        for(ll i=1; i<n; i++){
            minpath[i] = min(minpath[i-1],grid[0][i]);
            maxpath[i] = max(maxpath[i-1],grid[0][i]);
        }
        
        ll minv = min(grid[0][0],grid[1][n-1]);
        ll maxv = LLONG_MAX;
        
    }
}