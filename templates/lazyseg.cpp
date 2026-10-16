#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
const ll mod = 1e9+7;
struct SegTree{
    ll n; vi seg; vi lazy;
    SegTree(ll n){
        this->n = n;
        seg.resize(4*n+1,0);
        lazy.resize(4*n+1,0);
    }
    void push(ll node, ll l, ll r){
        if(lazy[node]!=0){
            seg[node] += lazy[node];
            if(l!=r){
                lazy[2*node] += lazy[node];
                lazy[2*node+1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }
    void build(ll node, ll l, ll r, vi &arr){
        if(l==r){
            seg[node] = arr[l];
            return;
        }
        ll m = l + (r-l)/2;
        build(2*node,l,m,arr);
        build(2*node+1,m+1,r,arr);
        seg[node] = min(seg[2*node],seg[2*node+1]);
    }
    void update(ll node, ll l, ll r, ll ql, ll qr, ll val){
        push(node,l,r);
        if(ql>r || qr<l) return;
        if(ql<=l && qr>=r){
            lazy[node] += val;
            push(node,l,r);
            return;
        }
        ll m = l + (r-l)/2;
        update(2*node, l, m, ql, qr, val);
        update(2*node+1, m+1, r, ql, qr, val);
        seg[node] = min(seg[2*node],seg[2*node+1]);
    }
    ll query(ll node, ll l, ll r, ll ql, ll qr){
        push(node,l,r);
        if(ql>r || qr<l) return LLONG_MAX;
        if(ql<=l && qr>=r) return seg[node];
        ll m = l + (r-l)/2;
        return min(query(2*node, l, m, ql, qr),query(2*node+1, m+1, r, ql, qr));
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1; 
    // cin >> t;
    while(t--){
        ll n,q; cin >> n >> q;
        vi arr(n); for(auto &x : arr) cin >> x;
        SegTree st(n);
        st.build(1,0,n-1,arr);
        while(q--){
            ll type; cin >> type;
            if(type==1){
                ll l,r,x; cin >> l >> r >> x;
                l--; r--;
                st.update(1, 0, n-1, l, r, x);
            }else{
                ll l,r; cin >> l >> r;
                l--; r--;
                cout << st.query(1,0,n-1,l,r) << "\n";
            }
        }
    }
}