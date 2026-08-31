#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
ll mod = 1e9+7;
struct SegTree{
    ll n; vi seg;
    SegTree(ll n){
        this->n = n;
        seg.resize(4*n+10,0);
    }
    void update(ll node, ll l, ll r, ll i, ll v){
        if(l==r){
            seg[node] += v;
            return;
        }
        ll m = l + (r-l)/2;
        if(i<=m) update(2*node,l,m,i,v);
        else update(2*node+1,m+1,r,i,v);
        seg[node] = seg[2*node] + seg[2*node+1];
    }
    ll query(ll node, ll l, ll r, ll ql, ll qr){
        if(ql>r || qr<l) return 0LL;
        if(ql<=l && qr>=r) return seg[node];
        ll m = l + (r-l)/2;
        return query(2*node,l,m,ql,qr) + query(2*node+1,m+1,r,ql,qr);
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
        map<ll,ll> mp;
        vi l(n), r(n);
        for(ll i=0; i<n; i++){
            mp[arr[i]]++;
            l[i] = mp[arr[i]];
        }
        mp.clear();
        for(ll i=n-1; i>=0; i--){
            mp[arr[i]]++;
            r[i] = mp[arr[i]];
        }
        ll res = 0;
        SegTree st(n);
        for(ll i=n-1; i>=0; i--){
            res += st.query(1,1,n,1,l[i]-1);
            st.update(1,1,n,r[i],1);
        }
        cout << res << "\n";
    }
} 