#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
struct DSU{
    vi parent,size;
    DSU(ll n){
        parent.resize(n);
        size.assign(n,1);
        iota(parent.begin(),parent.end(),0);
    }
    ll find(ll v){
        if(v==parent[v]) return v;
        return parent[v] = find(parent[v]);
    }
    bool unite(ll a, ll b){
        a = find(a); b = find(b);
        if(a!=b){
            if(size[a]<size[b]) swap(a,b);
            parent[b] = a;
            size[a] += size[b];
            return true;
        }
        return false;
    }
};