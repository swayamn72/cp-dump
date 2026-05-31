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
        ll n,k; cin >> n >> k;
        ll danger = n*n - k;
        if(danger==1){
            cout << "NO" << "\n";
            continue;
        }
        vector<vector<char>> grid(n, vector<char>(n,'#'));
        ll rows = danger/n;
        ll buffer = danger%n;
        for(ll i=0; i<rows; i++){
            grid[i][n-1] = 'L';
            for(ll j=0; j<n-1; j++){
                if(j%2==0) grid[i][j] = 'R';
                else grid[i][j] = 'L';
            }
        }

        if(buffer!=0 && rows==0){
            grid[0][buffer-1] = 'L';
            for(ll i=0; i<buffer-1; i++){
                if(i%2==0) grid[0][i] = 'R';
                else grid[0][i] = 'L';
            }
        }else if(buffer!=0){
            for(ll i=0; i<buffer; i++){
                grid[rows][i] = 'U';
            }
        }
        for(ll i=0; i<n; i++) for(ll j=0; j<n; j++){
            if(grid[i][j]=='#') grid[i][j] = 'D';
        }
        cout << "YES" << "\n";
        for(auto a : grid){
            for(auto b : a) cout << b;
            cout << "\n";
        }
    }
}