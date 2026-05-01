#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
struct SegTree{
    ll n; vector<ll> seg;
    SegTree(ll n){
        this->n = n;
        seg.resize(4*n+10,0);
    }
    void update(ll node, ll l, ll r, ll i){
        if(l==r){
            seg[node] = 1;
            return;
        }
        ll m = l + (r-l)/2;
        if(i<=m) update(2*node,l,m,i);
        else update(2*node+1,m+1,r,i);
        seg[node] = seg[2*node] + seg[2*node+1];
    }
    void update2(ll node, ll l, ll r, ll i){
        if(l==r){
            seg[node] = 0;
            return;
        }
        ll m = l + (r-l)/2;
        if(i<=m) update(2*node,l,m,i);
        else update(2*node+1,m+1,r,i);
        seg[node] = seg[2*node] + seg[2*node+1];
    }
    ll query(ll node, ll l, ll r, ll ql, ll qr){
        if(qr<l || ql>r) return 0;
        if(ql<=l && qr>=r) return seg[node];
        ll m = l + (r-l)/2;
        return query(2*node,l,m,ql,qr) + query(2*node+1,m+1,r,ql,qr);
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; cin >> n;
    vector<ll> arr(2*n); for(auto &x : arr) cin >> x;
    vector<ll> res(n,0);
    map<ll,ll> mp1; 
    SegTree st1(2*n);
    for(ll i=0; i<2*n; i++){
        ll a = arr[i];
        if(mp1.find(a)==mp1.end()){
            mp1[a]=i;
            st1.update(1,0,2*n-1,i);
        }else{
            res[a-1] += st1.query(1,0,2*n-1,mp1[a],i);
            st1
        }
    }

    map<ll,ll> mp2; SegTree st2(2*n);
    for(ll i=2*n-1; i>=0; i--){
        ll a = arr[i];
        if(mp2.find(a)==mp2.end()){
            mp2[a] = i;
            st2.update(1,0,2*n-1,)
        }
    }
    for(auto a : res) cout << a << " ";
}