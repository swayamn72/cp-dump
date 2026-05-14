#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; cin >> n;
    vector<vector<ll>> grid(n, vector<ll>(n,0));
    ll sum = 0;
    for(auto &a : grid) for(auto &b : a){
        cin >> b; sum += b;
    } 
    ll minv = min(grid[0][n-1],grid[n-1][0]);
    ll col = n-1;
    for(ll i=0; i<n; i++){
        minv = min(minv,grid[i][col--]);
    }
    cout << sum - minv;
}