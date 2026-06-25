#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
struct SegTree{
    ll n; vi seg, lazy;
    SegTree(ll n){
        this->n = n;
        seg.resize(4*n+1,0);
        lazy.resize(4*n+1,0);
    }
    void push(ll node, ll l, ll r){
        if(lazy[node]==0) return;
        seg[node] += lazy[node];
        if(l!=r){
            lazy[2*node] += lazy[node];
            lazy[2*node+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    void update(ll node, ll l, ll r, ll ql, ll qr, ll v){
        push(node,l,r);
        if(ql>r || qr<l) return;
        if(ql<=l && qr>=r){
            lazy[node] += v;
            push(node,l,r);
            return;
        }
        ll m = l + (r-l)/2;
        update(2*node,l,m,ql,qr,v);
        update(2*node+1,m+1,r,ql,qr,v);
        seg[node] = max(seg[2*node+1],seg[2*node]);
    }
    ll query(ll node, ll l, ll r, ll ql, ll x){
        push(node,l,r);
        if(seg[node]<x || ql>r) return -1;
        if(l==r) return l;
        ll m = l + (r-l)/2;
        ll res = query(2*node,l,m,ql,x);
        if(res==-1) res = query(2*node+1,m+1,r,ql,x);
        return res;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll n,m; cin >> n >> m;
    SegTree st(n);
    while(m--){
        ll type; cin >> type;
        if(type==1){
            ll l,r,v; cin >> l >> r >> v;
            st.update(1,0,n-1,l,r-1,v);
        }else{
            ll x,l; cin >> x >> l;
            cout << st.query(1,0,n-1,l,x) << "\n";
        }
    }
}