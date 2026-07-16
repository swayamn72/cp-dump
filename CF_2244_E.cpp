#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
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
        build(2*node+1,m+1,r,arr);
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
    ll t; cin >> t;
    while(t--){
        ll n,q; cin >> n >> q;
        string s; cin >> s;
        vi arr(n,0); 
        for(ll i=1; i<n; i++){
            if(s[i]==s[i-1]) arr[i] = 1;
        }
        SegTree st(n);
        st.build(1,0,n-1,arr);
        while(q--){
            ll l,r,k; cin >> l >> r >> k;
            l--; r--;
            if(l==r){
                cout << "YES" << "\n";
                continue;
            }
            ll sum = st.query(1,0,n-1,l+1,r);
            // cout << sum << " " << k << " " << "\n";
            k*=2;
            if(sum<=k){
                cout << "YES" << "\n";
            }else{
                cout << "NO" << "\n";
            }
        }        
    }
}