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
    void build(ll node, ll l, ll r, vi &arr){
        if(l==r){
            seg[node] = arr[l];
            return;
        }
        ll m = l + (r-l)/2;
        build(2*node,l,m,arr);
        build(2*node+1, m+1, r, arr);
        seg[node] = max(seg[2*node],seg[2*node+1]);
    }
    void update(ll node, ll l, ll r, ll i, ll v){
        if(l==r){
            seg[node] = v;
            return;
        }
        ll m = l + (r-l)/2;
        if(i<=m) update(2*node, l, m, i, v);
        else update(2*node+1, m+1, r, i, v);
        seg[node] = max(seg[2*node],seg[2*node+1]);
    }
    ll query(ll node, ll l, ll r, ll ql, ll qr, ll t){
        if(qr<l || ql>r) return LLONG_MIN;
        if(ql<=l && qr>=r) return seg[node];
        ll m = l + (r-l)/2;
        ll left = query(2*node, l, m, ql, qr, t);
        ll right = query(2*node+1, m+1, r, ql, qr, t);
        
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
        while(q--){
            ll type; cin >> type;
            if(type==1){
                ll i,x; cin >> i >> x;

            }else if(type==2){
                ll l,t; cin >> l >> t;

            }else{
                ll r,t; cin >> r >> t;

            }
        }
    }
}