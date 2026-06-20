#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
struct Tree{
    ll n,l; 
    vector<vector<ll>> up;
    Tree(ll n, vector<ll>&parent){
        this->n = n;
        l = 20;
        up.resize(n, vector<ll>(l+1));
        for(ll i=0; i<n; i++) up[i][0] = parent[i];
        for(ll j=l; j>=1; j--){
            for(ll i=0; i<n; i++){
                if(up[i][j-1]!=-1){
                    up[i][j] = up[up[i][j-1]][j-1];
                }
            }
        }
    }
    ll getkthboss(ll node, ll k){
        for(ll i=l; i>=0; i--){
            ll jumpsize = 1LL << i;
            if(jumpsize<=k){
                k-=jumpsize;
                node = up[node][i];
                if(node==-1) return -2;
            }
        }
        return node;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll n,q; cin >> n >> q;
    vector<ll> parent(n,-1);
    for(ll i=1; i<n; i++){
        ll x; cin >> x; x--;
        parent[i] = x;
    }
    Tree tree(n,parent);
    while(q--){
        ll x,k; cin >> x >> k; x--;
        ll ans = tree.getkthboss(x,k);
        cout << ans+1 << "\n";
    }
}