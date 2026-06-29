#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll n,m; cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    for(auto &a : grid) for(auto &b : a) cin >> b;
    ll toprow = 0;
    while(true){
        bool flag = true;
        for(ll i=0; i<m; i++){
            if(grid[toprow][i]=='#'){
                flag = false;
                break;
            }
        }
        if(!flag) break;
        toprow++;
    }
    ll bottomrow = n-1;
    while(true){
        bool flag = true;
        for(ll i=0; i<m; i++){
            if(grid[bottomrow][i]=='#'){
                flag = false;
                break;
            }
        }
        if(!flag) break;
        bottomrow--;
    }
    ll leftcolumn = 0;
    while(true){
        bool flag = true;
        for(ll i=0; i<n; i++){
            if(grid[i][leftcolumn]=='#'){
                flag = false;
                break;
            }
        }
        if(!flag) break;
        leftcolumn++;
    }
    ll rightcolumn = m-1;
    while(true){
        bool flag = true;
        for(ll i=0; i<n; i++){
            if(grid[i][rightcolumn]=='#'){
                flag = false;
                break;
            }
        }
        if(!flag) break;
        rightcolumn--;
    }
    for(ll i=toprow; i<=bottomrow; i++){
        for(ll j=leftcolumn; j<=rightcolumn; j++){
            cout << grid[i][j];
        }
        cout << "\n";
    }
}