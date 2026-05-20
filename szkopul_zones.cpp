#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,m; cin >> n >> m;
    vector<vector<ll>> edges;
    while(m--){
        ll x,y; cin >> x >> y; x--; y--;
        edges.push_back({x,y});
    }
    ll timer = 0;
    vi low(n,-1), tin(n,-1);
    
}