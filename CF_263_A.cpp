#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    vector<vector<ll>> grid(5, vector<ll>(5));
    for(auto &a : grid) for(auto &b : a) cin >> b;
    ll row,col;
    for(ll i=0; i<5; i++) for(ll j=0; j<5; j++){
        if(grid[i][j]==1){
            cout << abs(i-2) + abs(j-2);
            break;
        }
    }
}