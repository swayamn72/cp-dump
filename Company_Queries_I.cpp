#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll n,q; cin >> n >> q;
    vi parent(n,-1);
    for(ll i=1; i<n; i++){
        ll x; cin >> x;
        parent[i] = x-1;
    }
    ll l = 20;
    vector<vector<ll>> up(n, vector<ll>(l+1,-1));
    for(ll i=0; i<n; i++) up[i][0] = parent[i];
    for(ll i=1; i<=l; i++){
        for(ll j=0; j<n; j++) if(up[j][i-1]!=-1) up[j][i] = up[up[j][i-1]][i-1];
    }
    while(q--){
        ll x,k; cin >> x >> k;
        ll node = x; node--;
        ll ans = -2;
        for(ll i=l; i>=0; i--){
            ll dist = 1LL<<i;
            if(dist<=k){
                k-=dist;
                node = up[node][i];
            }
            if(node==-1) break;
        }
        ans = node;
        if(ans==-1) ans = -2;
        cout << ans+1 << "\n";
    }
}