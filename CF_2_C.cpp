#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
struct DSU{
    ll n;
    vector<ll> parent,size,val,delta;
    DSU(ll n){
        this->n = n;
        size.resize(n,1);
        val.resize(n,0);
        delta.resize(n,0);
        parent.resize(n); for(ll i=0; i<n; i++) parent[i] = i;
    }
    ll find(ll i){
        if(parent[i]==i) return i;
        ll p = parent[i];
        ll root = find(p);
        delta[i] += delta[p];
        return parent[i] = root;
    }
    void add(ll u, ll v){
        
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,m; cin >> n >> m;

}