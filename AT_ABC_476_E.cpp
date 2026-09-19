#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
const ll mod = 1e9+7;
struct SegTree{
    ll n; vi segmax, segmin;
    SegTree(ll n){
        this->n = n;
        segmax.resize(4*n+1);
        segmin.resize(4*n+1);
    }
    void build(ll node, ll l, ll r, vi &arr){
        if(l==r){
            segmax[node] = arr[l];
            segmin[node] = arr[l];
            return;
        }
        ll m = l + (r-l)/2;
        build(2*node, l, m, arr);
        build(2*node+1, m+1, r, arr);
        segmax[node] = max(segmax[2*node],segmax[2*node+1]);
        segmin[node] = min(segmin[2*node],segmin[2*node+1]);
    }
    ll maxquery(ll node, ll l, ll r, ll ql, ll qr){
        if(qr<l || ql>r) return LLONG_MIN;
        if(ql<=l && qr>=r) return segmax[node];
        ll m = l + (r-l)/2;
        return max(maxquery(2*node, l, m, ql, qr),maxquery(2*node+1, m+1, r, ql, qr));
    }
    ll minquery(ll node, ll l, ll r, ll ql, ll qr){
        if(qr<l || ql>r) return LLONG_MAX;
        if(ql<=l && qr>=r) return segmin[node];
        ll m = l + (r-l)/2;
        return min(minquery(2*node, l, m, ql, qr),minquery(2*node+1, m+1, r, ql, qr));
    }
    void update(ll node, ll l, ll r, ll i, ll v){
        if(l==r){
            segmax[node] = v;
            segmin[node] = v;
            return;
        }
        ll m = l + (r-l)/2;
        if(i<=m) update(2*node, l, m, i, v);
        else update(2*node+1, m+1, r, i, v);
        segmax[node] = max(segmax[2*node],segmax[2*node+1]);
        segmin[node] = min(segmin[2*node],segmin[2*node+1]);
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1; 
    // cin >> t;
    while(t--){
        ll n,m; cin >> n >> m;
        vi arr(n); for(auto &x : arr){
            cin >> x; x--;
        } 
        vi pos(n);
        for(ll i=0; i<n; i++){
            pos[arr[i]] = i;
        }
        SegTree st(n); 
        st.build(1, 0, n-1, arr);

        while(m--){
            ll l,r; cin >> l >> r;
            l--; r--;
            ll maxv = st.maxquery(1, 0, n-1, l, r);
            ll minv = st.minquery(1, 0, n-1, l, r);
            ll maxi = pos[maxv], mini = pos[minv];\
            st.update(1, 0, n-1, maxi, minv);
            st.update(1, 0, n-1, mini, maxv);
            swap(arr[maxi],arr[mini]);
            swap(pos[maxv],pos[minv]);
        }
        for(auto a : arr) cout << a+1 << " ";
    }
}