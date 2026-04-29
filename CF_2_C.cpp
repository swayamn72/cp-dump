#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
struct SegTree{
    ll n; vector<pair<ll,ll>> seg;
    SegTree(ll n){
        this->n = n;
        seg.resize(4*n);
    }
    pair<ll,ll> merge(pair<ll,ll>&a, pair<ll,ll>&b){
        pair<ll,ll> p;
        p.first = max(a.first, b.first);
        p.second = a.second;
        return p;
    }
    void build(ll node, ll l, ll r, vector<ll>&arr){
        if(l==r){
            seg[node] = {arr[l],l};
            return;
        }
        ll m = l + (r-l)/2;
        build(2*node,l,m,arr);
        build(2*node+1,m+1,r,arr);
        seg[node] = merge(seg[2*node],seg[2*node+1]);
    }
    void update(ll node, ll l, ll r, ll i, ll v){
        if(l==r){
            seg[node] = {v,i};
            return;
        }
        ll m = l + (r-l)/2;
        if(i<=m) update(2*node,l,m,i,v);
        else update(2*node+1,m+1,r,i,v);
        seg[node] = merge(seg[2*node],seg[2*node+1]);
    }
    ll query(ll node, ll l, ll r, ll val, ll k){
        if(val>seg[node] || r<k) return -1;
        if(l==r) return seg[node].second;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        
    }
}