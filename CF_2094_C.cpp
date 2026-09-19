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
        vector<vi> grid(n,vi(n));
        for(auto &a : grid) for(auto &b : a) cin >> b;
        vi res;
        vector<bool> vis(2*n+1,false);
        for(ll i=0; i<n; i++){
            res.push_back(grid[0][i]);
            vis[grid[0][i]] = true;
        }        
        for(ll i=1; i<n; i++){
            res.push_back(grid[n-1][i]);
            vis[grid[n-1][i]] = true;
        }
        for(ll i=1; i<=2*n; i++){
            if(!vis[i]){
                cout << i << " ";
                break;
            }
        }
        for(auto a : res) cout << a << " ";
        cout << "\n";
    }
} 