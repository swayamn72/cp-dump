#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,m; cin >> n >> m;
    vector<vector<ll>> grid(n, vector<ll>(m,0));
    for(ll i=0; i<n; i++) for(ll j=0; j<m; j++){
        ll val = 0;
        if((i-1)>=0) val++;
        if((i+1)<=n-1) val++;
        if((j-1)>=0) val++;
        if((j+1)<=m-1) val++;
        grid[i][j] = val;
    }
    for(auto a : grid){
        for(auto b : a) cout << b << " ";
        cout << "\n";
    }
}