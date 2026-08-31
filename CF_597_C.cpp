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
        seg.resize(4*n+1);
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
        ll n,k; cin >> n >> k;
        vi arr(n); for(auto &x : arr) cin >> x;
        ll len = k+1;
        vector<SegTree> dp(len+1,SegTree(n));

        for(auto a : arr){
            for(ll i=len; i>=2; i--){
                ll ways = dp[i-1].query(1,1,n,1,a-1);
                if(ways) dp[i].update(1,1,n,a,ways);
            }
            dp[1].update(1,1,n,a,1);
        }
        ll res = dp[len].query(1,1,n,1,n);
        cout << res;
    }
} 