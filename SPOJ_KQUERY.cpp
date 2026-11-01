#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
const ll mod = 1e9+7;
struct MSTree{
    ll n; vector<vi> seg;
    MSTree(ll n){
        this->n = n;
        seg.resize(4*n+10);
    }
    void build(ll node, ll l, ll r, vi &arr){
        if(l==r){
            seg[node] = {arr[l]};
            return;
        }
        ll m = l + (r-l)/2;
        build(2*node,l,m,arr);
        build(2*node+1,m+1,r,arr);
        merge(seg[2*node].begin(),seg[2*node].end(),
            seg[2*node+1].begin(),seg[2*node+1].end(),
            back_inserter(seg[node]));
    }
    ll query(ll node, ll l, ll r, ll ql, ll qr, ll x){
        if(ql>r || qr<l) return 0;
        if(ql<=l && qr>=r){
            auto it = upper_bound(seg[node].begin(),seg[node].end(),x);
            return seg[node].end() - it;
        }
        ll m = l + (r-l)/2;
        return query(2*node, l, m, ql, qr, x)+
            query(2*node+1, m+1, r, ql, qr, x);
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1; 
    // cin >> t;
    while(t--){
        ll n; cin >> n;
        vi arr(n); for(auto &x : arr) cin >> x;
        ll q; cin >> q;
        MSTree s(n);
        s.build(1, 0, n-1, arr);
        while(q--){
            ll l,r,x; cin >> l >> r >> x;
            l--; r--;
            ll ans = s.query(1, 0, n-1, l, r, x);
            cout << (ans==LLONG_MAX ? -1 : ans) << "\n";
        }
    }
}