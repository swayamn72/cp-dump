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
        seg[node] = seg[2*node] + seg[2*node+1];
    }
    void update(ll node, ll l, ll r, ll i){
        if(l==r){
            seg[node] = 1 - seg[node];
            return;
        }
        ll m = l + (r-l)/2;
        if(i<=m) update(2*node,l,m,i);
        else update(2*node+1,m+1,r,i);
        seg[node] = seg[2*node] + seg[2*node+1];
    }
    ll query(ll node, ll l, ll r, ll k){
        if(l==r){
            return l;
        }
        ll m = l + (r-l)/2;
        ll leftsum = seg[2*node];
        ll rightsum = seg[2*node+1];
        if(leftsum>k){
            return query(2*node,l,m,k);
        }else{
            return query(2*node+1,m+1,r,k-leftsum);
        }
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
            ll i; cin >> i;
            st.update(1,0,n-1,i);
        }else{
            ll k; cin >> k;
            cout << st.query(1,0,n-1,k) << "\n";
        }
    }
}