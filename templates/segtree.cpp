#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
const ll mod = 1e9+7;

struct SegTree{
    ll n; vi seg;
    SegTree(ll n){
        this->n = n;
        seg.resize(4*n+1);
    }
    // type merge(){
    //     // logic
    // }
    void build(ll node, ll l, ll r, vi &arr){
        if(l==r){
            seg[node] = arr[l];
            return;
        }
        ll m = l + (r-l)/2;
        build(2*node,l,m,arr);
        build(2*node+1,m+1,r,arr);
        seg[node] = merge(seg[2*node],seg[2*node+1]);
    }
    type query(ll node, ll l, ll r, ll ql, ll qr){
        if(ql>r || qr<l){
            // return identity
        }
        if(ql<=l && qr>=r){
            return seg[node];
        }
        ll m = l + (r-l)/2;
        return merge(query(2*node,l,m,ql,qr),query(2*node+1,m+1,r,ql,qr));
    }
    void update(ll node, ll l, ll r, ll i, ll v){
        if(l==r){
            seg[node] = v;
            return;
        }
        ll m = l + (r-l)/2;
        if(i<=m) update(2*node,l,m,i,v);
        else update(2*node+1,m+1,r,i,v);
        seg[node] = merge(seg[2*node],seg[2*node+1]);
    }
};
