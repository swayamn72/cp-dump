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
        ll n,k; cin >> n >> k;
        if(k==2*n || k<n){
            cout << -1 << "\n";
            continue;
        }        
        vector<vi> grid(n+1,vi(n+1,0));
        ll extra = k-n;
        
        ll i = 2, j = 2;
        grid[1][1] = 1;
        ll val = 2;
        for(ll k=0; k<extra; k++){
            grid[1][val] = val;
            val++;
            j++;
        }
        while(i<=n && j<=n){
            grid[i][j] = val++;
            i++; j++;
        }
        for(ll i=1; i<=n; i++) for(ll j=1; j<=n; j++){
            if(grid[i][j]==0) grid[i][j] = val++;
        }
        for(ll i=1; i<=n; i++){
            for(ll j=1; j<=n; j++) cout << grid[i][j] << " ";
            cout << "\n";
        } 
    }
} 