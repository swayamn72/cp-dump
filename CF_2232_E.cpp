#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
const ll mod = 1e9+7;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll t; cin >> t;
    while(t--){
        ll n,k; cin >> n >> k;
        vector<vector<ll>> grid(n, vector<ll>(n,0));
        vector<vector<bool>> vis(n, vector<bool>(n,false));
        while(k--){
            ll size; cin >> size;
            ll r,c; cin >> r >> c;
            grid[r-1][c-1] = 0;
            vis[r-1][c-1] = true;
            if(size==1) continue;
            string s; cin >> s;
            for(auto a : s){
                if(a=='R') c++;
                else r++;
                grid[r-1][c-1] = 0;
                vis[r-1][c-1] = false;
            }
        }
        // for(auto a : grid){
        //     for(auto b : a) cout << b;
        //     cout << "\n";
        // }    

        for(ll i=0; i<n; i++){
            for(ll j=0; j<n; j++){
                
            }
        }
    }
}