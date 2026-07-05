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
        vector<vector<ll>> grid(2, vector<ll>(n));
        for(ll i=0; i<n; i++) cin >> grid[0][i];
        for(ll i=0; i<n; i++) cin >> grid[1][i];
        
        vi topmax(n);
        topmax[0] = grid[0][0];
        for(ll i=1; i<n; i++) topmax[i] = max(topmax[i-1],grid[0][i]);

        vi bottommax(n);
        bottommax[n-1] = grid[1][n-1];
        for(ll i=n-2; i>=0; i--) bottommax[i] = max(bottommax[i+1],grid[1][i]);

        vi topmin(n);
        topmin[0] = grid[0][0];
        for(ll i=1; i<n; i++) topmin[i] = min(topmin[i-1],grid[0][i]);

        vi bottommin(n);
        bottommin[n-1] = grid[1][n-1];
        for(ll i=n-2; i>=0; i--) bottommin[i] = min(bottommin[i+1],grid[1][i]);

        vector<vector<ll>> v;
        for(ll i=0; i<n; i++){
            ll minv = min(topmin[i],bottommin[i]);
            ll maxv = max(topmax[i],bottommax[i]);
            v.push_back({minv,maxv});
        }
        sort(v.rbegin(),v.rend());
        ll res = 0;
        ll minr = 2*n+1;
        ll ptr = 0;
        for(ll l=2*n; l>=1; l--){
            while(ptr<n && v[ptr][0]>=l){
                minr = min(minr,v[ptr][1]);
                ptr++;
            }
            if(ptr>0){
                res += (2*n-minr+1);
            }
        }
        cout << res << "\n";
    }
}