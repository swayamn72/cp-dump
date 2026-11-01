#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
const ll mod = 1e9+7;
struct MSTree{
    ll n; vector<vi> seg, pref;
    MSTree(ll n){
        this->n = n;
        seg.resize(4*n+10);
        pref.resize(4*n+10);
    }
    void build(ll node, ll l, ll r, vi &arr){
        if(l==r){
            seg[node] = {arr[l]};
            pref[node] = {arr[l]};
            return;
        }
        ll m = l + (r-l)/2;
        build(2*node,l,m,arr);
        build(2*node+1,m+1,r,arr);
        merge(seg[2*node].begin(),seg[2*node].end(),
                seg[2*node+1].begin(),seg[2*node+1].end(),
                back_inserter(seg[node]));
        pref[node].resize(seg[node].size());
        pref[node][0] = seg[node][0];
        for(ll i=1; i<seg[node].size(); i++){
            pref[node][i] = pref[node][i-1] + seg[node][i];
        }
    }
    ll query(ll node, ll l, ll r, ll ql, ll qr, ll x){
        if(qr<l || ql>r) return 0;
        if(ql<=l && qr>=r){
            auto it = upper_bound(seg[node].begin(),seg[node].end(),x);
            if(it==seg[node].begin()) return 0;
            ll idx = it - seg[node].begin();
            return pref[node][idx-1];
        }
        ll m = l + (r-l)/2;
        return query(2*node,l,m,ql,qr,x) + query(2*node+1,m+1,r,ql,qr,x);
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
        MSTree ms(n);
        ms.build(1,0,n-1,arr);
        ll q; cin >> q;
        ll res = 0;
        while(q--){
            ll a,b,c; cin >> a >> b >> c;
            ll l = a^res, r = b^res,  x = c^res;
            l--; r--;
            res = ms.query(1, 0, n-1, l, r, x);\
            cout << res << "\n";
        }
    }
}