#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
struct SegTree{
    ll n; vi seg;
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
    ll maxn(ll node, ll l, ll r, ll ql, ll qr){
        if(ql>r || qr<l) return -1;
        if(ql<=l && qr>=r) return seg[node];
        ll m = l + (r-l)/2;
        return max(maxn(2*node,l,m,ql,qr), maxn(2*node+1,m+1,r,ql,qr));
    }
    ll query(ll node, ll l, ll r, ll ql, ll x){
        if(r<ql) return -1;
        if(seg[node]<x) return -1;
        if(l==r) return l;
        ll m = l + (r-l)/2;
        ll res = query(2*node,l,m,ql,x);
        if(res!=-1) return res;
        return query(2*node+1,m+1,r,ql,x);
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll n,m; cin >> n >> m;
    vi arr(n); for(auto &x : arr) cin >> x;
    SegTree st(n);
    st.build(1,0,n-1,arr);
    while(m--){
        ll type; cin >> type;
        if(type==1){
            ll i,v; cin >> i >> v;
            st.update(1,0,n-1,i,v);
        }else{
            ll x,l; cin >> x >> l;
            if(st.maxn(1,0,n-1,l,n-1)<x){
                cout << -1 << "\n";
            }else{
                cout << st.query(1,0,n-1,l,x) << "\n";
            }
        }
    }
}