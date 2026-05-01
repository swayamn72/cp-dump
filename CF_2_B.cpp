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
    void build(ll node, ll l, ll r){
        if(l==r){
            seg[node] = 1; return;
        }
        ll m = l + (r-l)/2;
        build(2*node,l,m); build(2*node+1,m+1,r);
        seg[node] = seg[2*node] + seg[2*node+1];
    }
    ll query(ll node, ll l, ll r, ll v){
        if(l==r){
            seg[node] = 0;
            return l+1;
        }
        ll m = l + (r-l)/2;
        ll res;
        
        if(seg[2*node]>=v) res = query(2*node,l,m,v);
        else res = query(2*node+1,m+1,r,v-seg[2*node]);
        seg[node] = seg[2*node] + seg[2*node+1];
        return res;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; cin >> n;
    vector<ll> arr(n); for(auto &x : arr) cin >> x;
    SegTree st(n); st.build(1,0,n-1);
    vector<ll> res(n);
    for(ll i=n-1; i>=0; i--){
        ll val = (i+1)-arr[i];
        res[i] = st.query(1,0,n-1,val);
    }
    for(auto a : res) cout << a << " ";
}