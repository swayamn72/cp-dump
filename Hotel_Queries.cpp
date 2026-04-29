#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
struct SegTree{
    ll n; vector<ll> seg;
    SegTree(ll n){
        this->n = n;
        seg.resize(4*n);
    }
    void build(ll node, ll l, ll r, vector<ll>&arr){
        if(l==r){
            seg[node] = arr[l];
            return;
        }
        ll m = l + (r-l)/2;
        build(2*node,l,m,arr);
        build(2*node+1,m+1,r,arr);
        seg[node] = max(seg[2*node],seg[2*node+1]);
    }
    void update(ll node, ll l, ll r, ll i, ll v){
        if(l==r){
            seg[node] = v;
            return;
        }
        ll m = l + (r-l)/2;
        if(i<=m) update(2*node,l,m,i,v);
        else update(2*node+1,m+1,r,i,v);
        seg[node] = max(seg[2*node],seg[2*node+1]);
    }
    ll query(ll node, ll l, ll r, ll x){
        if(seg[1]<x) return -1;
        if(l==r) return l;
        ll m = l + (r-l)/2;
        if(seg[2*node]>=x) return query(2*node,l,m,x);
        else return query(2*node+1,m+1,r,x);
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,m; cin >> n >> m;
    vector<ll> arr(n); for(auto &x : arr) cin >> x;
    SegTree st(n); st.build(1,0,n-1,arr);
    while(m--){
        ll x; cin >> x;
        ll index = st.query(1,0,n-1,x);
        cout << index+1 << " ";
        if(index==-1) continue;
        arr[index] -= x;
        st.update(1,0,n-1,index,arr[index]);
    }
}