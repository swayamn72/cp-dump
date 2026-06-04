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
        ll n,m; cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m));
        for(auto &a : grid) for(auto &b : a) cin >> b;
        bool flag = true;
        for(ll i=0; i<n; i++){
            ll sum = 0;
            for(ll j=0; j<m; j++){
                if(grid[i][j]=='L' || grid[i][j]=='U') sum++;
                else if(grid[i][j]=='R' || grid[i][j]=='D') sum--;
            }
            if(sum%2!=0){
                flag = false;
                break;
            }
        }
        for(ll i=0; i<m; i++){
            ll sum = 0;
            for(ll j=0; j<n; j++){
                if(grid[j][i]=='L' || grid[j][i]=='U') sum++;
                else if(grid[j][i]=='R' || grid[j][i]=='D') sum--;
            }
            if(sum%2!=0){
                flag = false;
                break;
            }
        }
        if(!flag){
            cout << -1 << "\n";
            continue;
        }
        vector<ll> rows(n,0);
        vector<ll> cols(m,0);
        for(ll i=0; i<n; i++){
            for(ll j=0; j<m; j++){
                if(grid[i][j]=='.' || grid[i][j]=='W' || grid[i][j]=='B') continue;
                if(grid[i][j]=='L' || grid[i][j]=='U'){
                    if(grid[i][j]=='U'){
                        if(rows[i] == 0){
                            grid[i][j] = 'B'; grid[i+1][j] = 'W';
                            rows[i] = 1;
                        }else{
                            grid[i][j] = 'W'; grid[i+1][j] = 'B';
                            rows[i] = 0;
                        }
                    }else{
                        if(cols[j] == 0){
                            grid[i][j] = 'B'; grid[i][j+1] = 'W';
                            cols[j] = 1;
                        }else{
                            grid[i][j] = 'W'; grid[i][j+1] = 'B';
                            cols[j] = 0;
                        }
                    }
                }
            }
        }
        for(auto a : grid){
            for(auto b : a) cout << b;
            cout << "\n";
        }
    }
}